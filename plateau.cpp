#include "plateau.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QObject>

#include <QGridLayout>
#include <QString>
#include <fstream>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;


Plateau::Plateau(QWidget *parent) : QWidget(parent)
{
    zoneDessin = new ZoneDessin;
    QPushButton *quitButton = new QPushButton("Quitter");
    QPushButton *newButton = new QPushButton("Nouvelle Partie");

    QHBoxLayout *layout1 = new QHBoxLayout; // Creation d’un layout horizontal
    layout1->addWidget(newButton); // Ajout du premier bouton au layout
    layout1->addWidget(quitButton); // Ajout du troisieme bouton au layout

    QVBoxLayout *layout2 = new QVBoxLayout; // Creation d’un layout vertical
    layout2->addLayout(layout1); // Ajout de layout1 au layout2
    layout2->addWidget(zoneDessin); // Ajout de zoneDessin au layout2

    setLayout(layout2);

    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(newButton, SIGNAL(clicked()), this, SLOT(new_game()));

    lmot = new QLabel;
    layout2->addWidget(lmot);
    lmot->setText("Bienvenue dans le jeu du pendu");
    charge_mots();      //on charge les mots dans le vecteur mots
    srand(time(NULL)); // Appel a srand pour initialiser le generateur de nombre aleatoires

        int i;
        for(i=0;i<26;i++)
        {
            MonBouton * a = new MonBouton(i,'A'+i);
            boutons.push_back(a);      //création des boutons et ajout au vecteur boutons
            boutons[i]->setEnabled(false);
        }

        QGridLayout * clavier = new QGridLayout;
        for(i=0;i<7;i++)
        {
            clavier->addWidget(boutons[i],1,i+1);
        }
        for(i=7;i<14;i++)
        {
            clavier->addWidget(boutons[i],2,i-6);
        }
        for(i=14;i<21;i++)
        {
            clavier->addWidget(boutons[i],3,i-13);
        }
        for(i=21;i<26;i++)
        {
            clavier->addWidget(boutons[i],4,i-19);
        }

        for(int i=0;i<26;i++)
        {
        connect(boutons[i], SIGNAL(clicked()), boutons[i], SLOT(selection()));
        connect(boutons[i],SIGNAL(monId(int)),this,SLOT(traitement(int)));
        }

        layout2->addLayout(clavier);
}

void Plateau::new_game()
{

    int x = rand() % mots.size(); //on choisit un mot aléatoirement
    mot=mots[x];


        motAffiche=QString(mot.size(),'*');

        lmot->setText("Mot : "+motAffiche);

        nbManques=0;

        zoneDessin->initCpt();

        for(double i=0;i<26;i++)
        {
            boutons[i]->setEnabled(true);
        }
}

void Plateau::traitement(int j)
{
    int compteur = 0;
    char c = 'A'+j;
    for (int i = 0; i<mot.size(); i++)
    {
        if (mot[i] == c)
        {
            motAffiche[i]=c;
            lmot->setText("Mot : "+motAffiche);
            compteur++;
        }
    }
    if(compteur==0)
    {
        nbManques++;
        zoneDessin->incCpt();
    }
    if(nbManques==10)
    {
        endGame(false);
    }
    if(mot==motAffiche)
    {
        endGame(true);
    }
    update();
}

void Plateau::charge_mots()
{

    ifstream f("mots.txt");      // tentative d’ouverture du fichier
    if (f)                       // permet de verifier si le fichier a pu etre ouvert
    { // le fichier a pu etre ouvert
    string s;
    while (f) // parcours du fichier
    {
    getline(f,s);                // stockage de la ligne en cours de f dans s et
                                 // passage a la ligne suivante
    QString s1;
    s1 = QString(s.c_str()); // initialization d’un objet QString a partir d’un objet string
    mots.push_back(s1.toUpper()); // ajout de la conversion en majuscule de s2 au vecteur v
    }
    f.close();                   // fermeture du fichier. A NE PAS OUBLIER !
    }
    else
    { // le fichier n’a pas pu etre ouvert
      //si mots.txt ne s'ouvre pas
            QString m,p;
            m="ALBA";
            p="FLORIAN";
            mots.push_back(m);
            mots.push_back(p);
    }
}

void Plateau::endGame(bool win)
{
    for(double i=0;i<26;i++)
    {
        boutons[i]->setEnabled(false);
    }
     if(win)
     {
         lmot->setText("Vous avez gagne ! Le mot etait : "+mot);
     }

     else
     {
         lmot->setText("Vous avez perdu ! Le mot etait : "+mot);
     }
}
