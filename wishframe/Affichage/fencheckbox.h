#ifndef FENCHECKBOX_H
#define FENCHECKBOX_H

/*!
 * \file fencheckbox.h
 * \brief Classe FenCheckBox
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include <QCheckBox>

/*! \class FenCheckBox
  * \brief classe representant l'affichage d'une Checkbox
  *
  *  La classe gere la structure d'un FenCheckBox
  *  qui correspond a l'affichage d'un CheckBox
  */
class FenCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe FenCheckBox
     *
     *  \param parent : le conteneur du FenCheckBox
     *  \param nom : le nom de la Checkbox du widget
     *  \param checked : booléen qui exprime l'état coché ou non de la Checkbox du widget
     *  \param largeur : la largeur du widget
     *  \param hauteur : la hauteur du widget
     */
    explicit FenCheckBox(QWidget *parent = nullptr, QString nom="nom", bool checked=false, int largeur = 100, int hauteur = 50);

    /*!
     *  \brief Recupere les donnees du FenCheckbox sous format de balises
     *
     *  Methode qui permet de recupere les donnees du FenCheckbox
     *  avec des balises semblables au format Html, cela va
     *  servir a sauvegarder les FenCheckboxes
     *
     *  \return : le string finale avec les différentes balises
     */
    QString obtenirInfoString();
signals:
    /*!
     *  Signal qui permet de modifier le nom du FenCheckBox
     *
     *  \param nom : le nouveau nom
     */
    void modifierNom (QString nom);

    /*!
     *  Signal qui permet de cocher ou decocher le FenCheckBox
     *
     *  \param checked : le booleen a inverser
     */
    void modifierCheck (bool checked);
};

#endif // FENCHECKBOX_H
