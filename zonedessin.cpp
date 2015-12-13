#include "zonedessin.h"
#include "rectangle.h"
#include "cercle.h"
#include<QPainter>

ZoneDessin::ZoneDessin(QWidget *parent): QWidget(parent)

{
    setPalette(QPalette(QColor(250, 250, 250))); // couleur de fond
    setAutoFillBackground(true); // remplissage automatique avec la couleur de fond
    setFixedSize(300,300); // dimension de la fenetre
    cpt=10;
}


void ZoneDessin::initCpt()
{
    cpt=0;
    update();
}
void ZoneDessin::incCpt()
{
    cpt++;
    update();
}

void ZoneDessin::paintEvent(QPaintEvent *event)
{

   d.afficher(this,cpt);
}
