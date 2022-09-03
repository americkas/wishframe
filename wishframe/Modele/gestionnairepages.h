#ifndef GESTIONNAIREPAGES_H
#define GESTIONNAIREPAGES_H

/*!
 * \file gestionnairepages.h
 * \brief Classe GestionnairePages
 * \author Nicolas Mir, Aymeric Keyewa
 * \version 1
 */
#include "Modele/page.h"

/*! \class GestionnairePages
  * \brief classe representant le gestionnaires de pages
  *
  *  La classe gere la structure du gestionnaire de pages
  *  qui fait office de controlleur pour l'edition des pages
  */
class GestionnairePages: public QObject
{
    Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe GestionnairePages
     */
    GestionnairePages();

    /*!
     *  \brief Creation d'une page (un onglet)
     *
     *  Methode qui permet de creer une nouvelle page
     *
     *  \param type : le type de la page (ses dimensions)
     */
    void creerPage(QString type);

    /*!
     *  \brief Changement des dimensions d'une page
     *
     *  Methode qui permet de modifier les dimensions
     *  d'une page
     *
     *  \param page : la page a modifier
     *  \param hauteur : la nouvelle hauteur de la page
     *  \param largeur : la nouvelle largeur de la page
     */
    void changerTaillePage(Page * page, int hauteur, int largeur);

    /*!
     *  \brief Recuperation de la page a un certain indice
     *
     *  Methode qui permet de recuperer une page
     *  dans la liste des pages par rapport a un
     *  indice donne en entree
     *
     *  \param index : l'indice de la page
     *  \return : la page correspondant
     */
    Page * page(int index);

    /*!
     *  \brief Sauvegarder une page dans un fichier
     *
     *  Methode qui permet de sauvegarder une page
     *  dans un fichier a partir de son lien
     *
     *  \param page : la page a sauvegarder
     *  \param lien : le lien du fichier dans lequel sauvegarder
     */
    void sauvegarderPage(Page * page, QString lien);

    /*!
     *  \brief Charger une page
     *
     *  Methode qui permet de renvoyer une page
     *  a partir d'un lien de fichier existant et dans le bon
     *  format
     *
     *  \param lien : le lien du fichier a partir duquel on charge la page
     *  \return : la page renvoyée
     */
    Page * chargerPage(QString lien);

public slots:
    /**
       * \brief Slot pour la suppression d'une page
       *
       * Slot qui permet de supprimer une page de la liste des pages
       */
    void supprPage(Page * page);


private:
    QList<Page*> pages; /*!< la liste des pages/onglets*/
};

#endif // GESTIONNAIREPAGES_H
