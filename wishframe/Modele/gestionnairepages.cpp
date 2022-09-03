#include "gestionnairepages.h"
#include <QFile>
#include <QTextStream>

GestionnairePages::GestionnairePages()
{

}

void GestionnairePages::creerPage(QString type){
    Page * page = new Page(type);
    pages.append(page);
}
void GestionnairePages::supprPage(Page * page){
    this->pages.removeOne(page);
}

Page * GestionnairePages::page(int index){
    return pages.value(index);
}

QString composants_commun(QString texte, int hauteur, int largeur, QPoint position){
    texte.append("<position>"+QString::number(position.x())+";"+QString::number(position.y())+"</position>");
    texte.append("<hauteur>"+QString::number(hauteur)+"</hauteur>");
    texte.append("<largeur>"+QString::number(largeur)+"</largeur>");
    return texte;
}

void GestionnairePages::sauvegarderPage(Page * page,QString lien){
    QString texte = "<page>";
    QList<Composant*> composants = page->recupererComposants();

    for(int i=0; i<composants.size(); i++){
        int hauteur = composants[i]->recupererHauteur();
        int largeur = composants[i]->recupererLargeur();
        QPoint position = composants[i]->recupererPosition();

        QString type = composants[i]->classname();

        if(type == "Bouton"){
            Bouton * b = static_cast<Bouton*>(composants[i]);
            texte.append("<bouton>");
            texte.append(composants_commun(texte,hauteur,largeur,position));
            texte.append("<champ>"+b->recupererChamp()+"</champ>");
            texte.append("<policeCouleur>"+b->recupererPoliceCouleur()+"</policeCouleur>");
            texte.append("<policeTaille>"+QString::number(b->recupererPoliceTaille())+"</policeTaille>");
            texte.append("<bordCouleur>"+b->recupererBordCouleur()+"</bordCouleur>");
            texte.append("<bordRadius>"+QString::number(b->recupererBordRadius())+"</bordRadius>");
            texte.append("</bouton>");
        } else if(type == "Rectangle"){
            Rectangle * b = static_cast<Rectangle*>(composants[i]);
            texte.append("<rectangle>");
            texte.append(composants_commun(texte,hauteur,largeur,position));
            texte.append("<bordCouleur>"+b->recupererBordCouleur()+"</bordCouleur>");
            texte.append("<bordRadius>"+QString::number(b->recupererBordRadius())+"</bordRadius>");
            texte.append("</rectangle>");
        } else if (type == "ChampDeTexte"){
            ChampDeTexte * b = static_cast<ChampDeTexte*>(composants[i]);
            texte.append("<champdetexte>");
            texte.append(composants_commun(texte,hauteur,largeur,position));
            texte.append("<champ>"+b->recupererChamp()+"</champ>");
            texte.append("<policeCouleur>"+b->recupererPoliceCouleur()+"</policeCouleur>");
            texte.append("<policeTaille>"+QString::number(b->recupererPoliceTaille())+"</policeTaille>");
            texte.append("<bordCouleur>"+b->recupererBordCouleur()+"</bordCouleur>");
            texte.append("<bordRadius>"+QString::number(b->recupererBordRadius())+"</bordRadius>");
            texte.append("</champdetexte>");
        } else if (type == "Image") {
            Image * b = static_cast<Image*>(composants[i]);
            texte.append("<image>");
            texte.append(composants_commun(texte,hauteur,largeur,position));
            texte.append("<lien>"+b->recupererLienImg()+"</lien>");
            texte.append("<bordCouleur>"+b->recupererBordCouleur()+"</bordCouleur>");
            texte.append("<bordRadius>"+QString::number(b->recupererBordRadius())+"</bordRadius>");
            texte.append("</image>");
        } else if (type == "ListeDeroulante") {
            ListeDeroulante * b = static_cast<ListeDeroulante*>(composants[i]);
            texte.append("<listederoulante>");
            texte.append(composants_commun(texte,hauteur,largeur,position));

            foreach(ElementListe * element, b->recupererElements()){
               texte.append("<nom>"+element->recupererNom()+"</nom>");
            }

            texte.append("</listederoulante>");
        } else if (type == "Radiobox") {
            Radiobox * b = static_cast<Radiobox*>(composants[i]);
            texte.append("<radiobox>");
            texte.append(composants_commun(texte,hauteur,largeur,position));

            foreach(RadioboxSingle * single, b->recupererRadioBoxes()){
               texte.append("<nom>"+single->recupererNom()+"</nom>");
               if (single->recupererIsChecked()){
                texte.append("<ischecked>true</ischecked");
               }
               else {
                 texte.append("<ischecked>false</ischecked");
               }
            }

            texte.append("</radiobox>");
        } else if (type == "Checkbox") {
            Checkbox * b = static_cast<Checkbox*>(composants[i]);
            texte.append("<checkbox>");
            texte.append(composants_commun(texte,hauteur,largeur,position));
            texte.append("<nom>"+b->recupererNom()+"</nom>");
            if (b->recupererChecked()){
                texte.append("<checked>true</checked>");
            }
            else {
                texte.append("<checked>false</checked>");
            }
            texte.append("</checkbox>");
        } else {
            return ;
        }
    }
    texte.append("</page>");

    QFile file(lien);

    if (!file.open(QIODevice::ReadWrite) ){
        file.close();
    }
    else {
        QTextStream out( &file );
        out << texte;
        file.close();
    }
}

