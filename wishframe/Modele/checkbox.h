#ifndef CHECKBOX_H
#define CHECKBOX_H

/*!
 * \file checkbox.h
 * \brief Classe Checkbox
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include "Modele/composant.h"

/*! \class Checkbox
  * \brief classe representant une checkbox
  *
  *  La classe gere la structure d'une checkbox
  */
class Checkbox : public Composant
{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Checkbox
     */
    Checkbox();

    /*!
     *  \brief Inverse la valeur du check
     *
     *  Methode qui permet de mettre le check
     *  a true si il est false et inversement
     */
    void check();

    /*!
     *  \brief Changement du nom
     *
     *  Methode qui permet de modifier le nom
     *  de la Checkbox
     *
     *  \param nom : le nouveau nom
     */
    void modifierNom(QString nom);

    /*!
     *  \brief Recupere le nom
     *
     *  Methode qui permet de recuperer
     *  le nom de la Checkbox
     *
     *  \return le nom
     */
    QString recupererNom();

    /*!
     *  \brief Recupere le check
     *
     *  Methode qui permet de savoir
     *  si la Checkbox est cochée ou non
     *
     *  \return le booléen check
     */
    bool recupererChecked();

    /*!
     *  \brief Renvoie le nom de la classe
     *
     *  Methode qui permet de renvoyer le nom
     *  de la classe, ie "Checkbox"
     *
     *  \return "Checkbox"
     */
    QString classname();
private:
    QString nom; /*!< nom de la Checkbox*/
    bool checked; /*!< param qui détermine si la Checkbox est cochée ou non*/
};

#endif // CHECKBOX_H
