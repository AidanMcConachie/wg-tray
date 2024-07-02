#include "mainwindow.h"


#include <QApplication>
#include <QWidget>
#include <QMenu>
#include <QAction>



int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    wireguard_tray window;
    window.show();
    return app.exec();
}
