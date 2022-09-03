#include "rectangle.h"

Rectangle::Rectangle()
{

}

void Rectangle::changerBordRadius(int radius){
    this->bordRadius = radius;
}

void Rectangle::changerBordCouleur(QString couleur){
    this->bordCouleur = couleur;
}

int Rectangle::recupererBordRadius(){
    return this->bordRadius;
}

QString Rectangle::recupererBordCouleur(){
    return this->bordCouleur;
}

QString Rectangle::classname(){
    return "Rectangle";
}
