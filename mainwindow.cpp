#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QString>
#include <QIcon>
#include <QRadioButton>
#include <filesystem>




wireguard_tray::wireguard_tray(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wireguard_tray)
{
    ui->setupUi(this);
    tray = new QSystemTrayIcon(this);


    std::filesystem::path filesystemPath = std::filesystem::current_path().parent_path().parent_path() / "assets" / "icon"; // do double parent paths to get back to wg-tray/...
    QString path = QString::fromStdString(filesystemPath.string());
    QIcon trayIcon;
    trayIcon.addFile(path);
    tray->setIcon(trayIcon);
    tray->show();
    tray->showMessage("Wireguard Tray", "Right click to change");
    connect(tray, &QSystemTrayIcon::activated, this, &wireguard_tray::onTrayClick);
}

wireguard_tray::~wireguard_tray()
{
    delete ui;
}

