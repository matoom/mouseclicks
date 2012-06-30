#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <controlthread.h>

namespace Ui {
    class MainWindow;
}

class ControlThread;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    ControlThread* controlThread;
    QSystemTrayIcon* trayIcon;

    QMenu* trayIconMenu;
    QAction* restoreAction;
    QAction* minimizeAction;
    QAction* quitAction;

private slots:
    void startApplication();
    void stopApplication();
    void quit();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

signals:
    void stop(void);

};

#endif // MAINWINDOW_H
