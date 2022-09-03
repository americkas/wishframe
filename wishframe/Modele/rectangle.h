#ifndef RECTANGLE_H
#define RECTANGLE_H

/*!
 * \file rectangle.h
 * \brief Classe Rectangle
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include "Modele/composant.h"

/*! \class Rectangle
  * \brief classe representant un rectangle
  *
  *  La classe gere la structure d'un rectangle
  */
class Rectangle : public Composant
{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Rectangle
    */
    Rectangle();

    /*!
     *  \brief Changement de la courbure du bord
     *
     *  Methode qui permet de modifier le rayon
     *  de courbure du bord du rectangle
     *
     *  \param radius : le nouveau rayon de courbure
     */
    void changerBordRadius(int radius);

    /*!
     *  \brief Changement de la couleur du bord
     *
     *  Methode qui permet de modifier la couleur
     *  du bord du rectangle
     *
     *  \param couleur : le nouvelle couleur du bord
     */
    void changerBordCouleur(QString couleur);

    /*!
     *  \brief Recupere le rayon de courbure
     *
     *  Methode qui permet de recuperer
     *  le rayon de courbure du rectangle
     *
     *  \return le rayon de courbure
     */
    int recupererBordRadius();

    /*!
     *  \brief Recupere la couleur du bord
     *
     *  Methode qui permet de recuperer
     *  la couleur du bord du rectangle
     *
     *  \return la couleur du bord
     */
    QString recupererBordCouleur();

    /*!
     *  \brief Renvoie le nom de la classe
     *
     *  Methode qui permet de renvoyer le nom
     *  de la classe, ie "Rectangle"
     *
     *  \return : "Rectangle"
     */
    QString classname();
private:
    int bordRadius; /*!< rayon de courbure*/
    QString bordCouleur; /*!< couleur du bord*/

};

#endif // RECTANGLE_H
