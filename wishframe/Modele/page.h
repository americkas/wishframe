#ifndef PAGE_H
#define PAGE_H

/*!
 * \file page.h
 * \brief Classe Page
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include <QObject>
#include <QList>
#include "Modele/bouton.h"
#include "Modele/champdetexte.h"
#include "Modele/checkbox.h"
#include "Modele/image.h"
#include "Modele/listederoulante.h"
#include "Modele/radiobox.h"
#include "Modele/rectangle.h"

//! Enumere Typecomposant.
/*! Enumere l'ensemble des types que peuvent prendre les composants de l'ui. */
enum class Typecomposant { Checkbox, /*!< Type CheckBox. */
                           RadioBox, /*!< Type RadioBox. */
                           Bouton, /*!< Type Bouton. */
                           Rectangle, /*!< Type Rectangle. */
                           Image, /*!< Type Image. */
                           ChampDeTexte, /*!< Type ChampDeTexte. */
                           ListeDeroulante }; /*!< Type ListeDeroulante. */

/*! \class Page
  * \brief classe representant une page
  *
  *  La classe gere la structure d'un onglet (donc une page) de l'interface
  */
class Page : public QObject
{
    Q_OBJECT
public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Page
     *
     *  \param parent : le conteneur de la page
     */
    Page(QObject *parent = nullptr);

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Page
     *
     *  \param type : le type de la page a construire
     */
    Page(QString type);

    /*!
     *  \brief Ajout d'un composant
     *
     *  Methode qui permet d'ajouter un nouveau
     *  composant a la page
     *
     *  \param composant : le composant a ajouter
     */
    void ajouterComposant(Typecomposant composant);

    /*!
     *  \brief Ajout d'un composant
     *
     *  Methode qui permet d'ajouter un
     *  composant custom a la page
     *
     *  \param composant : le composant a ajouter
     */
    void ajouterComposant(Composant* composant);

    /*!
     *  \brief Suppression d'un composant
     *
     *  Methode qui permet de supprimer
     *  un composant de la page
     *
     *  \param composant : le composant a supprimer
     */
    void retirerComposant(Composant * composant);

    /*!
     *  \brief Recuperer la largeur de la page
     *
     *  Methode qui permet de recuperer la largeur
     *  de la page
     *
     *  \return : la largeur de la page
     */
    int recupererLargeur();

    /*!
     *  \brief Recuperer la hauteur de la page
     *
     *  Methode qui permet de recuperer la hauteur
     *  de la page
     *
     *  \return : la hauteur de la page
     */
    int recupererHauteur();

    /*!
     *  \brief Recuperer le type de la page
     *
     *  Methode qui permet de recuperer le type de
     *  la page
     *
     *  \return : le type de la page
     */
    QString recupererType();

    /*!
     *  \brief Recuperer les composants de la page
     *
     *  Methode qui permet de recuperer la liste
     *  des composants de la page
     *
     *  \return : la liste des composants
     */
    QList<Composant*> recupererComposants();

    /*!
     *  brief Sauvegarder la page
     *
     *  Methode qui permet de sauvegarder
     *  la page, l'instance

    void sauvegarderPage();*/

public slots:
    /*!
     *  \brief Slot pour changer la taille de la page
     *
     *  Slot qui permet de modifier les dimensions de la page, l'instance
     */
    void changerTaillePage(int hauteur, int largeur);

private:
    int largeur; /*!< largeur de la page*/
    int hauteur; /*!< hauteur de la page*/
    QString type; /*!< type de la page*/
    QList<Composant*> composants; /*!< liste des composants de la page*/
};

#endif // PAGE_H
