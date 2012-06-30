#ifndef CLICK_H
#define CLICK_H

#include <QObject>

class Click : public QObject {
    Q_OBJECT

public:
    explicit Click(int, int, bool, QObject *parent = 0);

    void setX(int);
    int getX();

    void setY(int);
    int getY();

    void setAlt(bool);
    bool getAlt();

private:       
    int x;
    int y;
    bool alt;
};

#endif // CLICK_H
