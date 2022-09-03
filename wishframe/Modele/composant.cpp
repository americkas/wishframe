#include "composant.h"

Composant::Composant(QObject *parent)
    : QObject(parent), largeur(50),hauteur(50)
{
}

void Composant::changerTailleComposant(int largeur, int hauteur){
    this->largeur = largeur;
    this->hauteur = hauteur;
}
void Composant::modifierPosition(QPoint position){
    this->position = position;
}

int Composant::recupererLargeur(){
    return this->largeur;
}

int Composant::recupererHauteur(){
    return this->hauteur;
}

QPoint Composant::recupererPosition(){
    return this->position;
}

QString Composant::classname(){
    return "Composant";
}
