#include "wireguard_tray.h"
#include "file_functions.h"

#include <QApplication>
#include <QRadioButton>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wireguard_tray window;
    QRadioButton* config1 = window.findChild<QRadioButton*>("config1Button");
    QRadioButton* config2 = window.findChild<QRadioButton*>("config2Button");
    QRadioButton* config3 = window.findChild<QRadioButton*>("config3Button");
    QRadioButton* config4 = window.findChild<QRadioButton*>("config4Button");
    vector<string> names = getConfigNames();
    int numberOfConfigs = configCount();
    createFiles();
    window.show();
    return a.exec();
}
