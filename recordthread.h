#ifndef RECORDTHREAD_H
#define RECORDTHREAD_H

#include <QThread>
#include <QDebug>
#include <QMouseEvent>
#include <QList>
#include <QCursor>
#include <click.h>
#include <windows.h>

typedef QList<Click*> Clicks;

class RecordThread : public QThread {
    Q_OBJECT

public:
    explicit RecordThread();
    ~RecordThread();

    virtual void run();

private:
    bool state;
    bool alt;
    QList<Click*> clicks;
    int prevManhattan;

    QPoint point;

signals:
    void updateSettings(Clicks);

public slots:
    void stopRecord();

};

#endif // RECORDTHREAD_H
