#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "wireguard_functions.h"
#include "file_functions.h"


#include <QString>
#include <QIcon>
#include <QRadioButton>
#include <filesystem>

#include <iostream>




wireguard_tray::wireguard_tray(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wireguard_tray)
{
    ui->setupUi(this);
    tray = new QSystemTrayIcon(this);

    createFiles(); // create required .config directories (if needed)

    std::filesystem::path filesystemPath = std::filesystem::current_path().parent_path().parent_path() / "assets" / "icon"; // do double parent paths to get back to wg-tray/...
    QString path = QString::fromStdString(filesystemPath.string());
    QIcon trayIcon;
    trayIcon.addFile(path);
    tray->setIcon(trayIcon);
    tray->show();
    tray->showMessage("Wireguard Tray", "Right click to change");
    connect(tray, &QSystemTrayIcon::activated, this, &wireguard_tray::onTrayClick);

    // set button names
    ui->config1Button->setText(fetchConfigName(0));
    ui->config2Button->setText(fetchConfigName(1));
    ui->config3Button->setText(fetchConfigName(2));
    ui->config4Button->setText(fetchConfigName(3));


    connect(ui->config1Button, &QRadioButton::clicked, this, &wireguard_tray::on_config1Button_pressed);
}

wireguard_tray::~wireguard_tray()
{
    delete ui;
}


// void wireguard_tray::on_config1Button_clicked()
// {
//     QString name = fetchConfigName(0);
//     startwg(name);
// }




void wireguard_tray::on_config1Button_pressed()
{
    QString name = fetchConfigName(0);
    startwg(name);
}

