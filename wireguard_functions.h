#ifndef WIREGUARD_FUNCTIONS_H
#define WIREGUARD_FUNCTIONS_H

#include <stdlib.h>
#include <QProcess>
#include <QString>
#include <string.h>
#include <iostream>


// future versions *should* use polkit or a variation of it, but terminal cmds will work also.


void startwg(QString configName, QString lastConfigName=""){
    QProcess* terminal = new QProcess();
    if (!(lastConfigName=="")){ // might be able to use nullptr here?
        QStringList command = {"sudo", "wg-quick", "down", lastConfigName, "&&", "sudo", "wg-quick", "up", configName}; // stop and start
        terminal->start("foot", command);
    } else {
        QStringList command = {"sudo", "wg-quick", "up", configName}; // just start
        terminal->start("foot", command);
    }
}

void stopwg(QString configName){
    QProcess* terminal = new QProcess();
    QStringList command = {"sudo", "wg-quick", "down", configName};
    terminal->start("foot", command);
}



#endif // WIREGUARD_FUNCTIONS_H
