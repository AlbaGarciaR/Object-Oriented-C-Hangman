#include "rectangle.h"
#include "forme.h"
#include <QPainter>



Rectangle::Rectangle(int x,int y, int l, int h):Forme(x,y)
{
    largeur=l;
    hauteur=h;
}
int Rectangle::getl()
{
    return largeur;
}
int Rectangle::geth()
{
    return hauteur;
}

void Rectangle::afficher(QWidget* fenetre)
{
    int a,b,c,d;
    a=getx();
    b=gety();
    c=getl();
    d=geth();
    QPainter painter(fenetre);
    painter.setBrush(Qt::blue);
    painter.drawRect(a,b,c,d);
}
