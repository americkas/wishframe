#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include "Affichage/fenbouton.h"
#include "Affichage/fenimage.h"
#include "Affichage/fenrectangle.h"
#include "Affichage/fenchampdetexte.h"
#include "Affichage/fencheckbox.h"
#include "Affichage/fenradiobox.h"
#include "Affichage/fenlistederoulante.h"
#include "Modele/page.h"
#include <QFrame>
#include <QRubberBand>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

//! [0]
class DragWidget : public QFrame
{
public:
    explicit DragWidget(QWidget *parent = nullptr);
    void ajouterComposant(QWidget * instance, QPoint point);
    void ajouterComposant(Typecomposant composant);
    QString obtenirDialogBoxComposant(QWidget * composant, QWidget * parent);
    void modifierComposant(QString InfoString, QWidget * composant);
    QList <QWidget *> enfants();
    QWidget * creerComposantDepuisInfoString(QString InfoString, QString widgetType);
    QString obtenirInfoString(QWidget * composant);
    QString stylesheet(QString type, QString couleur, QString nombre);
    //void obtenirDonneesDepuisInfoString(QString InfoString, QVariant * nom, QVariant * stylesheet, QVariant * hauteur, QVariant *largeur,  QVariant * champ, QVariant *lien , QVariant * checked);

signals:
    void fermerOnglet(int index);
    void modifierTaille(int largeur,int hauteur);


protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void showContextMenu();
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    QString type_widget;
    void mouseMoveEvent(QMouseEvent *event) override;
    int index_widget;
    QRubberBand * rubberBand;



private:
    QPoint dragStartPosition;
    QList <QWidget *> listeWidgets;

};
//! [0]

#endif // DRAGWIDGET_H
