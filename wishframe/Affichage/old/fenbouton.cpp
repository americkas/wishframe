#include "fenbouton.h"
#include "ui_fenbouton.h"
#include <QMouseEvent>
#include <QDrag>
#include <QMenu>
#include <QMimeData>

FenBouton::FenBouton(QWidget *parent, QString nom, QString policeCouleur, int policeTaille) :
    QWidget(parent),
    ui(new Ui::FenBouton)
{
    ui->setupUi(this);
    ui->pushButton->setText(nom);
    ui->pushButton->setStyleSheet("QPushButton{font-size:" + QString::number(policeTaille) +"px;color: " + policeCouleur + ";}");


}

FenBouton::~FenBouton()
{
    delete ui;
}
