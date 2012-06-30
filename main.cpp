#include <QtGui>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {        
        QMessageBox::critical(0, QObject::tr("Systray"),
            QObject::tr("I couldn't detect any system tray "
            "on this system."));

        return 1;
    }

    QApplication::setQuitOnLastWindowClosed(false);

    MainWindow w;
    w.show();

    QObject::connect(&a, SIGNAL(aboutToQuit()), &w, SLOT(quit()));

    return a.exec();
}
