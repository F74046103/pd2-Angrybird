#include "red.h"
#include <QTimer>
#include "game.h"
#include<iostream>
using namespace std;
extern game *g;
red::red()
{
    setPixmap(QPixmap(":/image/red.png"));
    i=2;
    vx=0;
    vy=0;
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(2);
}

void red::setv(float a,float b)
{
    vx=a;
    vy=b;
}

void red::move()
{   if(vx!=0||vy!=0){
        vy=vy-0.001;
        if(i>7){
            vy=0;
            vx=0;
        }
        setPos(x()+vx,y()-vy);

        if(y()>630){
            setPos(x(),630);
            vy=-vy/i;
            vx=(vx/i)*1.5;
            i++;
        }
    }
    if(vx==0&&vy==0&&y()==630){
        setPos(-500,630);
    }

    for(int j=0;j<3;j++){
        if(x()<g->w[j]->x()-44&&x()>g->w[j]->x()-46&&y()>g->w[j]->y()-45&&x()<1300&&vx>0){
            vx=-vx/1.5;
            setPos(g->w[j]->x()-46,y());
            g->w[j]->setPos(-1000,g->w[j]->y());
            g->score=g->score+100;
            g->s->setPlainText(QString("score:")+QString::number(g->score));
        }
        if(x()<g->w[j]->x()+21&&x()>g->w[j]->x()+19&&y()>g->w[j]->y()-45&&x()<1300&&vx<0){
            vx=-vx/1.5;
            setPos(g->w[j]->x()+21,y());
            g->w[j]->setPos(-1000,g->w[j]->y());
            g->score=g->score+100;
            g->s->setPlainText(QString("score:")+QString::number(g->score));
        }
        if(x()<g->w[j]->x()+20&&x()>g->w[j]->x()-45&&y()>g->w[j]->y()-45&&x()<1300&&vy<0){
            vy=-vy/1.5;
            setPos(x(),g->w[j]->y()-45);
            g->w[j]->setPos(-1000,g->w[j]->y());
            g->score=g->score+100;
            g->s->setPlainText(QString("score:")+QString::number(g->score));
        }



        if(x()<g->p[j]->x()-44&&x()>g->p[j]->x()-46&&y()>g->p[j]->y()-45&&x()<1300&&vx>0){
            vx=-vx/1.5;
            setPos(g->p[j]->x()-46,y());
            g->p[j]->setPos(-1000,g->p[j]->y());
            g->score=g->score+200;
            g->s->setPlainText(QString("score:")+QString::number(g->score));
        }
        if(x()<g->p[j]->x()+21&&x()>g->p[j]->x()+19&&y()>g->p[j]->y()-45&&x()<1300&&vx<0){
            vx=-vx/1.5;
            setPos(g->p[j]->x()+21,y());
            g->p[j]->setPos(-1000,g->p[j]->y());
            g->score=g->score+200;
           g->s->setPlainText(QString("score:")+QString::number(g->score));
        }
        if(x()<g->p[j]->x()+20&&x()>g->p[j]->x()-45&&y()>g->p[j]->y()-45&&x()<1300&&vy<0){
            vy=-vy/1.5;
            setPos(x(),g->p[j]->y()-45);
            g->p[j]->setPos(-1000,g->p[j]->y());
            g->score=g->score+200;
            g->s->setPlainText(QString("score:")+QString::number(g->score));
        }
    }
}
