/********************************************************************************
** Form generated from reading UI file 'fenlistederoulante.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENLISTEDEROULANTE_H
#define UI_FENLISTEDEROULANTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenListeDeroulante
{
public:
    QComboBox *comboBox;

    void setupUi(QWidget *FenListeDeroulante)
    {
        if (FenListeDeroulante->objectName().isEmpty())
            FenListeDeroulante->setObjectName(QString::fromUtf8("FenListeDeroulante"));
        FenListeDeroulante->resize(400, 300);
        comboBox = new QComboBox(FenListeDeroulante);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 60, 161, 61));

        retranslateUi(FenListeDeroulante);

        QMetaObject::connectSlotsByName(FenListeDeroulante);
    } // setupUi

    void retranslateUi(QWidget *FenListeDeroulante)
    {
        FenListeDeroulante->setWindowTitle(QCoreApplication::translate("FenListeDeroulante", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenListeDeroulante: public Ui_FenListeDeroulante {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENLISTEDEROULANTE_H
