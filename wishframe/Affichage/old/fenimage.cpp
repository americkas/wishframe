#include "fenimage.h"
#include "ui_fenimage.h"
#include <QLabel>

FenImage::FenImage(QWidget *parent, QString lien) :
    QWidget(parent),
    ui(new Ui::FenImage)
{
    ui->setupUi(this);

    ui->label->setPixmap(QPixmap(lien));
}

FenImage::~FenImage()
{
    delete ui;
}
