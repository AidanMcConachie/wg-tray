#ifndef WIREGUARD_TRAY_H
#define WIREGUARD_TRAY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class wireguard_tray;
}
QT_END_NAMESPACE

class wireguard_tray : public QMainWindow
{
    Q_OBJECT

public:
    wireguard_tray(QWidget *parent = nullptr);
    ~wireguard_tray();

private:
    Ui::wireguard_tray *ui;
};

#endif // WIREGUARD_TRAY_H
