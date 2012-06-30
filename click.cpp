#include "click.h"

Click::Click(int x, int y, bool alt, QObject *parent) : QObject(parent) {
    this->x = x;
    this->y = y;
    this->alt = alt;
}

void Click::setX(int x) {
    this->x = x;
}

int Click::getX() {
    return this->x;
}

void Click::setY(int y) {
    this->x = y;
}

int Click::getY() {
    return this->y;
}

void Click::setAlt(bool alt) {
    this->alt = alt;
}

bool Click::getAlt() {
    return this->alt;
}
