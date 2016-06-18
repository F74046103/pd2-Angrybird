#include <QApplication>
#include "game.h"
game * g;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    g=new game();
    g->show();
    return a.exec();
}
