#include "fenrectangle.h"
#include "ui_fenrectangle.h"
#include <string>

FenRectangle::FenRectangle(QWidget *parent, int bordRadius, QString bordCouleur) :
    QWidget(parent),
    ui(new Ui::FenRectangle)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel{background-color: white; border: 5px solid " + bordCouleur + "; border-radius: " + QString::number(bordRadius)+"px;}");
}

FenRectangle::~FenRectangle()
{
    delete ui;
}
