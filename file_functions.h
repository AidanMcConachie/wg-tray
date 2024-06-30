#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

#include <vector>
#include <filesystem>
#include <string>
#include <stdlib.h>
#include <QString>
#include <QSystemTrayIcon>
#include <QIcon>


using namespace std;

string getDirectories(string directoryType){
    const string homeDirectory = getenv("HOME"); // could use string as well
    const filesystem::path wgTrayDirectory = homeDirectory + "/.config/wg-tray";
    const filesystem::path wgConfigs = homeDirectory + "/.config/wg-tray/wireguard-configs";
    if (directoryType=="homeDirectory"){
        return homeDirectory;
    } else if (directoryType=="wgTrayDirectory"){
        return wgTrayDirectory;
    } else if (directoryType=="wgConfigs"){
        return wgConfigs;
    }
    return "";
}


// Create a new .config directory for wg files
void createFiles(){
    string wgTrayDirectory = getDirectories("wgTrayDirectory");
    try{
        if (filesystem::is_directory(wgTrayDirectory)){
            throw runtime_error("Directory already exists");
        }
        else{
            // could change below to filesystem to remain consistent, will need env checks
            system("cd $HOME/.config && mkdir wg-tray"); // make directory
            system("cd $HOME/.config/wg-tray && mkdir wireguard-configs"); // make directory for wireguard configs
        }
    }
    catch (exception e){
        // don't need anything printed to console
    }
}

vector<string> getConfigNames(){
    vector<string> names;
    string path = getDirectories("wgConfigs");
    try{
        if (path.size()==0){
            throw out_of_range("Wireguard configuration folder is empty");
        }
        for (auto entry : filesystem::directory_iterator(path)){ // goes through wireguard configs and counts them
            names.push_back(entry.path().filename().string().erase(entry.path().filename().string().size() - 5)); // to remove the .conf part
        }
    }
    catch(exception error){
        // don't need to do anything
    }
    return names;
}


QString fetchConfigName(int vectorIndex){ // this function will need to be changed later to offset list functions
    vector<string> names = getConfigNames();
    int configCount = names.size();
    if (vectorIndex < configCount){
        return QString::fromStdString(names.at(vectorIndex));
    }
    return 0;
}



#endif // FILE_FUNCTIONS_H
