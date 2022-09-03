#ifndef RADIOBOX_H
#define RADIOBOX_H

/*!
 * \file radiobox.h
 * \brief Classes RadioBoxSingle et Radiobox
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include "Modele/composant.h"

/*! \class RadioboxSingle
  * \brief classe representant une radiobox simple
  *
  *  La classe gere la structure d'une radiobox simple
  */
class RadioboxSingle : public QObject
{
Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe RadioboxSingle
     */
    RadioboxSingle();

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
     *  de la RadioboxSingle
     *
     *  \param nom : le nouveau nom
     */
    void modifierNom(QString nom);

    /*!
     *  \brief Récupération du nom
     *
     *  Methode qui permet de récupérer
     *  le nom de la RadioboxSingle
     *
     *  \return : le nom
     */
    QString recupererNom();

    /*!
     *  \brief Récupération du booléen isChecked
     *
     *  Methode qui permet de savoir si
     *  le composant RadioboxSingle est cochée
     *  ou non
     *
     *  \return : le booléen
     */
    bool recupererIsChecked();
private:
    QString nom; /*!< nom de la RadioboxSingle*/
    bool isChecked; /*!< param qui détermine si la RadioboxSingle est cochée ou non*/
};


/*! \class Radiobox
  * \brief classe representant une radiobox
  *
  *  La classe gere la structure d'un ensemble de radiobox
  */
class Radiobox : public Composant
{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Radiobox
     */
    Radiobox();

    /*!
     *  \brief Ajout d'un element
     *
     *  Methode qui permet d'ajouter une
     *  RadioboxSingle a la Radiobox
     *
     *  \param nom: le nom de la RadioboxSingle
     *  \param isChecked: le booléen isChecked de RadioboxSingle
     */
    void ajouterElement(QString nom, bool isChecked);

    /*!
     *  \brief Recuperation de la liste des RadioboxSingle
     *
     *  Methode qui permet de recuperer la liste des
     *  RadioboxSingle qui forment la Radiobox
     *
     *  \return : la liste des RadioboxSingle
     */
    QList<RadioboxSingle*> recupererRadioBoxes();

    /*!
     *  \brief Renvoie le nom de la classe
     *
     *  Methode qui permet de renvoyer le nom
     *  de la classe, ie "Radiobox"
     *
     *  \return : "Radiobox"
     */
    QString classname();
private:
    QList<RadioboxSingle*> radioboxes; /*!< liste des RadioboxSingle qui composent la Radiobox*/
};

#endif // RADIOBOX_H
