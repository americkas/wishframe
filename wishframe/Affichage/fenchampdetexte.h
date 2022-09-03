#ifndef FENCHAMPDETEXTE_H
#define FENCHAMPDETEXTE_H

/*!
 * \file fenchampdetexte.h
 * \brief Classe FenChampDeTexte
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include <QLabel>

/*! \class FenChampDeTexte
  * \brief classe representant l'affichage d'un ChampDeTexte
  *
  *  La classe gere la structure d'un FenChampDeTexte
  *  qui correspond a l'affichage d'un ChampDeTexte
  */
class FenChampDeTexte : public QLabel
{
    Q_OBJECT

public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe FenChampDeTexte
     *
     *  \param parent : le conteneur du FenChampDeTexte
     *  \param champ : le texte écrit dans le widget
     *  \param policeCouleur : la couleur du texte dans le widget
     *  \param policeTaille : la police du texte dans le widget
     *  \param largeur : la largeur du widget
     *  \param hauteur : la hauteur du widget
     */
    explicit FenChampDeTexte(QWidget *parent = nullptr, QString nom = "voila", QString policeCouleur= "rgb(0,0,0)", int PoliceTaille = 11, int largeur = 100, int hauteur = 50);

    /*!
     *  \brief Recupere les donnees du FenChampDeTexte sous format de balises
     *
     *  Methode qui permet de recupere les donnees du FenChampDeTexte
     *  avec des balises semblables au format Html, cela va
     *  servir a sauvegarder les FenChampDeTextes
     *
     *  \return : le string finale avec les différentes balises
     */
    QString obtenirInfoString();

signals:
    /*!
     *  Signal qui permet de modifier le champ du FenChampDeTexte
     *
     *  \param champ : le nouveau champ
     */
    void modifierChamp(QString champ);

    /*!
     *  Signal qui permet de modifier la couleur du champ du FenChampDeTexte
     *
     *  \param policeCouleur : la nouvelle couleur
     */
    void modifierPoliceCouleur(QString policeCouleur);

    /*!
     *  Signal qui permet de modifier la taille du texte du champ du FenChampDeTexte
     *
     *  \param policeTaille : la nouvelle taille de la police
     */
    void modifierPoliceTaille(int policeTaille);
};

#endif // FENCHAMPDETEXTE_H
