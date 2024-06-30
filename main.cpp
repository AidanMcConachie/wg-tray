#include "wireguard_tray.h"
#include "file_functions.h"

#include <QApplication>
#include <QRadioButton>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QString>
// needed for running privileged commands....


#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    wireguard_tray window;
    QSystemTrayIcon tray;
    QIcon trayIcon;
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
    std::filesystem::path filesystemPath = std::filesystem::current_path().parent_path().parent_path() / "assets" / "icon"; // do double parent paths to get back to wg-tray/...
    QString path = QString::fromStdString(filesystemPath.string());
    trayIcon.addFile(path);
    tray.setIcon(trayIcon);
    tray.show();
    tray.showMessage("Wireguard Tray", "Right click to change");
    window.show();
    return app.exec();
}
