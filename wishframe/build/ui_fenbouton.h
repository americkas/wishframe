/********************************************************************************
** Form generated from reading UI file 'fenbouton.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENBOUTON_H
#define UI_FENBOUTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenBouton
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *FenBouton)
    {
        if (FenBouton->objectName().isEmpty())
            FenBouton->setObjectName(QString::fromUtf8("FenBouton"));
        FenBouton->resize(222, 135);
        FenBouton->setAcceptDrops(false);
        FenBouton->setAutoFillBackground(false);
        FenBouton->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(FenBouton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 40, 111, 51));

        retranslateUi(FenBouton);

        QMetaObject::connectSlotsByName(FenBouton);
    } // setupUi

    void retranslateUi(QWidget *FenBouton)
    {
        FenBouton->setWindowTitle(QCoreApplication::translate("FenBouton", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("FenBouton", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenBouton: public Ui_FenBouton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENBOUTON_H
