#ifndef CERCLE_H
#define CERCLE_H
#include "forme.h"

class Cercle : public Forme

{
    protected:
        int rayon;
    public:
        Cercle(int, int, int);
        virtual void afficher(QWidget*);
        int getr();
};


#endif // CERCLE_H

