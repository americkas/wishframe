#include "fenlistederoulante.h"
#include "ui_fenlistederoulante.h"

FenListeDeroulante::FenListeDeroulante(QWidget *parent, QList<ElementListe*> elements) :
    QWidget(parent),
    ui(new Ui::FenListeDeroulante)
{
    ui->setupUi(this);

    for (int i = 0; i < elements.size(); ++i) {
        ui->comboBox->addItem({elements[i]->recupererNom()});
        ui->comboBox->setStyleSheet({"font-color: white;"});
    }

}

FenListeDeroulante::~FenListeDeroulante()
{
    delete ui;
}
