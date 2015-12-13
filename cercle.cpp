#include "cercle.h"
#include "forme.h"
#include <QPainter>


Cercle::Cercle(int x, int y, int r):Forme(x,y)
{
    rayon=r;
}

int Cercle::getr()
{
    return rayon;
}

void Cercle::afficher(QWidget*fenetre)
{
    int a,b,c,d;
    a=getx();
    b=gety();
    c=getr();
    d=getr();
    QPainter painter(fenetre);
    painter.setBrush(Qt::blue);
    painter.drawEllipse(a,b,c,d);
}
