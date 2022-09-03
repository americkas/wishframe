/********************************************************************************
** Form generated from reading UI file 'fenimage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENIMAGE_H
#define UI_FENIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenImage
{
public:
    QLabel *label;

    void setupUi(QWidget *FenImage)
    {
        if (FenImage->objectName().isEmpty())
            FenImage->setObjectName(QString::fromUtf8("FenImage"));
        FenImage->resize(224, 193);
        FenImage->setAutoFillBackground(false);
        FenImage->setStyleSheet(QString::fromUtf8(":hover{background:#e5f1fb}"));
        label = new QLabel(FenImage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 181, 141));
        label->setAutoFillBackground(false);
        label->setFrameShape(QFrame::Box);

        retranslateUi(FenImage);

        QMetaObject::connectSlotsByName(FenImage);
    } // setupUi

    void retranslateUi(QWidget *FenImage)
    {
        FenImage->setWindowTitle(QCoreApplication::translate("FenImage", "Form", nullptr));
        label->setText(QCoreApplication::translate("FenImage", "abc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenImage: public Ui_FenImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENIMAGE_H
