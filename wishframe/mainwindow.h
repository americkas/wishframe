#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "controlleur.h"
#include <QMainWindow>

#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <qpushbutton.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionajouterBouton_triggered();

    void on_actionajouterImage_triggered();

    void on_actionajouterRectangle_triggered();

    void on_actionajouterChampDeTexte_triggered();

    void on_actionajouterCheckBox_triggered();

    void on_actionajouterRadioBox_triggered();

    void on_actionajouterListeDeroulante_triggered();

    void on_actionSupprimer_triggered();


    void on_actionNouveau_fichier_triggered(bool firstTab);

    void on_tabWidget_tabCloseRequested(int index);

    void on_actionFermer_triggered(int index);

    void on_actionSauvegarder_sous_triggered();

    void on_actionSauvegarder_triggered();

    void on_actionSauvegarder_sous_forme_d_image_triggered();

    void on_actionRenommer_Onglet_triggered();

    void on_actionModifier_objet_triggered();

    void on_actionCopier_triggered();

    void on_actionColler_triggered();

    void on_actionCouper_triggered();

private:
    Ui::MainWindow *ui;
    int nvCount;
    void sauvegarderFichier(const QString & fileName);
    Controlleur controlleur;
};
#endif // MAINWINDOW_H
