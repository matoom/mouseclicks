#ifndef CLICKTHREAD_H
#define CLICKTHREAD_H

#include <QThread>
#include <windows.h>
#include <QDebug>
#include <click.h>

class ClickThread : public QThread {
    Q_OBJECT

public:
    ClickThread(QList<const Click*>);
    ~ClickThread();

    virtual void run();

private:
    QList<const Click*> clicks;

signals:
    void clicksEnd(void);

};

#endif // CLICKTHREAD_H
