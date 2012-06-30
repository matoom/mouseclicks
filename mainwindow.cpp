#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {        
    ui->setupUi(this);

    layout()->setSizeConstraint(QLayout::SetFixedSize);

    controlThread = new ControlThread();

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startApplication()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopApplication()));
    connect(this, SIGNAL(stop()), controlThread, SLOT(stop()));

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    trayIcon->setIcon(QIcon(":/icons/images/bag.png"));

    trayIcon->show();
}

void MainWindow::startApplication() {
    ui->startButton->setDisabled(1);

    if(!controlThread->isRunning()) {
        controlThread->start();
    }

    ui->stopButton->setDisabled(0);
}

void MainWindow::stopApplication() {
    emit stop();
    ui->startButton->setDisabled(0);
    ui->stopButton->setDisabled(1);
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        showNormal();
        break;
    case QSystemTrayIcon::MiddleClick:
        break;
    default:
        ;
    }
}

void MainWindow::quit(){
    emit stop();
    controlThread->wait();
}

MainWindow::~MainWindow() {
    delete ui;
    delete controlThread;
    delete trayIconMenu;
    delete trayIcon;
}
