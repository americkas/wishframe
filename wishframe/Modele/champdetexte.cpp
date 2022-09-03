#include "champdetexte.h"

ChampDeTexte::ChampDeTexte():champ("Nom"),policeCouleur("#000000"),policeTaille(11)
{

}


void ChampDeTexte::changerPoliceTaille (int taille){
    this->policeTaille = taille;
}
void ChampDeTexte::changerPoliceCouleur (QString couleur){
    this->policeCouleur = couleur;
}
void ChampDeTexte::modifierChamp(QString champ){
    this->champ = champ;
}

QString ChampDeTexte::recupererChamp(){
    return this->champ;
}

QString ChampDeTexte::recupererPoliceCouleur(){
    return this->policeCouleur;
}

int ChampDeTexte::recupererPoliceTaille(){
    return this->policeTaille;
}

QString ChampDeTexte::classname(){
    return "ChampDeTexte";
}
