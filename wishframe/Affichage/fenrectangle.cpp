#include "fenrectangle.h"
#include <string>

FenRectangle::FenRectangle(QWidget *parent, int bordRadius, QString bordCouleur, int largeur, int hauteur)
{
    this->setParent(parent);
    this->setStyleSheet("QLabel{background-color: white; height: 200px; width: 50px; border: 5px solid " + bordCouleur + "; border-radius: " + QString::number(bordRadius)+"px;}");
    this->setMinimumSize(largeur,hauteur);
}

QString FenRectangle::obtenirInfoString(){
    QString data =QString("<stylesheet>") + this->styleSheet() + QString("</stylesheet>") +
            QString("<hauteur>") + QString::number(this->size().height()) + QString("</hauteur>") +
            QString("<largeur>") + QString::number(this->size().width()) + QString("</largeur>") ;
    return data;
}
