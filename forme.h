#ifndef FORME_H
#define FORME_H

#include <QWidget>

class Forme
{
    protected:
        int xc;
        int yc;
    public:
        Forme(int ,int );
        virtual void afficher(QWidget*) = 0;
        int getx();
        int gety();
};

#endif // FORME_H
