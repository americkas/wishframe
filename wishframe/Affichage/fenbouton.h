#ifndef FENBOUTON_H
#define FENBOUTON_H

/*!
 * \file fenbouton.h
 * \brief Classe FenBouton
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include <QPushButton>

/*! \class FenBouton
  * \brief classe representant l'affichage d'un Bouton
  *
  *  La classe gere la structure d'un FenBouton
  *  qui correspond a l'affichage d'un Bouton
  */
class FenBouton : public QPushButton
{
    Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe FenBouton
     *
     *  \param parent : le conteneur du FenBouton
     *  \param nom : le nom du widget
     *  \param policeCouleur : la couleur du texte dans le widget
     *  \param policeTaille : la police du texte dans le widget
     *  \param largeur : la largeur du widget
     *  \param hauteur : la hauteur du widget
     */
    explicit FenBouton(QWidget *parent = nullptr, QString nom = "voila", QString policeCouleur= "rgb(0,0,0)", int PoliceTaille = 11, int largeur = 100, int hauteur = 50);

    /*!
     *  \brief Recupere les donnees du FenBouton sous format de balises
     *
     *  Methode qui permet de recupere les donnees du FenBouton
     *  avec des balises semblables au format Html, cela va
     *  servir a sauvegarder les FenBoutons
     *
     *  \return : le string finale avec les différentes balises
     */
    QString obtenirInfoString();

signals: 
    /*!
     *  Signal qui permet de modifier le champ du FenBouton
     *
     *  \param champ : le nouveau champ
     */
    void modifierChamp(QString champ);

    /*!
     *  Signal qui permet de modifier la couleur du champ du FenBouton
     *
     *  \param policeCouleur : la nouvelle couleur
     */
    void modifierPoliceCouleur(QString policeCouleur);

    /*!
     *  Signal qui permet de modifier la taille du texte du champ du FenBouton
     *
     *  \param policeTaille : la nouvelle taille de la police
     */
    void modifierPoliceTaille(int policeTaille);
};

#endif // FENBOUTON_H
