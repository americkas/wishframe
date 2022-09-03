#ifndef CHAMPDETEXTE_H
#define CHAMPDETEXTE_H

/*!
 * \file champdetexte.h
 * \brief Classe ChampDeTexte
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include "Modele/rectangle.h"

/*! \class ChampDeTexte
  * \brief classe representant un champ de texte
  *
  *  La classe gere la structure d'un champ de texte
  */
class ChampDeTexte : public Rectangle
{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe ChampDeTexte
     */
    ChampDeTexte();

    /*!
     *  \brief Changement de la police
     *
     *  Methode qui permet de modifier la police
     *  du texte du champ
     *
     *  \param taille : la nouvelle taille du texte
     */
    void changerPoliceTaille (int taille);

    /*!
     *  \brief Changement de la couleur du texte
     *
     *  Methode qui permet de modifier la couleur
     *  du texte du champ
     *
     *  \param couleur : la nouvelle couleur du texte
     */
    void changerPoliceCouleur (QString couleur);

    /*!
     *  \brief Changement du texte
     *
     *  Methode qui permet de modifier le texte
     *  du champ
     *
     *  \param champ : le nouveau texte
     */
    void modifierChamp(QString champ);

    /*!
     *  \brief Recupere le texte
     *
     *  Methode qui permet de recuperer
     *  le texte du champ
     *
     *  \return le texte
     */
    QString recupererChamp();

    /*!
     *  \brief Recupere la couleur du texte
     *
     *  Methode qui permet de recuperer
     *  le couleur du texte du champ
     *
     *  \return la couleur du texte
     */
    QString recupererPoliceCouleur();

    /*!
     *  \brief Recupere la police du texte
     *
     *  Methode qui permet de recuperer
     *  le police du texte du champ
     *
     *  \return la police du texte
     */
    int recupererPoliceTaille();

    /*!
     *  \brief Renvoie le nom de la classe
     *
     *  Methode qui permet de renvoyer le nom
     *  de la classe, ie "ChampDeTexte"
     *
     *  \return "ChampDeTexte"
     */
    QString classname();
private:
    QString champ; /*!< texte du champ*/
    QString policeCouleur; /*!< couleur du texte*/
    int policeTaille; /*!< police du texte*/
};

#endif // CHAMPDETEXTE_H
