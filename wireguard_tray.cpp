#include "wireguard_tray.h"
#include "./ui_wireguard_tray.h"

wireguard_tray::wireguard_tray(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wireguard_tray)
{
    ui->setupUi(this);
}

wireguard_tray::~wireguard_tray()
{
    delete ui;
}
