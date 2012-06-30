#include "recordthread.h"

RecordThread::RecordThread() {
    this->state = true;
}

void RecordThread::run() {
    alt = false;
    prevManhattan = 0;

    clicks.clear();

    while(state) {
        if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
            if(GetAsyncKeyState(VK_MENU) & 0x8000) {
                alt = true;
            } else {
                alt = false;
            }

            point = QCursor::pos();
            if(prevManhattan != point.manhattanLength()) {
                clicks.append(new Click(point.x(), point.y(), alt));
                Sleep(50);
            }
            prevManhattan = point.manhattanLength();
        }
        Sleep(50);
    }

    emit updateSettings(clicks);
    this->state = true;
}

void RecordThread::stopRecord() {
    this->state = false;
}

RecordThread::~RecordThread() {
}
