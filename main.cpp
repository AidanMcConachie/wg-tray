#include "mainwindow.h"
#include "file_functions.h"

#include <QApplication>
#include <QRadioButton>
#include <QString>
#include <QObject>
// needed for running privileged commands....


#include <iostream>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    wireguard_tray window;
    vector<string> names = getConfigNames();
    QRadioButton* config1 = window.findChild<QRadioButton*>("config1Button");
    config1->setText(fetchConfigName(0));
    QRadioButton* config2 = window.findChild<QRadioButton*>("config2Button");
    config2->setText(fetchConfigName(1));
    QRadioButton* config3 = window.findChild<QRadioButton*>("config3Button");
    config3->setText(fetchConfigName(3));
    QRadioButton* config4 = window.findChild<QRadioButton*>("config4Button");
    config4->setText(fetchConfigName(4));
    createFiles(); // create required .config directories
    window.show();
    return app.exec();
}
