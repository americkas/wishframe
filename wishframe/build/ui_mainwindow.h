/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouveau_fichier;
    QAction *actionOuvrir_un_fichier;
    QAction *actionSauvegarder;
    QAction *actionSauvegarder_sous;
    QAction *actionFermer;
    QAction *actionQuitter;
    QAction *actionAnnuler;
    QAction *actionR_tablir;
    QAction *actionCouper;
    QAction *actionCopier;
    QAction *actionColler;
    QAction *actionSupprimer;
    QAction *actionajouterBouton;
    QAction *actionajouterImage;
    QAction *actionajouterRectangle;
    QAction *actionajouterChampDeTexte;
    QAction *actionajouterCheckBox;
    QAction *actionajouterRadioBox;
    QAction *actionajouterListeDeroulante;
    QAction *actionSauvegarder_sous_forme_d_image;
    QAction *actionRenommer_Onglet;
    QAction *actionModifier_objet;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menu_dition;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(807, 660);
        actionNouveau_fichier = new QAction(MainWindow);
        actionNouveau_fichier->setObjectName(QString::fromUtf8("actionNouveau_fichier"));
        actionOuvrir_un_fichier = new QAction(MainWindow);
        actionOuvrir_un_fichier->setObjectName(QString::fromUtf8("actionOuvrir_un_fichier"));
        actionSauvegarder = new QAction(MainWindow);
        actionSauvegarder->setObjectName(QString::fromUtf8("actionSauvegarder"));
        actionSauvegarder_sous = new QAction(MainWindow);
        actionSauvegarder_sous->setObjectName(QString::fromUtf8("actionSauvegarder_sous"));
        actionFermer = new QAction(MainWindow);
        actionFermer->setObjectName(QString::fromUtf8("actionFermer"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionAnnuler = new QAction(MainWindow);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionR_tablir = new QAction(MainWindow);
        actionR_tablir->setObjectName(QString::fromUtf8("actionR_tablir"));
        actionCouper = new QAction(MainWindow);
        actionCouper->setObjectName(QString::fromUtf8("actionCouper"));
        actionCopier = new QAction(MainWindow);
        actionCopier->setObjectName(QString::fromUtf8("actionCopier"));
        actionColler = new QAction(MainWindow);
        actionColler->setObjectName(QString::fromUtf8("actionColler"));
        actionSupprimer = new QAction(MainWindow);
        actionSupprimer->setObjectName(QString::fromUtf8("actionSupprimer"));
        actionajouterBouton = new QAction(MainWindow);
        actionajouterBouton->setObjectName(QString::fromUtf8("actionajouterBouton"));
        actionajouterImage = new QAction(MainWindow);
        actionajouterImage->setObjectName(QString::fromUtf8("actionajouterImage"));
        actionajouterRectangle = new QAction(MainWindow);
        actionajouterRectangle->setObjectName(QString::fromUtf8("actionajouterRectangle"));
        actionajouterChampDeTexte = new QAction(MainWindow);
        actionajouterChampDeTexte->setObjectName(QString::fromUtf8("actionajouterChampDeTexte"));
        actionajouterCheckBox = new QAction(MainWindow);
        actionajouterCheckBox->setObjectName(QString::fromUtf8("actionajouterCheckBox"));
        actionajouterRadioBox = new QAction(MainWindow);
        actionajouterRadioBox->setObjectName(QString::fromUtf8("actionajouterRadioBox"));
        actionajouterListeDeroulante = new QAction(MainWindow);
        actionajouterListeDeroulante->setObjectName(QString::fromUtf8("actionajouterListeDeroulante"));
        actionSauvegarder_sous_forme_d_image = new QAction(MainWindow);
        actionSauvegarder_sous_forme_d_image->setObjectName(QString::fromUtf8("actionSauvegarder_sous_forme_d_image"));
        actionRenommer_Onglet = new QAction(MainWindow);
        actionRenommer_Onglet->setObjectName(QString::fromUtf8("actionRenommer_Onglet"));
        actionModifier_objet = new QAction(MainWindow);
        actionModifier_objet->setObjectName(QString::fromUtf8("actionModifier_objet"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(false);

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 807, 20));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menu_dition = new QMenu(menubar);
        menu_dition->setObjectName(QString::fromUtf8("menu_dition"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menu_dition->menuAction());
        menuFichier->addAction(actionNouveau_fichier);
        menuFichier->addAction(actionOuvrir_un_fichier);
        menuFichier->addAction(actionSauvegarder);
        menuFichier->addAction(actionSauvegarder_sous);
        menuFichier->addAction(actionSauvegarder_sous_forme_d_image);
        menuFichier->addSeparator();
        menuFichier->addAction(actionFermer);
        menuFichier->addAction(actionQuitter);
        menu_dition->addAction(actionRenommer_Onglet);
        menu_dition->addSeparator();
        menu_dition->addAction(actionAnnuler);
        menu_dition->addAction(actionCouper);
        menu_dition->addAction(actionCopier);
        menu_dition->addAction(actionColler);
        menu_dition->addSeparator();
        menu_dition->addAction(actionSupprimer);
        menu_dition->addAction(actionModifier_objet);
        toolBar->addAction(actionajouterBouton);
        toolBar->addSeparator();
        toolBar->addAction(actionajouterImage);
        toolBar->addSeparator();
        toolBar->addAction(actionajouterRectangle);
        toolBar->addSeparator();
        toolBar->addAction(actionajouterChampDeTexte);
        toolBar->addSeparator();
        toolBar->addAction(actionajouterCheckBox);
        toolBar->addSeparator();
        toolBar->addAction(actionajouterRadioBox);
        toolBar->addSeparator();
        toolBar->addAction(actionajouterListeDeroulante);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNouveau_fichier->setText(QCoreApplication::translate("MainWindow", "Nouvelle page", nullptr));
        actionOuvrir_un_fichier->setText(QCoreApplication::translate("MainWindow", "Ouvrir un fichier", nullptr));
        actionSauvegarder->setText(QCoreApplication::translate("MainWindow", "Sauvegarder mod\303\250le", nullptr));
        actionSauvegarder_sous->setText(QCoreApplication::translate("MainWindow", "Sauvegarder mod\303\250le sous...", nullptr));
        actionFermer->setText(QCoreApplication::translate("MainWindow", "Fermer", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        actionAnnuler->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        actionR_tablir->setText(QCoreApplication::translate("MainWindow", "R\303\251tablir", nullptr));
        actionCouper->setText(QCoreApplication::translate("MainWindow", "Couper", nullptr));
#if QT_CONFIG(shortcut)
        actionCouper->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopier->setText(QCoreApplication::translate("MainWindow", "Copier", nullptr));
#if QT_CONFIG(shortcut)
        actionCopier->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionColler->setText(QCoreApplication::translate("MainWindow", "Coller", nullptr));
#if QT_CONFIG(shortcut)
        actionColler->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer objet", nullptr));
#if QT_CONFIG(shortcut)
        actionSupprimer->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionajouterBouton->setText(QCoreApplication::translate("MainWindow", "ajouterBouton", nullptr));
#if QT_CONFIG(tooltip)
        actionajouterBouton->setToolTip(QCoreApplication::translate("MainWindow", "ajouter bouton", nullptr));
#endif // QT_CONFIG(tooltip)
        actionajouterImage->setText(QCoreApplication::translate("MainWindow", "ajouterImage", nullptr));
#if QT_CONFIG(tooltip)
        actionajouterImage->setToolTip(QCoreApplication::translate("MainWindow", "ajouterImage", nullptr));
#endif // QT_CONFIG(tooltip)
        actionajouterRectangle->setText(QCoreApplication::translate("MainWindow", "ajouterRectangle", nullptr));
#if QT_CONFIG(tooltip)
        actionajouterRectangle->setToolTip(QCoreApplication::translate("MainWindow", "ajouterRectangle", nullptr));
#endif // QT_CONFIG(tooltip)
        actionajouterChampDeTexte->setText(QCoreApplication::translate("MainWindow", "ajouterChampDeTexte", nullptr));
#if QT_CONFIG(tooltip)
        actionajouterChampDeTexte->setToolTip(QCoreApplication::translate("MainWindow", "ajouterChampDeTexte", nullptr));
#endif // QT_CONFIG(tooltip)
        actionajouterCheckBox->setText(QCoreApplication::translate("MainWindow", "ajouterCheckBox", nullptr));
#if QT_CONFIG(tooltip)
        actionajouterCheckBox->setToolTip(QCoreApplication::translate("MainWindow", "ajouterCheckBox", nullptr));
#endif // QT_CONFIG(tooltip)
        actionajouterRadioBox->setText(QCoreApplication::translate("MainWindow", "ajouterRadioBox", nullptr));
#if QT_CONFIG(tooltip)
        actionajouterRadioBox->setToolTip(QCoreApplication::translate("MainWindow", "ajouterRadioBox", nullptr));
#endif // QT_CONFIG(tooltip)
        actionajouterListeDeroulante->setText(QCoreApplication::translate("MainWindow", "ajouterListeDeroulante", nullptr));
#if QT_CONFIG(tooltip)
        actionajouterListeDeroulante->setToolTip(QCoreApplication::translate("MainWindow", "ajouterListeDeroulante", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSauvegarder_sous_forme_d_image->setText(QCoreApplication::translate("MainWindow", "Sauvegarder sous forme d'image", nullptr));
        actionRenommer_Onglet->setText(QCoreApplication::translate("MainWindow", "Renommer Onglet", nullptr));
        actionModifier_objet->setText(QCoreApplication::translate("MainWindow", "Modifier objet", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        menu_dition->setTitle(QCoreApplication::translate("MainWindow", "\303\211dition", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
