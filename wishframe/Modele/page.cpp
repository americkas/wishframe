#include "page.h"
#include<QDebug>

Page::Page(QObject *parent)
    : QObject(parent)
{
}

Page::Page(QString type)
    : type(type)
{ //TODO On n'est pas sûr d'implémenter la taille des pages dans l'aspect graphique
    if (type == "Paysage"){
        this->hauteur = 900;
        this->largeur = 1600;

    }
    else if (type == "Portrait"){
        this->hauteur = 1600;
        this->largeur = 900;
    }
    else {
        this->hauteur = 1600;
        this->largeur = 1600;
             }
}

void Page::ajouterComposant(Typecomposant composant){
        switch(composant){
            case Typecomposant::Checkbox:{
                Checkbox * checkbox = new Checkbox();
                composants.append(checkbox);
                //return checkbox;
                break;
            }
            case Typecomposant::RadioBox:{
                Radiobox * radiobox = new Radiobox();
                composants.append(radiobox);
                //return radiobox;
                break;
            }
            case Typecomposant::Bouton:{
                Bouton * bouton = new Bouton();
                composants.append(bouton);
                //return bouton;
                break;
            }
            case Typecomposant::Rectangle:{
                Rectangle * rectangle = new Rectangle();
                composants.append(rectangle);
                //return rectangle;
                break;
            }
            case Typecomposant::Image:{
                Image * image = new Image();
                composants.append(image);
                //return image;
                break;
            }
            case Typecomposant::ChampDeTexte:{
                ChampDeTexte * champDeTexte = new ChampDeTexte();
                composants.append(champDeTexte);
                //return champDeTexte;
                break;
            }
            case Typecomposant::ListeDeroulante:{
                ListeDeroulante * listeDeroulante = new ListeDeroulante();
                composants.append(listeDeroulante);
                //return listeDeroulante;
                break;
            }
            default:
                qFatal( "Composant non reconnu");
        }
     }

void Page::ajouterComposant(Composant* composant){
    composants.append(composant);
}

void Page::retirerComposant(Composant * composant){
    this->composants.removeOne(composant);
}
void Page::changerTaillePage(int hauteur, int largeur){
    this->largeur = largeur;
    this->hauteur = hauteur;
}

int Page::recupererLargeur(){
    return this->largeur;
}

int Page::recupererHauteur(){
    return this->hauteur;
}

QString Page::recupererType(){
    return this->type;
}

QList<Composant*> Page::recupererComposants(){
    return this->composants;
}

/*void Page::sauvegarderPage(){
//TODO
}*/
