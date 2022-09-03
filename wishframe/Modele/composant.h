#ifndef COMPOSANT_H
#define COMPOSANT_H

/*!
 * \file composant.h
 * \brief Classe Composant
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include <QObject>
#include <QPoint>

/*! \class Composant
  * \brief classe representant un composant
  *
  *  La classe gere la structure d'un composant de la page
  */
class Composant : public QObject
{
    Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Composant
     *
     *  \param parent : le conteneur du composant
     */
    Composant(QObject *parent = nullptr);

    /*!
     *  \brief Changement des dimensions du composant
     *
     *  Methode qui permet de modifier la hauteur
     *  et la largeur du composant
     *
     *  \param largeur : la nouvelle largeur
     *  \param hauteur : la nouvelle hauteur
     */
    void changerTailleComposant(int largeur, int hauteur);

    /*!
     *  \brief Changement de la position du composant
     *
     *  Methode qui permet de modifier la position
     *  du composant dans la page
     *
     *  \param position : la nouvelle position
     */
    void modifierPosition(QPoint position);

    /*!
     *  \brief Recuperer la largeur du composant
     *
     *  Methode qui permet de recuperer la largeur
     *  du composant
     *
     *  \return : la largeur du composant
     */
    int recupererLargeur();

    /*!
     *  \brief Recuperer la hauteur du composant
     *
     *  Methode qui permet de recuperer la hauteur
     *  du composant
     *
     *  \return : la hauteur du composant
     */
    int recupererHauteur();

    /*!
     *  \brief Recuperer la position du composant
     *
     *  Methode qui permet de recuperer la position
     *  du composant
     *
     *  \return : la position du composant
    */
    QPoint recupererPosition();

    /*!
     *  \brief Renvoie le nom de la classe
     *
     *  Methode qui permet de renvoyer le nom
     *  de la classe, ie "Composant"
     *
     *  \return "Composant"
     */
    virtual QString classname();

private:
    int largeur; /*!< largeur du composant*/
    int hauteur; /*!< hauteur du composant */
    QPoint position; /*!< position du composant */
};


#endif // COMPOSANT_H
