#ifndef CONTROLTHREAD_H
#define CONTROLTHREAD_H

#include <QThread>
#include <windows.h>
#include <QDebug>
#include <click.h>
#include <clickthread.h>
#include <recordThread.h>

typedef QList<const Click*> Clicks;
Q_DECLARE_METATYPE(Clicks);

class ClickThread;
class RecordThread;

class ControlThread : public QThread {
    Q_OBJECT

public:
    ControlThread();
    ~ControlThread();

    virtual void run();

private:
    ClickThread* clickThread;
    RecordThread* recordThread;
    QList<const Click*> clicks;

    bool state;

private slots:
    void stop();
    void updateSettings(Clicks);

signals:
    void stopRecord(void);

};

#endif // CONTROLTHREAD_H
