/********************************************************************************
** Form generated from reading UI file 'fenrectangle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENRECTANGLE_H
#define UI_FENRECTANGLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenRectangle
{
public:
    QLabel *label;

    void setupUi(QWidget *FenRectangle)
    {
        if (FenRectangle->objectName().isEmpty())
            FenRectangle->setObjectName(QString::fromUtf8("FenRectangle"));
        FenRectangle->resize(400, 300);
        label = new QLabel(FenRectangle);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 60, 281, 171));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 255, 0);\n"
"border-width: thick;"));

        retranslateUi(FenRectangle);

        QMetaObject::connectSlotsByName(FenRectangle);
    } // setupUi

    void retranslateUi(QWidget *FenRectangle)
    {
        FenRectangle->setWindowTitle(QCoreApplication::translate("FenRectangle", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FenRectangle: public Ui_FenRectangle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENRECTANGLE_H
