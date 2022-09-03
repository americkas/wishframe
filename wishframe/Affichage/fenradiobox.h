#ifndef FENRADIOBOX_H
#define FENRADIOBOX_H

/*!
 * \file fenradiobox.h
 * \brief Classe FenRadioBox
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include <QRadioButton>

/*! \class FenRadioBox
  * \brief classe representant l'affichage d'une RadioBox
  *
  *  La classe gere la structure d'un FenRadioBox
  *  qui correspond a l'affichage d'une RadioBox
  */
class FenRadioBox : public QRadioButton
{
    Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe FenRadioBox
     *
     *  \param parent : le conteneur du FenRadioBox
     *  \param name : le nom de la RadioBox du widget
     *  \param checked : booléen qui exprime l'état coché ou non de la RadioBox du widget
     *  \param largeur : la largeur du FenRadioBox
     *  \param hauteur : la hauteur du FenRadioBox
     */
    explicit FenRadioBox(QWidget *parent = nullptr, QString name="radiohead", bool checked=false, int largeur = 100, int hauteur = 50);

    /*!
     *  \brief Recupere les donnees du FenRadioBox sous format de balises
     *
     *  Methode qui permet de recupere les donnees du FenRadioBox
     *  avec des balises semblables au format Html, cela va
     *  servir a sauvegarder les FenRadioBoxes
     *
     *  \return : le string finale avec les différentes balises
     */
    QString obtenirInfoString();
signals:
    /*!
     *  Signal qui permet de cocher ou decocher la FenRadioBox
     */
    void modifierCheck();

    /*!
     *  Signal qui permet de modifier le nom de la FenRadioBox
     *
     *  \param nom : le nouveau nom
     */
    void modifierNom(QString nom);
};

#endif // FENRADIOBOX_H
