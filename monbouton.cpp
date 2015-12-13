#include "monbouton.h"
#include <QString>
#include <QPushButton>
#include "plateau.h"
#include <QWidget>

MonBouton::MonBouton(int num, char n, QPushButton * parent) : QPushButton(parent)
{

    QChar carac=n;
    QString nom(carac);
    setText(nom);
    id=num;
}

void MonBouton::selection()
{
    this->setEnabled(false);
    emit monId(id);
    update();
}