Page * GestionnairePages::chargerPage(QString lien){
    QFile file(lien);
    Page * page = new Page();
    QTextStream flux(&file);
    QString texte = flux.readAll();

    QRegExp regBouton("<bouton>.*</bouton>");
    QRegExp regImage("<image>.*</image>");
    QRegExp regRectangle("<rectangle>.*</rectangle>");
    QRegExp regListe("<listederoulante>.*</listederoulante>");
    QRegExp regRadiobox("<radiobox>.*</radiobox>");
    QRegExp regCheckbox("<checkbox>.*</checkbox>");
    QRegExp regChampDeTexte("<champdetexte>.*</champdetexte>");

    QRegExp regChamp("<champ>.*</champ>");
    QRegExp regLien("<lien>.*</lien>");
    QRegExp regIsChecked("<ischecked>.*</ischecked>");
    QRegExp regChecked("<checked>.*</checked>");
    QRegExp regBordCouleur("<bordCouleur>.*</bordCouleur>");
    QRegExp regBordRadius("<bordRadius>.*</bordRadius>");
    QRegExp regPoliceCouleur("<policeCouleur>.*</policeCouleur>");
    QRegExp regPoliceTaille("<policeTaille>.*</policeTaille>");
    QRegExp regNom("<nom>.*</nom>");
    QRegExp regPosition("<position>.*</position>");
    QRegExp regHauteur("<hauteur>.*</hauteur>");
    QRegExp regLargeur("<largeur>.*</largeur>");

    texte.replace("<page>", "");
    texte.replace("</page>", "");

    while(!texte.isEmpty()){
        regBouton.indexIn(texte);
        regImage.indexIn(texte);
        regRectangle.indexIn(texte);
        regListe.indexIn(texte);
        regRadiobox.indexIn(texte);
        regCheckbox.indexIn(texte);
        regChampDeTexte.indexIn(texte);

        if(!regBouton.cap(0).isEmpty()){
            QString boutonHtml = regBouton.cap(0);
            regChamp.indexIn(boutonHtml);
            regPosition.indexIn(boutonHtml);
            regBordCouleur.indexIn(boutonHtml);
            regBordRadius.indexIn(boutonHtml);
            regPoliceCouleur.indexIn(boutonHtml);
            regPoliceTaille.indexIn(boutonHtml);
            regHauteur.indexIn(boutonHtml);
            regLargeur.indexIn(boutonHtml);
            Bouton * bouton = new Bouton();
            bouton->changerTailleComposant(regLargeur.cap(0).toInt(),regHauteur.cap(0).toInt());
            bouton->changerBordCouleur(regBordCouleur.cap(0));
            bouton->changerBordRadius(regBordRadius.cap(0).toInt());
            bouton->modifierChamp(regChamp.cap(0));
            bouton->changerPoliceCouleur(regPoliceCouleur.cap(0));
            bouton->changerPoliceTaille(regPoliceTaille.cap(0).toInt());
            bouton->modifierPosition(QPoint(regPosition.cap(0).split(";")[0].toInt(),regPosition.cap(0).split(";")[1].toInt()));

            page->ajouterComposant(bouton);
            texte.replace(regBouton.cap(0),"");
        }

        if(!regRectangle.cap(0).isEmpty()){
            QString rectangleHtml = regRectangle.cap(0);
            regPosition.indexIn(rectangleHtml);
            regBordCouleur.indexIn(rectangleHtml);
            regBordRadius.indexIn(rectangleHtml);
            regHauteur.indexIn(rectangleHtml);
            regLargeur.indexIn(rectangleHtml);
            Rectangle * rectangle = new Rectangle();
            rectangle->changerTailleComposant(regLargeur.cap(0).toInt(),regHauteur.cap(0).toInt());
            rectangle->changerBordCouleur(regBordCouleur.cap(0));
            rectangle->changerBordRadius(regBordRadius.cap(0).toInt());
            rectangle->modifierPosition(QPoint(regPosition.cap(0).split(";")[0].toInt(),regPosition.cap(0).split(";")[1].toInt()));

            page->ajouterComposant(rectangle);
            texte.replace(regRectangle.cap(0),"");
        }

        if(!regImage.cap(0).isEmpty()){
            QString imageHtml = regImage.cap(0);
            regPosition.indexIn(imageHtml);
            regBordCouleur.indexIn(imageHtml);
            regBordRadius.indexIn(imageHtml);
            regHauteur.indexIn(imageHtml);
            regLargeur.indexIn(imageHtml);
            regLien.indexIn(imageHtml);
            Image * image = new Image();
            image->changerTailleComposant(regLargeur.cap(0).toInt(),regHauteur.cap(0).toInt());
            image->changerBordCouleur(regBordCouleur.cap(0));
            image->changerBordRadius(regBordRadius.cap(0).toInt());
            image->modifierPosition(QPoint(regPosition.cap(0).split(";")[0].toInt(),regPosition.cap(0).split(";")[1].toInt()));
            image->modifierLienImg(regLien.cap(0));

            page->ajouterComposant(image);
            texte.replace(regImage.cap(0),"");
        }

        if(!regChampDeTexte.cap(0).isEmpty()){
            QString champHtml = regChampDeTexte.cap(0);
            regPosition.indexIn(champHtml);
            regBordCouleur.indexIn(champHtml);
            regBordRadius.indexIn(champHtml);
            regHauteur.indexIn(champHtml);
            regLargeur.indexIn(champHtml);
            regChamp.indexIn(champHtml);
            regPoliceCouleur.indexIn(champHtml);
            regPoliceTaille.indexIn(champHtml);

            ChampDeTexte * champDeTexte = new ChampDeTexte();
            champDeTexte->changerTailleComposant(regLargeur.cap(0).toInt(),regHauteur.cap(0).toInt());
            champDeTexte->changerBordCouleur(regBordCouleur.cap(0));
            champDeTexte->changerBordRadius(regBordRadius.cap(0).toInt());
            champDeTexte->modifierPosition(QPoint(regPosition.cap(0).split(";")[0].toInt(),regPosition.cap(0).split(";")[1].toInt()));
            champDeTexte->modifierChamp(regChamp.cap(0));
            champDeTexte->changerPoliceCouleur(regPoliceCouleur.cap(0));
            champDeTexte->changerPoliceTaille(regPoliceTaille.cap(0).toInt());

            page->ajouterComposant(champDeTexte);
            texte.replace(regChampDeTexte.cap(0),"");
        }

        if(!regCheckbox.cap(0).isEmpty()){
            QString checkboxHtml = regCheckbox.cap(0);
            regPosition.indexIn(checkboxHtml);
            regHauteur.indexIn(checkboxHtml);
            regLargeur.indexIn(checkboxHtml);
            regNom.indexIn(checkboxHtml);
            regChecked.indexIn(checkboxHtml);

            Checkbox * checkbox = new Checkbox();
            checkbox->changerTailleComposant(regLargeur.cap(0).toInt(),regHauteur.cap(0).toInt());
            checkbox->modifierPosition(QPoint(regPosition.cap(0).split(";")[0].toInt(),regPosition.cap(0).split(";")[1].toInt()));
            checkbox->modifierNom(regNom.cap(0));
            if (regChecked.cap(0)=="true"){
                checkbox->check();
            }

            page->ajouterComposant(checkbox);
            texte.replace(regCheckbox.cap(0),"");
        }

        if(!regRadiobox.cap(0).isEmpty()){
            QString radioboxHtml = regRadiobox.cap(0);
            regPosition.indexIn(radioboxHtml);
            regHauteur.indexIn(radioboxHtml);
            regLargeur.indexIn(radioboxHtml);

            Radiobox * radiobox = new Radiobox();
            radiobox->changerTailleComposant(regLargeur.cap(0).toInt(),regHauteur.cap(0).toInt());
            radiobox->modifierPosition(QPoint(regPosition.cap(0).split(";")[0].toInt(),regPosition.cap(0).split(";")[1].toInt()));

            regNom.indexIn(radioboxHtml);
            regIsChecked.indexIn(radioboxHtml);

            for(int j=0; j<regNom.captureCount(); j++){
                if (regIsChecked.cap(j) == "true"){
                    radiobox->ajouterElement(regNom.cap(j),true);
                }
                else{
                    radiobox->ajouterElement(regNom.cap(j),false);
                }
            }

            page->ajouterComposant(radiobox);
            texte.replace(regRadiobox.cap(0),"");
        }

        if(!regListe.cap(0).isEmpty()){
            QString listeHtml = regListe.cap(0);
            regPosition.indexIn(listeHtml);
            regHauteur.indexIn(listeHtml);
            regLargeur.indexIn(listeHtml);

            ListeDeroulante * liste = new ListeDeroulante();
            liste->changerTailleComposant(regLargeur.cap(0).toInt(),regHauteur.cap(0).toInt());
            liste->modifierPosition(QPoint(regPosition.cap(0).split(";")[0].toInt(),regPosition.cap(0).split(";")[1].toInt()));

            regNom.indexIn(listeHtml);

            for(int j=0; j<regNom.captureCount(); j++){
                liste->ajouterElement(regNom.cap(j));
            }

            page->ajouterComposant(liste);
            texte.replace(regListe.cap(0),"");
        }
    }

    pages.append(page);
    return page;
}
