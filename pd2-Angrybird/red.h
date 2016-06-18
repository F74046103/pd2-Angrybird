#ifndef RED_H
#define RED_H
#include <QGraphicsPixmapItem>

class red:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    red();
    int i;
    float vx,vy;
    void setv(float a,float b);
public slots:
    void move();
};

#endif // RED_H
