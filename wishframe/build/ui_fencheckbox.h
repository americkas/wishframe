/********************************************************************************
** Form generated from reading UI file 'fencheckbox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENCHECKBOX_H
#define UI_FENCHECKBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenCheckBox
{
public:
    QCheckBox *checkBox;

    void setupUi(QWidget *FenCheckBox)
    {
        if (FenCheckBox->objectName().isEmpty())
            FenCheckBox->setObjectName(QString::fromUtf8("FenCheckBox"));
        FenCheckBox->resize(400, 300);
        checkBox = new QCheckBox(FenCheckBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(160, 100, 86, 20));

        retranslateUi(FenCheckBox);

        QMetaObject::connectSlotsByName(FenCheckBox);
    } // setupUi

    void retranslateUi(QWidget *FenCheckBox)
    {
        FenCheckBox->setWindowTitle(QCoreApplication::translate("FenCheckBox", "Form", nullptr));
        checkBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FenCheckBox: public Ui_FenCheckBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENCHECKBOX_H
