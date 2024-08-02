#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "wireguard_functions.h"
#include "file_functions.h"

#include <QString>
#include <QIcon>
#include <QRadioButton>
#include <filesystem>



QString previousUsedConfig = ""; // has to be global so all functions & methods can access it

wireguard_tray::wireguard_tray(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wireguard_tray)
{
    ui->setupUi(this);
    tray = new QSystemTrayIcon(this);

    createFiles(); // create required .config directories (if needed)


    // Defining tray icon properties
    std::filesystem::path filesystemPath = std::filesystem::current_path().parent_path().parent_path() / "assets" / "icon"; // do double parent paths to get back to wg-tray/...
    QString path = QString::fromStdString(filesystemPath.string());
    QIcon trayIcon;
    trayIcon.addFile(path);
    tray->setIcon(trayIcon);
    tray->show();
    tray->showMessage("Wireguard Tray", "Double click to change");

    // Menu & actions after right clicking on tray, future verions of wg-tray will solely use this, for simplicity
    QMenu *menu = new QMenu;
    QAction *exit = menu->addAction("Exit");
    tray->setContextMenu(menu);

    // TODO: Lots of boilerplate code, shorten

    ui->config1Button->setText(fetchConfigName(0));
    ui->config2Button->setText(fetchConfigName(1));
    ui->config3Button->setText(fetchConfigName(2));
    ui->config4Button->setText(fetchConfigName(3));


    if (ui->config1Button->text()==""){
        ui->config1Button->setVisible(false);
    }
    if (ui->config2Button->text()==""){
        ui->config2Button->setVisible(false);
    }
    if (ui->config3Button->text()==""){
        ui->config3Button->setVisible(false);
    }
    if (ui->config4Button->text()==""){
        ui->config4Button->setVisible(false);
    }

    // std::bind is used below to add index (less code needed)
    connect(ui->config1Button, &QRadioButton::clicked, this, std::bind(&wireguard_tray::on_configButton_pressed, this, 0));
    connect(ui->config2Button, &QRadioButton::clicked, this, std::bind(&wireguard_tray::on_configButton_pressed, this, 1));
    connect(ui->config3Button, &QRadioButton::clicked, this, std::bind(&wireguard_tray::on_configButton_pressed, this, 2));
    connect(ui->config4Button, &QRadioButton::clicked, this, std::bind(&wireguard_tray::on_configButton_pressed, this, 3));
    connect(exit, &QAction::triggered, this, &wireguard_tray::onTrayExit); // stop wireguard
    connect(tray, &QSystemTrayIcon::activated, this, &wireguard_tray::onTrayClick);

}

wireguard_tray::~wireguard_tray()
{
    delete ui;
}

void wireguard_tray::onTrayExit(){
    if (!(previousUsedConfig=="")){
        stopwg(previousUsedConfig);
    }
    QCoreApplication::exit();
}


void wireguard_tray::on_configButton_pressed(int index)
{
    QString name = fetchConfigName(index);
    startwg(name, previousUsedConfig);
    previousUsedConfig = name; // set current config to previous config the next time it is ran
}


