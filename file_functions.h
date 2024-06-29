#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

#include <vector>
#include <filesystem>
#include <string>
#include <stdlib.h>


using namespace std;


// Create a new .config directory for wg files
void createFiles(){
    system("cd $HOME/.config && mkdir wg-tray"); // make directory
    system("cd $HOME/.config/wg-tray %% mkdir wireguard-configs"); // make directory for wireguard configs
}



int configCount(){
    int count;
    string path = "$HOME/.config/wg-tray/wireguard-configs"; // change
    for (const auto & entry : std::filesystem::directory_iterator(path)){ // goes through wireguard configs and counts them
        count+=1;
    }
    return count;
}

vector<string> getConfigNames(){
    vector<string> names;
    string path = "$HOME/.config/wg-tray/wireguard-configs"; // change
    for (const auto & entry : std::filesystem::directory_iterator(path)){ // goes through wireguard configs and counts them
        names.push_back(entry.path());
    }
    return names;
}


#endif // FILE_FUNCTIONS_H
