#ifndef FENIMAGE_H
#define FENIMAGE_H

#include <QWidget>

namespace Ui {
class FenImage;
}

class FenImage : public QWidget
{
    Q_OBJECT

public:
    explicit FenImage(QWidget *parent = nullptr, QString lien = ":/images/boat.png");
    ~FenImage();
signals:
     void modifierLienImg(QString lien);


private:
    Ui::FenImage *ui;
};

#endif // FENIMAGE_H
