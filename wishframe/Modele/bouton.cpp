#include "bouton.h"

Bouton::Bouton():champ("Nom"),policeCouleur("rgb(0,0,0)"),policeTaille(11)
{

}

void Bouton::changerPoliceTaille (int taille){
    this->policeTaille = taille;
}
void Bouton::changerPoliceCouleur (QString couleur){
    this->policeCouleur = couleur;
}
void Bouton::modifierChamp(QString champ){
    this->champ = champ;
}

QString Bouton::recupererChamp(){
    return this->champ;
}

QString Bouton::recupererPoliceCouleur(){
    return this->policeCouleur;
}

int Bouton::recupererPoliceTaille(){
    return this->policeTaille;
}

QString Bouton::classname(){
    return "Bouton";
}
