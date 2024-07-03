#ifndef WIREGUARD_FUNCTIONS_H
#define WIREGUARD_FUNCTIONS_H

#include <QProcess>
#include <QString>

// future versions *should* use polkit or a variation of it, but terminal commands will work also.


void startwg(QString configName, QString lastConfigName=""){
    QProcess* terminal = new QProcess();
    if (!(lastConfigName=="")){
        QStringList downCommand = {"sudo", "wg-quick", "down", lastConfigName};
        QStringList upCommand = {"sudo", "wg-quick", "up", configName};
        terminal->start("foot", downCommand);
        terminal->waitForFinished();
        terminal->start("foot", upCommand); // have to put password twice, not optimal
        terminal->waitForFinished();
    } else {
        QStringList command = {"sudo", "wg-quick", "up", configName}; // just start
        terminal->start("foot", command);
    }
}

void stopwg(QString configName){
    QProcess* terminal = new QProcess();
    QStringList command = {"sudo", "wg-quick", "down", configName};
    terminal->start("foot", command);
    terminal->waitForFinished();
}


#endif // WIREGUARD_FUNCTIONS_H
