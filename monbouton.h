#ifndef MONBOUTON_H
#define MONBOUTON_H
#include <QPushButton>

class MonBouton:public QPushButton
{
   Q_OBJECT

   private:
        int id;
        char n;

    public:
        explicit MonBouton(int,char , QPushButton *parent = 0);

    signals:
        void monId(int);

    public slots:
        void selection();

};

#endif // MONBOUTON_H
