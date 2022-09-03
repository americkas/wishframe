#include "controlleur.h"

Controlleur::Controlleur(QObject *parent, QTabWidget * tabWidget)
    : QObject(parent),tabWidget(tabWidget)
{
}

void Controlleur::nouvellePage(/*type*/){
    gestionnaire.creerPage("portrait");

}


void Controlleur::ajouterComposant(Typecomposant composant){
    Page * page = gestionnaire.page(tabWidget->currentIndex());
    page->ajouterComposant(composant);
    //TODO connect composants modifiés A faire dans le MainWindow pour chaque type
    //TODO connect

}

void Controlleur::modifierComposant(Composant * composant , QWidget * widget){

}

void Controlleur::supprPage(Page * page){
    gestionnaire.supprPage(page);

}

void Controlleur::chargerFichier(QString lien, DragWidget* dragwidget){
    QList<Composant*> composants = gestionnaire.chargerPage(lien)->recupererComposants();
    foreach(Composant * composant, composants){
        //dragwidget->ajouterComposant(,);
    }
}

void Controlleur::supprComposant(Composant * composant){

}
