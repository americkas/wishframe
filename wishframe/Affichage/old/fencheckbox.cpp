#include "fencheckbox.h"
#include "ui_fencheckbox.h"

FenCheckBox::FenCheckBox(QWidget *parent, QString name, bool checked) :
    QWidget(parent),
    ui(new Ui::FenCheckBox)
{
    ui->setupUi(this);

    ui->checkBox->setChecked(checked);
    ui->checkBox->setText(name);
}

FenCheckBox::~FenCheckBox()
{
    delete ui;
}
