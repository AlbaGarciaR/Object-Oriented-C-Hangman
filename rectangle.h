#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "forme.h"
#include <QPainter>
#include <QWidget>

class Rectangle : public Forme

{
    int largeur;
    int hauteur;

public:
    Rectangle(int, int, int , int);
    virtual void afficher(QWidget*);
    int getl();
    int geth();
};


#endif // RECTANGLE_H
