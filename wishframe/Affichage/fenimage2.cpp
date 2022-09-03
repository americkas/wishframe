#include "fenimage2.h"
#include <QLabel>


FenImage2::FenImage2(QWidget* parent, QString lien)
{
    this->setParent(parent);
    this->setPixmap(QPixmap(lien));
}

