#include "fenbouton.h"

FenBouton::FenBouton(QWidget *parent, QString nom, QString policeCouleur, int policeTaille, int largeur, int hauteur)
{
    this->setParent(parent);
    this->setText(nom);
    this->setStyleSheet("QPushButton{font-size:" + QString::number(policeTaille) +"px;color: " + policeCouleur + ";}");
    this->setMinimumSize(largeur,hauteur);
}

QString FenBouton::obtenirInfoString(){
    QString data = QString("<nom>") + this->text() + QString("</nom>") +
            QString("<stylesheet>") + this->styleSheet() + QString("</stylesheet>") +
            QString("<hauteur>") + QString::number(this->size().height()) + QString("</hauteur>") +
            QString("<largeur>") + QString::number(this->size().width()) + QString("</largeur>") ;
    return data;
}
