#ifndef CONTROLLEUR_H
#define CONTROLLEUR_H

#include <QObject>
#include <QTabWidget>

#include "Affichage/dragwidget.h"
#include "Modele/gestionnairepages.h"

class Controlleur : public QObject
{

    Q_OBJECT
public:
    Controlleur(QObject *parent = nullptr, QTabWidget * tabWidget = new QTabWidget);

public slots:
    void nouvellePage();
    void ajouterComposant(Typecomposant composant);
    void modifierComposant(Composant * composant , QWidget * widget);
    void supprPage(Page * page);
    void chargerFichier(QString lien, DragWidget* dragwidget);
    void supprComposant(Composant * composant);

private:
    GestionnairePages gestionnaire;
    int nvCount;
    QTabWidget * tabWidget;
};

#endif // CONTROLLEUR_H
