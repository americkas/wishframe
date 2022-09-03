/********************************************************************************
** Form generated from reading UI file 'fenradiobox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENRADIOBOX_H
#define UI_FENRADIOBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenRadioBox
{
public:
    QRadioButton *radioButton;

    void setupUi(QWidget *FenRadioBox)
    {
        if (FenRadioBox->objectName().isEmpty())
            FenRadioBox->setObjectName(QString::fromUtf8("FenRadioBox"));
        FenRadioBox->resize(400, 300);
        radioButton = new QRadioButton(FenRadioBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(150, 90, 99, 20));

        retranslateUi(FenRadioBox);

        QMetaObject::connectSlotsByName(FenRadioBox);
    } // setupUi

    void retranslateUi(QWidget *FenRadioBox)
    {
        FenRadioBox->setWindowTitle(QCoreApplication::translate("FenRadioBox", "Form", nullptr));
        radioButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FenRadioBox: public Ui_FenRadioBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENRADIOBOX_H
