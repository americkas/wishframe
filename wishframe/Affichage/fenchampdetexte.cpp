#include "fenchampdetexte.h"
#include <QTextEdit>


FenChampDeTexte::FenChampDeTexte(QWidget *parent, QString nom, QString policeCouleur, int policeTaille, int largeur, int hauteur){
    this->setParent(parent);
    this->setText(nom);
    this->setStyleSheet("{font-size:" + QString::number(policeTaille) +"px;color: " + policeCouleur + ";}");
    this->setMinimumSize(largeur,hauteur);
    this->setFrameShape(QFrame::Box);
}

QString FenChampDeTexte::obtenirInfoString(){
    QString data = QString("<champ>") + this->text() + QString("</champ>") +
            QString("<stylesheet>") + this->styleSheet() + QString("</stylesheet>") +
            QString("<hauteur>") + QString::number(this->size().height()) + QString("</hauteur>") +
            QString("<largeur>") + QString::number(this->size().width()) + QString("</largeur>") ;
    return data;
}
