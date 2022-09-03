#include "fenimage.h"

FenImage::FenImage(QWidget* parent, QString lien)
    :lien(lien)
{
    this->setParent(parent);
    this->setPixmap(QPixmap(lien));
    this->setFrameShape(QFrame::Box);
}

QString FenImage::obtenirInfoString(){
    QString data = QString("<lien>") + this->lien + QString("</lien>")+
            QString("<hauteur>") + QString::number(this->size().height()) + QString("</hauteur>") +
            QString("<largeur>") + QString::number(this->size().width()) + QString("</largeur>") ;;
    return data;
}
