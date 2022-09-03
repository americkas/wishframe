#include "fenlistederoulante.h"

FenListeDeroulante::FenListeDeroulante(QWidget *parent, QList<ElementListe*> elements)
{
    this->setParent(parent);

    for (int i = 0; i < elements.size(); ++i) {
        this->addItem({elements[i]->recupererNom()});
        this->setStyleSheet({"font-color: white;"});
    }

    this->setMinimumSize(100,40);

}

QString FenListeDeroulante::obtenirInfoString(){
    QString data = "";//TODO
    /*QString data = QString("<nom>") + this->text() + QString("</nom>") +
            QString("<stylesheet>") + this->styleSheet() + QString("</stylesheet>") +
            QString("<checked>") + check + QString("</checked>") +
            QString("<hauteur>") + QString::number(this->size().height()) + QString("</hauteur>") +
            QString("<largeur>") + QString::number(this->size().width()) + QString("</largeur>") ;*/
    return data;
}
