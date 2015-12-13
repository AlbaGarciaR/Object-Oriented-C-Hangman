#ifndef DESSIN_H
#define DESSIN_H
#include"forme.h"
#include "rectangle.h"
#include "cercle.h"
#include<iostream>
#include <QWidget>
using namespace std;

class Dessin
{
    vector<Forme*> liste_formes;

public:
    Dessin();
    void afficher(QWidget*,int);
    ~Dessin();
};

#endif // DESSIN_H
