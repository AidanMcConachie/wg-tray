#ifndef WIREGUARD_FUNCTIONS_H
#define WIREGUARD_FUNCTIONS_H

#include <stdlib.h>
#include <QProcess>
#include <QString>
#include <string.h>
#include <iostream>



void startwg(QString configName, QString lastConfigName=""){
    QProcess* terminal = new QProcess();
    if (lastConfigName==""){ // might be able to use nullptr here?
        QStringList command = {"sudo", "wg-quick", "down", lastConfigName, "&&", "sudo", "wg-quick", "up", configName, "&&", "exit"}; // stop and start
        terminal->start("foot", command);
    } else {
        QStringList command = {"sudo", "wg-quick", "up", configName, "&&", "exit"}; // just start
        terminal->start("foot", command);
    }
}

void stopwg(QString configName){
    QProcess* terminal = new QProcess();
    QStringList command = {"sudo", "wg-quick", "down", configName, "&&", "quit"};
    terminal->start("foot", command);
}



#endif // WIREGUARD_FUNCTIONS_H
