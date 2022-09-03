#ifndef LISTEDEROULANTE_H
#define LISTEDEROULANTE_H

/*!
 * \file listederoulante.h
 * \brief Classes ElementListe et ListeDeroulante
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include "Modele/composant.h"

/*! \class ElementListe
  * \brief classe representant un choix d'une liste déroulante
  *
  *  La classe gere la structure d'un choix d'une liste déroulante
  */
class ElementListe : public QObject
{

Q_OBJECT
public: 
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe ElementListe
     *
     *  \param nom : le texte qui fera office de choix
     */
    ElementListe(QString nom);

    /*!
     *  \brief Changement du nom
     *
     *  Methode qui permet de modifier le nom
     *  du choix de la liste
     *
     *  \param nom : le nouveau nom du choix
     */
    void modifierNom(QString nom);

    /*!
     *  \brief Recupere le nom
     *
     *  Methode qui permet de recuperer
     *  le nom de ElementListe
     *
     *  \return le nom
     */
    QString recupererNom();
private:
    QString nom; /*!< nom de ElementListe*/

};

/*! \class ListeDeroulante
  * \brief classe representant une liste déroulante
  *
  *  La classe gere la structure d'une liste déroulante
  */
class ListeDeroulante : public Composant
{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe ListeDeroulante
     */
    ListeDeroulante();

    /*!
     *  \brief Ajout d'un choix
     *
     *  Methode qui permet d'ajouter un
     *  choix dans la liste déroulante
     *
     *  \param nom : le nom d'une choix à ajouter
     */
    void ajouterElement(QString nom);

    /*!
     *  \brief Recupere la liste des éléments qui forment la liste
     *
     *  Methode qui permet de recuperer
     *  les ElementListe qui sont les choix d'une
     *  liste déroulante
     *
     *  \return la liste des choix
     */
    QList<ElementListe*> recupererElements();

    /*!
     *  \brief Renvoie le nom de la classe
     *
     *  Methode qui permet de renvoyer le nom
     *  de la classe, ie "ListeDeroulante"
     *
     *  \return "ListeDeroulante"
     */
    QString classname();
private:
    QList<ElementListe*> elements; /*!< liste des choix*/
};

#endif // LISTEDEROULANTE_H
