#include "fenradiobox.h"
#include "ui_fenradiobox.h"

FenRadioBox::FenRadioBox(QWidget *parent, QString name, bool checked) :
    QWidget(parent),
    ui(new Ui::FenRadioBox)
{
    ui->setupUi(this);

    ui->radioButton->setText(name);
    ui->radioButton->setChecked(checked);
}

FenRadioBox::~FenRadioBox()
{
    delete ui;
}
