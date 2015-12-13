#ifndef PLATEAU_H
#define PLATEAU_H
#include "zonedessin.h"
#include <QWidget>
#include<QObject>
//#include <QApplication>
#include <monbouton.h>
//#include <vector>
#include <QLabel>

using namespace std;

class Plateau : public QWidget
{

    Q_OBJECT

    private :
        ZoneDessin *zoneDessin;
        vector<MonBouton*> boutons;
        QString mot;
        QString motAffiche;
        QLabel *lmot;
        int nbManques;
        vector<QString> mots;

    public:
        explicit Plateau(QWidget *parent = 0);
        void endGame(bool);
        void set_mot(QString);
        void charge_mots();

    signals:

    public slots:
        void new_game();
        void traitement(int);





};

#endif // PLATEAU_H
