#include "fenchampdetexte.h"
#include "ui_fenchampdetexte.h"
#include <QTextEdit>

FenChampDeTexte::FenChampDeTexte(QWidget *parent, QString champ, QString policeCouleur, int policeTaille):
    QWidget(parent),
    ui(new Ui::FenChampDeTexte)
{
    ui->setupUi(this);

    ui->textEdit->setStyleSheet("QTextEdit{background-color: white; color: "+policeCouleur+"; font: "+policeTaille+ "pt}");
    ui->textEdit->setText(champ);
}

FenChampDeTexte::~FenChampDeTexte()
{
    delete ui;
}
