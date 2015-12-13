#include "dessin.h"
#include <vector>

Dessin::Dessin()
{
    Rectangle* r1 = new Rectangle(52,230,100,2);
        liste_formes.push_back(r1);
    Rectangle* r2 = new Rectangle(100,30,2,200);
        liste_formes.push_back(r2);
    Rectangle* r3 = new Rectangle(100,30,100,2);
        liste_formes.push_back(r3);
    Rectangle* r4 = new Rectangle(198,30,2,50);
        liste_formes.push_back(r4);
    Cercle* c1 = new Cercle(184,80,30);
        liste_formes.push_back(c1);
    Rectangle* r5 = new Rectangle(194,110,10,50);
        liste_formes.push_back(r5);
    Rectangle* r6 = new Rectangle(172,120,22,3);
        liste_formes.push_back(r6);
    Rectangle* r7 = new Rectangle(204,120,22,3);
        liste_formes.push_back(r7);
    Rectangle* r8 = new Rectangle(194,160,2,40);
        liste_formes.push_back(r8);
    Rectangle* r9 = new Rectangle(202,160,2,40);
        liste_formes.push_back(r9);
}

void Dessin::afficher(QWidget *fenetre,int nb)
{
    for (double i=0;i<nb && i<liste_formes.size();i++)
    {
        liste_formes[i]->afficher(fenetre);
    }
}

Dessin::~Dessin(){
    for(double i=0;i<liste_formes.size();i++)
    {
        delete liste_formes[i];
    }
}
