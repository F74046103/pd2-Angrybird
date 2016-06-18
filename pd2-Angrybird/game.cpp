#include "game.h"
#include <iostream>
#include <QFont>

using namespace std;

game::game()
{
    i=0;
    score=0;
    scene=new QGraphicsScene;
    scene->setSceneRect(0,0,1280,800);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,800);


    bg=new QGraphicsPixmapItem;
    bg->setPixmap(QPixmap(":/image/background"));
    bg->setPos(0,0);
    scene->addItem(bg);


    exit=new QGraphicsPixmapItem;
    exit->setPixmap(QPixmap(":/image/exit.png"));
    exit->setPos(50,20);
    scene->addItem(exit);


    shooter=new QGraphicsPixmapItem;
    shooter->setPixmap(QPixmap(":/image/shooter"));
    shooter->setScale(0.5);
    shooter->setPos(100,570);
    scene->addItem(shooter);

    s=new QGraphicsTextItem;
    s->setPlainText(QString("score:")+QString::number(score));
    s->setDefaultTextColor(Qt::blue);
    s->setFont(QFont("times",16));
    s->setPos(50,120);
    scene->addItem(s);

    w[0]=new QGraphicsPixmapItem;
    w[0]->setPixmap(QPixmap(":/image/thinwood1.png"));
    w[0]->setPos(600,470);
    scene->addItem(w[0]);
    w[1]=new QGraphicsPixmapItem;
    w[1]->setPixmap(QPixmap(":/image/thinwood1.png"));
    w[1]->setPos(800,470);
    scene->addItem(w[1]);
    w[2]=new QGraphicsPixmapItem;
    w[2]->setPixmap(QPixmap(":/image/thinwood1.png"));
    w[2]->setPos(1000,470);
    scene->addItem(w[2]);


    bird6=new red;
    bird6->setPixmap(QPixmap(":/image/blue.png"));
    scene->addItem(bird6);
    bird6->setPos(-700,-700);

    bird5=new red;
    bird5->setPixmap(QPixmap(":/image/blue.png"));
    scene->addItem(bird5);
    bird5->setPos(-700,-700);


    bird4=new red;
    bird4->setPixmap(QPixmap(":/image/blue.png"));
    bird4->setPos(-700,-700);
    scene->addItem(bird4);

    bird3=new red;
    bird3->setPixmap(QPixmap(":/image/green.png"));
    bird3->setScale(0.6);
    bird3->setPos(-700,-700);
    scene->addItem(bird3);

    bird2=new red;
    bird2->setPixmap(QPixmap(":/image/yellow.png"));
    bird2->setScale(0.8);
    bird2->setPos(-700,-700);
    scene->addItem(bird2);

    bird1=new red;
    bird1->setPos(100,550);
    scene->addItem(bird1);


    p[0]=new QGraphicsPixmapItem;
    p[0]->setPixmap(QPixmap(":/image/pig.png"));
    p[0]->setPos(675,620);
    p[0]->setScale(0.5);
    scene->addItem(p[0]);
    p[1]=new QGraphicsPixmapItem;
    p[1]->setPixmap(QPixmap(":/image/pig.png"));
    p[1]->setPos(875,620);
    p[1]->setScale(0.5);
    scene->addItem(p[1]);
    p[2]=new QGraphicsPixmapItem;
    p[2]->setPixmap(QPixmap(":/image/pig.png"));
    p[2]->setPos(1075,620);
    p[2]->setScale(0.5);
    scene->addItem(p[2]);

    connect(this,SIGNAL(quitGame()),this,SLOT(quitGameSlots()));

}

void game::mousePressEvent(QMouseEvent *event)
{
        if(event->x()>50&&event->x()<150&&event->y()>20&&event->y()<120){
            emit quitGame();
            close();
        }
        else{
           xp=event->x();
           yp=event->y();
        }
}

void game::mouseMoveEvent(QMouseEvent *event)
{
    float a,b;

    a=event->x()-xp;
    b=event->y()-yp;
    if (event->x()-xp>75)
       a=75;
    if (event->y()-yp>75)
       b=75;
    if (event->x()-xp<-75)
       a=-75;
    if (event->y()-yp<-75)
       b=-75;

    if(i==3){
        bird4->setPos(100+a,550+b);
    }
    if(i==2){
        bird3->setPos(100+a,550+b);
    }
    if(i==1){
        bird2->setPos(100+a,550+b);
    }
    if(i==0){
        bird1->setPos(100+a,550+b);
    }
}

void game::mouseReleaseEvent(QMouseEvent *event)
{
    float a,b;
    xr=event->x();
    yr=event->y();
    a=(xp-xr)/75;
    b=(yr-yp)/75;
    if ((xp-xr)>75)
       a=1;
    if ((yr-yp)>75)
       b=1;
    if(event->x()>50&&event->x()<150&&event->y()>20&&event->y()<120){
    }
    else{
    if(i==3){
        bird4->setv(a,b);
        i++;
    }
    if(i==2){
        bird3->setv(a,b);
        bird4->setPos(100,550);
        i++;
    }
    if(i==1){
        bird2->setv(a,b);
        bird3->setPos(100,550);
        i++;
    }
    if(i==0){
        bird1->setv(a,b);
        bird2->setPos(100,550);
        i++;
    }}
}

void game::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Space){
        if(i==2&&bird2->vx>0){
            bird2->vx=bird2->vx+1;
        }
        if(i==3&&bird3->vx>0){
            bird3->vx=bird3->vx*-1;
        }
        if(i==4&&bird4->vx>0){

            bird5->setPos(bird4->x(),bird4->y());
            bird5->setv(bird4->vx-0.2,bird4->vy);
            bird6->setPos(bird4->x(),bird4->y());
            bird6->setv(bird4->vx+0.2,bird4->vy);
        }
    }
}

void game::quitGameSlots()
{
    cout<<"Quit Game signal received"<<endl;
}

