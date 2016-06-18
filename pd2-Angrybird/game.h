#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include"red.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QGraphicsTextItem>

class game:public QGraphicsView

{
    Q_OBJECT
public:
    game();
    QGraphicsScene *scene;
    QGraphicsPixmapItem *bg;
    QGraphicsPixmapItem *shooter;
    QGraphicsPixmapItem *w[3];
    QGraphicsPixmapItem *p[3];
    QGraphicsPixmapItem *exit;
    QGraphicsTextItem *s;
    red *bird1;
    red *bird2;
    red *bird3;
    red *bird4;
    red *bird5;
    red *bird6;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    float xp,yp,xr,yr;
    int i,score;
signals:
    void quitGame();
public slots:
    void quitGameSlots();
};

#endif // GAME_H
