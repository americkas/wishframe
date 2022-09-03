#ifndef IMAGE_H
#define IMAGE_H

/*!
 * \file image.h
 * \brief Classe Image
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include "Modele/rectangle.h"

/*! \class Image
  * \brief classe representant une image
  *
  *  La classe gere la structure d'une image
  */
class Image : public Rectangle
{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Image
     */
    Image();

    /*!
     *  \brief Changement d'image
     *
     *  Methode qui permet de changer le lien
     *  de l'image (et donc l'image)
     *
     *  \param lien : le nouveau lien
     */
    void modifierLienImg(QString lien);

    /*!
     *  \brief Recuperer le lien de l'image
     *
     *  Methode qui recupere
     *  le lien de l'image
     *
     *  \return lien : le lien de l'image
     */
    QString recupererLienImg();

    /*!
     *  \brief Renvoie le nom de la classe
     *
     *  Methode qui permet de renvoyer le nom
     *  de la classe, ie "Image"
     *
     *  \return "Image"
     */
    QString classname();
private:
    QString lienImg; /*!< lien de l'image*/
};

#endif // IMAGE_H
