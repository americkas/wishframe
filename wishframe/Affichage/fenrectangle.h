#ifndef FENRECTANGLE_H
#define FENRECTANGLE_H

/*!
 * \file fenrectangle.h
 * \brief Classe FenRectangle
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include <QLabel>

/*! \class FenRectangle
  * \brief classe representant l'affichage d'un Rectangle
  *
  *  La classe gere la structure d'un FenRectangle
  *  qui correspond a l'affichage d'un Rectangle
  */
class FenRectangle : public QLabel
{
    Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Rectangle
     *
     *  \param parent : le conteneur du FenRectangle
     *  \param bordRadius : le rayon de courbure du rectangle du widget
     *  \param bordCouleur : la couleur du bord du rectangle du widget
     *  \param largeur : la largeur du widget
     *  \param hauteur : la hauteur du widget
     */
    explicit FenRectangle(QWidget *parent = nullptr, int bordRadius = 25, QString bordCouleur = "red", int largeur = 200, int hauteur = 70);

    /*!
     *  \brief Recupere les donnees du FenRectangle sous format de balises
     *
     *  Methode qui permet de recupere les donnees du FenRectangle
     *  avec des balises semblables au format Html, cela va
     *  servir a sauvegarder les FenRectangles
     *
     *  \return : le string finale avec les différentes balises
     */
    QString obtenirInfoString();
signals:
    /*!
     *  Signal qui permet de modifier le borderRadius du widget
     *
     *  \param radius : le nouveau rayon de courbure
     */
    void changerBordRadius(int radius);

    /*!
     *  Signal qui permet de modifier la couleur du bord du widget
     *
     *  \param couleur : la nouvelle couleur du bord
     */
    void changerBordCouleur(QString couleur);
};

#endif // FENRECTANGLE_H
