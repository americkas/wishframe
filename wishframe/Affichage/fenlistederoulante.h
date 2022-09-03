#ifndef FENLISTEDEROULANTE_H
#define FENLISTEDEROULANTE_H

/*!
 * \file fenlistederoulante.h
 * \brief Classe FenListeDeroulante
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include <QComboBox>
#include "Modele/listederoulante.h"

/*! \class FenListeDeroulante
  * \brief classe representant l'affichage d'une ListeDeroulante
  *
  *  La classe gere la structure d'un FenListeDeroulante
  *  qui correspond a l'affichage d'une ListeDeroulante
  */
class FenListeDeroulante : public QComboBox
{
    Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe FenListeDeroulante
     *
     *  \param parent : le conteneur du FenListeDeroulante
     *  \param elements : la liste des choix du widget de la liste deroulante
     */
    explicit FenListeDeroulante(QWidget *parent = nullptr, QList<ElementListe*> elements = QList<ElementListe*>() << new ElementListe("pillule bleue") << new ElementListe("pillule rouge") << new ElementListe("pillule verte"));

    /*!
     *  \brief Recupere les donnees du FenListeDeroulante sous format de balises
     *
     *  Methode qui permet de recupere les donnees du FenListeDeroulante
     *  avec des balises semblables au format Html, cela va
     *  servir a sauvegarder les FenListeDeroulantes
     *
     *  \return : le string finale avec les différentes balises
     */
    QString obtenirInfoString();

signals:
    /*!
     *  Signal qui permet de modifier le nom d'un element de la FenListeDeroulante
     *
     *  \param nom : le nouveau nom
     *  \param element : l'element que l'on modifie
     */
    void modifierNom(QString nom,ElementListe * element);
};

#endif // FENLISTEDEROULANTE_H
