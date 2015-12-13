#ifndef ZONEDESSIN_H
#define ZONEDESSIN_H
#include "dessin.h"
#include <QWidget>
using namespace std;

class Dessin;

class ZoneDessin : public QWidget
{
    Q_OBJECT

    Dessin d;
    int cpt;

public:
    explicit ZoneDessin(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void initCpt();
    void incCpt();
};


#endif // ZONEDESSIN_H
