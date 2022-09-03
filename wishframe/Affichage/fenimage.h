#ifndef FENIMAGE_H
#define FENIMAGE_H

/*!
 * \file fenimage.h
 * \brief Classe FenImage
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include <QLabel>

/*! \class FenImage
  * \brief classe representant l'affichage d'une image
  *
  *  La classe gere la structure d'un FenImage
  *  qui correspond a l'affichage d'une Image
  */
class FenImage : public QLabel
{
    Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe FenImage
     *
     *  \param parent : le conteneur du FenImage
     *  \param lien : le lien de l'image affichée dans le widget
     */
    explicit FenImage(QWidget *parent = nullptr, QString lien = ":/images/boat.png");

    /*!
     *  \brief Recupere les donnees du FenImage sous format de balises
     *
     *  Methode qui permet de recupere les donnees du FenImage
     *  avec des balises semblables au format Html, cela va
     *  servir a sauvegarder les FenImages
     *
     *  \return : le string finale avec les différentes balises
     */
    QString obtenirInfoString();
signals:
    /*!
     *  Signal qui permet de modifier le lien de l'image
     *
     *  \param lien : le nouveau lien
     */
    void modifierLienImg2(QString lien);
private:
    QString lien; /*!< le lien de l'image*/
};

#endif // FENIMAGE_H
