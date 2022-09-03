/********************************************************************************
** Form generated from reading UI file 'fenchampdetexte.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENCHAMPDETEXTE_H
#define UI_FENCHAMPDETEXTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenChampDeTexte
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *FenChampDeTexte)
    {
        if (FenChampDeTexte->objectName().isEmpty())
            FenChampDeTexte->setObjectName(QString::fromUtf8("FenChampDeTexte"));
        FenChampDeTexte->resize(400, 193);
        textEdit = new QTextEdit(FenChampDeTexte);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(60, 30, 261, 111));
        textEdit->setAutoFillBackground(false);

        retranslateUi(FenChampDeTexte);

        QMetaObject::connectSlotsByName(FenChampDeTexte);
    } // setupUi

    void retranslateUi(QWidget *FenChampDeTexte)
    {
        FenChampDeTexte->setWindowTitle(QCoreApplication::translate("FenChampDeTexte", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenChampDeTexte: public Ui_FenChampDeTexte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENCHAMPDETEXTE_H
