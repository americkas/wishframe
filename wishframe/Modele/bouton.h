#ifndef BOUTON_H
#define BOUTON_H

/*!
 * \file bouton.h
 * \brief Classe Bouton
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include "Modele/rectangle.h"

/*! \class Bouton
  * \brief classe representant un bouton
  *
  *  La classe gere la structure d'un bouton
  */
class Bouton : public Rectangle
{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Bouton
     */
    Bouton();

    /*!
     *  \brief Changement de la police
     *
     *  Methode qui permet de modifier la police
     *  du texte du bouton
     *
     *  \param taille : la nouvelle taille du texte
     */
    void changerPoliceTaille (int taille);

    /*!
     *  \brief Changement de la couleur du texte
     *
     *  Methode qui permet de modifier la couleur
     *  du texte du bouton
     *
     *  \param couleur : la nouvelle couleur du texte
     */
    void changerPoliceCouleur (QString couleur);

    /*!
     *  \brief Changement du texte
     *
     *  Methode qui permet de modifier le texte
     *  du bouton
     *
     *  \param champ : le nouveau texte
     */
    void modifierChamp(QString champ);

    /*!
     *  \brief Recupere le texte
     *
     *  Methode qui permet de recuperer
     *  le texte du bouton
     *
     *  \return le champ de texte du bouton
     */
    QString recupererChamp();

    /*!
     *  \brief Recupere la couleur du texte
     *
     *  Methode qui permet de recuperer
     *  le couleur du texte du bouton
     *
     *  \return la couleur du texte du bouton
     */
    QString recupererPoliceCouleur();

    /*!
     *  \brief Recupere la police du texte
     *
     *  Methode qui permet de recuperer
     *  le police du texte du bouton
     *
     *  \return la police du texte du bouton
     */
    int recupererPoliceTaille();

    /*!
     *  \brief Renvoie le nom de la classe
     *
     *  Methode qui permet de renvoyer le nom
     *  de la classe, ie "Bouton"
     *
     *  \return "Bouton"
     */
    QString classname();

private:
    QString champ; /*!< texte dans le bouton*/
    QString policeCouleur; /*!< couleur du texte sous format rgb*/
    int policeTaille; /*!< police du texte*/
};

#endif // BOUTON_H
