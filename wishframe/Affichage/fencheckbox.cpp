#include "fencheckbox.h"

FenCheckBox::FenCheckBox(QWidget *parent, QString nom, bool checked, int largeur, int hauteur)
{
    this->setParent(parent);
    this->setChecked(checked);
    this->setText(nom);
    this->setMinimumSize(largeur,hauteur);
}


QString FenCheckBox::obtenirInfoString(){
    QString check= "false";
    if (this->isChecked()){
        check= "true";
    }
    QString data = QString("<nom>") + this->text() + QString("</nom>") +
            QString("<checked>") + check + QString("</checked>") +
            QString("<hauteur>") + QString::number(this->size().height()) + QString("</hauteur>") +
            QString("<largeur>") + QString::number(this->size().width()) + QString("</largeur>") ;
    return data;
}
