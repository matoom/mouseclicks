#include "controlthread.h"

ControlThread::ControlThread() {
    this->state = true;

    recordThread = new RecordThread();
    connect(this, SIGNAL(stopRecord()), recordThread, SLOT(stopRecord()));

    typedef QList<const Click*> Clicks;
    qRegisterMetaType<Clicks>("Clicks");
    connect(recordThread, SIGNAL(updateSettings(Clicks)), this, SLOT(updateSettings(Clicks)));
}

void ControlThread::run() {
    while(state){
        if(GetAsyncKeyState(VK_LCONTROL) & GetAsyncKeyState(VK_SPACE) & 0x8000) {
            clickThread = new ClickThread(clicks);
            clickThread->start();
            clickThread->wait();
            delete clickThread;
        }

        if(GetAsyncKeyState(VK_F5) & 0x8000) {
            recordThread->start();
        }

        if(GetAsyncKeyState(VK_F6) & 0x8000) {
            if(recordThread->isRunning()) {
                emit stopRecord();
            }
        }
        Sleep(80);
    }

    this->state = true;
}

void ControlThread::stop() {
    emit stopRecord();
    this->state = false;
}

void ControlThread::updateSettings(QList<const Click*> clicks) {
    this->clicks = clicks;
}

 ControlThread::~ControlThread() {
     delete recordThread;
}
