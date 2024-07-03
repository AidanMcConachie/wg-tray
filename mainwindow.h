#ifndef WIREGUARD_TRAY_H
#define WIREGUARD_TRAY_H

#include <QMainWindow>
#include <QSystemTrayIcon>



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

    void onTrayClick(){ // slot for opening/closing tray
        if (wireguard_tray::isVisible()){
            wireguard_tray::hide();
        } else {
            wireguard_tray::show();
        }
    }
private slots:
    void on_configButton_pressed(int index); // make buttons functional, go to source file
    void onTrayExit(); // on tray exit (right click)

private:
    Ui::wireguard_tray *ui;
    QSystemTrayIcon *tray;

};


#endif // WIREGUARD_TRAY_H
