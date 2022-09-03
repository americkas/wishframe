#include "dragwidget.h"

#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QFrame>
#include <QLabel>
#include <QRegularExpression>
#include <QWindow>
#include <QMenu>
#include <QErrorMessage>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDebug>
#include <QImage>
// TODO gérer index children
DragWidget::DragWidget(QWidget *parent)
    : QFrame(parent)
{

    setAcceptDrops(true);

    setMinimumSize(parent->width(),parent->height());
    //this->setFrameShape(QFrame::Box);

}



QString DragWidget::obtenirInfoString(QWidget * composant){

    QString typeWidget = composant->metaObject()->className();
    QString data = "";
    if(typeWidget == "FenBouton"){
        data = qobject_cast<FenBouton*>(composant)->obtenirInfoString();
    }
    else if(typeWidget == "FenImage"){
        data = qobject_cast<FenImage*>(composant)->obtenirInfoString();
    }
    else if (typeWidget == "FenRectangle") {
        data = qobject_cast<FenRectangle*>(composant)->obtenirInfoString();
    }
    else if (typeWidget == "FenChampDeTexte") {
        data = qobject_cast<FenChampDeTexte*>(composant)->obtenirInfoString();
    }
    else if (typeWidget == "FenCheckBox") {
        data = qobject_cast<FenCheckBox*>(composant)->obtenirInfoString();
    }
    else if (typeWidget == "FenRadioBox") {
        data = qobject_cast<FenRadioBox*>(composant)->obtenirInfoString();
    }
    else if (typeWidget == "FenListeDeroulante") {
        data = qobject_cast<FenListeDeroulante*>(composant)->obtenirInfoString();
    }
    else{
        QErrorMessage * errorBox = new QErrorMessage();
        errorBox->showMessage("Type non reconnu");
    }
    return data;
}

QWidget * DragWidget::creerComposantDepuisInfoString(QString InfoString,QString widgetType){
    //On définit des patterns pour retrouver les variables
    QRegularExpression regNom("<nom>(.*)</nom>");
    QRegularExpression regStylesheet("<stylesheet>(.*)</stylesheet>");
    QRegularExpression regHauteur("<hauteur>(.*)</hauteur>");
    QRegularExpression regLargeur("<largeur>(.*)</largeur>");
    QRegularExpression regChamp("<champ>(.*)</champ>");
    QRegularExpression regChecked("<checked>(.*)</checked>");
    QRegularExpression regLien("<lien>(.*)</lien>");

    QString nom ="";
    QString stylesheet ="";
    int hauteur = 0;
    int largeur = 0;
    QString champ = "";
    bool ok;
    QString lien = "";

    bool checked=false;
    qDebug() << "Info: " << InfoString;
    QRegularExpressionMatch matchNom = regNom.match(InfoString);
    QRegularExpressionMatch matchStylesheet = regStylesheet.match(InfoString);
    QRegularExpressionMatch matchHauteur = regHauteur.match(InfoString);
    QRegularExpressionMatch matchLargeur = regLargeur.match(InfoString);
    QRegularExpressionMatch matchChamp = regChamp.match(InfoString);
    QRegularExpressionMatch matchChecked = regChecked.match(InfoString);
    QRegularExpressionMatch matchLien = regLien.match(InfoString);

/*
    qDebug() << "Nom : " << regNom;
    qDebug() << "Nom : " << matchNom;
    qDebug() <<  "Style : " << matchStylesheet;
    qDebug() << "Hauteur: " << matchHauteur;
    qDebug() << "Largeur: " << matchLargeur;
    qDebug() << "Champ: " << matchChamp;
    qDebug() << "Lien: " << matchLien;*/

    // On récupère les variables définies
    while(!InfoString.isEmpty()){
        if(matchNom.hasMatch()){
                        nom = matchNom.captured(1);
                        InfoString.replace(matchNom.captured(0),"");

        }
        if(matchStylesheet.hasMatch()){
                        stylesheet = matchStylesheet.captured(1);
                        InfoString.replace(matchStylesheet.captured(0),"");

        }
        if(matchHauteur.hasMatch()){
                        hauteur = matchHauteur.captured(1).toInt(&ok,10);
                        InfoString.replace(matchHauteur.captured(0),"");

        }
        if(matchLargeur.hasMatch()){
                        largeur = matchLargeur.captured(1).toInt(&ok,10);
                        InfoString.replace(matchLargeur.captured(0),"");

        }
        if(matchChamp.hasMatch()){
                        champ = matchChamp.captured(1);
                        InfoString.replace(matchChamp.captured(0),"");

        }
        if(matchChecked.hasMatch()){
            if (matchChecked.captured(1) == "true"){checked=true;}
                        InfoString.replace(matchChecked.captured(0),"");
        }
        if(matchLien.hasMatch()){
                        lien = matchLien.captured(1);
                        InfoString.replace(matchLien.captured(0),"");
        }

    }
/*    qDebug() << "Type: " << widgetType;
    qDebug() << "Nom : " << nom;
    qDebug() <<  "Style : " << stylesheet;
    qDebug() << "Hauteur: " << hauteur;
    qDebug() << "Largeur: " << largeur;
    qDebug() << "Champ: " << champ;
    qDebug() << "Lien: " << lien;*/

        if(widgetType=="FenCheckBox"){

             FenCheckBox * widget = new FenCheckBox(this, nom, checked,largeur,hauteur);
             return widget;
        }
        else if(widgetType=="FenRadioBox"){
            FenRadioBox * widget = new FenRadioBox(this, nom, checked, largeur, hauteur);
            return widget;
        }
        else if(widgetType=="FenBouton"){
            FenBouton * widget = new FenBouton(this, nom," ", 11 , largeur, hauteur);
            widget->setStyleSheet(stylesheet);
            return widget;
        }
        else if(widgetType=="FenRectangle"){
            FenRectangle * widget = new FenRectangle(this,25, "red",largeur,hauteur);
            return widget;
        }
        else if(widgetType=="FenImage"){
            FenImage * widget = new FenImage(this,lien);
            widget->setMinimumSize(largeur,hauteur);
            return widget;
        }
        else if(widgetType=="FenChampDeTexte"){
            FenChampDeTexte * widget = new FenChampDeTexte(this,champ, " ", 11 , largeur, hauteur);
            widget->setStyleSheet(stylesheet);
            return widget;
        }
        else if(widgetType=="FenListeDeroulante"){
            FenListeDeroulante * widget = new FenListeDeroulante(this);
            return widget;
        }
        else{
            qFatal( "Composant non reconnu");
    }

}

QList <QWidget *> DragWidget::enfants(){
    return this->listeWidgets;
}

/*void DragWidget::obtenirDonneesDepuisInfoString(QString InfoString, QVariant * nom, QVariant * stylesheet, QVariant * hauteur, QVariant *largeur,  QVariant * champ, QVariant *lien , QVariant * checked){
    //On définit des patterns pour retrouver les variables
    QRegularExpression regNom("<nom>(.*)</nom>");
    QRegularExpression regStylesheet("<stylesheet>(.*)</stylesheet>");
    QRegularExpression regHauteur("<hauteur>(.*)</hauteur>");
    QRegularExpression regLargeur("<largeur>(.*)</largeur>");
    QRegularExpression regChamp("<champ>(.*)</champ>");
    QRegularExpression regChecked("<checked>(.*)</checked>");
    QRegularExpression regLien("<lien>(.*)</lien>");

    bool ok;

    qDebug() << "Info: " << InfoString;
    QRegularExpressionMatch matchNom = regNom.match(InfoString);
    QRegularExpressionMatch matchStylesheet = regStylesheet.match(InfoString);
    QRegularExpressionMatch matchHauteur = regHauteur.match(InfoString);
    QRegularExpressionMatch matchLargeur = regLargeur.match(InfoString);
    QRegularExpressionMatch matchChamp = regChamp.match(InfoString);
    QRegularExpressionMatch matchChecked = regChecked.match(InfoString);
    QRegularExpressionMatch matchLien = regLien.match(InfoString);


    qDebug() << "Nom : " << regNom;
    qDebug() << "Nom : " << matchNom;
    qDebug() <<  "Style : " << matchStylesheet;
    qDebug() << "Hauteur: " << matchHauteur;
    qDebug() << "Largeur: " << matchLargeur;
    qDebug() << "Champ: " << matchChamp;
    qDebug() << "Lien: " << matchLien;

    // On récupère les variables définies
    while(!InfoString.isEmpty()){
        if(matchNom.hasMatch()){
            nom = new QVariant(matchNom.captured(1));
            qDebug() << "Nom:" << *nom;
            InfoString.replace(matchNom.captured(0),"");

        }
        if(matchStylesheet.hasMatch()){
            stylesheet = new QVariant(matchStylesheet.captured(1));
            InfoString.replace(matchStylesheet.captured(0),"");

        }
        if(matchHauteur.hasMatch()){
            hauteur = new QVariant(matchHauteur.captured(1).toInt(&ok,10));
            InfoString.replace(matchHauteur.captured(0),"");

        }
        if(matchLargeur.hasMatch()){
            largeur = new QVariant(matchLargeur.captured(1).toInt(&ok,10));
            InfoString.replace(matchLargeur.captured(0),"");

        }
        if(matchChamp.hasMatch()){
            champ = new QVariant(matchChamp.captured(1));
            InfoString.replace(matchChamp.captured(0),"");

        }
        if(matchChecked.hasMatch()){
            if (matchChecked.captured(1) == "true"){checked = new QVariant(true);}
            else{checked = new QVariant(false);};
                        InfoString.replace(matchChecked.captured(0),"");
        }
        if(matchLien.hasMatch()){
                        lien = new QVariant(matchLien.captured(1));
                        InfoString.replace(matchLien.captured(0),"");
        }

    }
    qDebug() << "Type: " << widgetType;
    qDebug() << "Nom : " << nom;
    qDebug() <<  "Style : " << stylesheet;
    qDebug() << "Hauteur: " << hauteur;
    qDebug() << "Largeur: " << largeur;
    qDebug() << "Champ: " << champ;
    qDebug() << "Lien: " << lien;
}
*/
void DragWidget::ajouterComposant(QWidget * instance,QPoint point){
    instance->move(point);
    instance->show();
    instance->setAttribute(Qt::WA_DeleteOnClose);
    listeWidgets.append(instance);
}

void DragWidget::ajouterComposant(Typecomposant composant){
    switch(composant){
        case Typecomposant::Checkbox:{
            FenCheckBox * instance = new FenCheckBox(this);
            this->ajouterComposant(instance,this->geometry().center());
            break;
        }
        case Typecomposant::RadioBox:{
            FenRadioBox * instance = new FenRadioBox(this);
            this->ajouterComposant(instance,this->geometry().center());
            break;
        }
        case Typecomposant::Bouton:{
            FenBouton * instance = new FenBouton(this);
            this->ajouterComposant(instance,this->geometry().center());
            break;
        }
        case Typecomposant::Rectangle:{
            FenRectangle * instance = new FenRectangle(this);
            this->ajouterComposant(instance,this->geometry().center());
            break;
        }
        case Typecomposant::Image:{
            FenImage * instance = new FenImage(this);
            this->ajouterComposant(instance,this->geometry().center());
            break;
        }
        case Typecomposant::ChampDeTexte:{
            FenChampDeTexte * instance = new FenChampDeTexte(this);
            this->ajouterComposant(instance,this->geometry().center());
            break;
        }
        case Typecomposant::ListeDeroulante:{
            FenListeDeroulante * instance = new FenListeDeroulante(this);
            this->ajouterComposant(instance,this->geometry().center());
            break;
        }
        default:
            qFatal( "Composant non reconnu");
    }
}

QString DragWidget::stylesheet(QString type, QString couleur, QString nombre){
    QString stylesheet = "";
    if (type=="FenBouton"){
        stylesheet = "QPushButton{font-size:" + nombre +"px;color: " + couleur + ";}";
    }
    else if(type=="FenChampDeTexte"){
        stylesheet = "QLabel{font-size:" + nombre +"px;color: " + couleur + ";}";
    }
    else if(type=="FenRectangle"){
        stylesheet = "QLabel{background-color: white; height: 200px; width: 50px; border: 5px solid " + couleur + "; border-radius: " + nombre+ "px;}";
    }
    return stylesheet;
}

QString DragWidget::obtenirDialogBoxComposant(QWidget * composant, QWidget * parent){
    QDialog dialog(parent);
      QString typeWidget = composant->metaObject()->className();
      QString infoString = "";

      // Ajout du titre
      dialog.setWindowTitle("Modifier " + typeWidget);
      QFormLayout form(&dialog);

      // Ajout des lineEdits avec leur label
      QList<QLineEdit *> fields;

      if(typeWidget == "FenBouton"){
          //On crée les labels
          QLineEdit *nomLineEdit = new QLineEdit(&dialog);
          QString nom = QString("Nom");

          QLineEdit *policeCouleurLineEdit = new QLineEdit(&dialog);
          QString policeCouleur  = QString("Couleur de la police (en rgb)");

          QLineEdit *policeTailleLineEdit = new QLineEdit(&dialog);
          QString policeTaille  = QString("Taille de la police");

          QLineEdit *largeurLineEdit = new QLineEdit(&dialog);
          QString largeur  = QString("Largeur");

          QLineEdit *hauteurLineEdit = new QLineEdit(&dialog);
          QString hauteur = QString("Hauteur");

          //On les ajoute au layout
          form.addRow(nom, nomLineEdit);
          form.addRow(policeCouleur, policeCouleurLineEdit);
          form.addRow(policeTaille, policeTailleLineEdit);
          form.addRow(largeur, largeurLineEdit);
          form.addRow(hauteur, hauteurLineEdit);


          fields << nomLineEdit
                 << policeCouleurLineEdit
                 << policeTailleLineEdit
                 << largeurLineEdit
                 << hauteurLineEdit;

      }
      else if(typeWidget == "FenImage"){
          //On crée les labels
          QLineEdit *lienLineEdit = new QLineEdit(&dialog);
          QString lien = QString("Lien");

          QLineEdit *largeurLineEdit = new QLineEdit(&dialog);
          QString largeur  = QString("Largeur");

          QLineEdit *hauteurLineEdit = new QLineEdit(&dialog);
          QString hauteur = QString("Hauteur");

          //On les ajoute au layout
          form.addRow(lien, lienLineEdit);
          form.addRow(largeur, largeurLineEdit);
          form.addRow(hauteur, hauteurLineEdit);


          fields << lienLineEdit
                 << largeurLineEdit
                 << hauteurLineEdit;
      }
      else if (typeWidget == "FenRectangle") {
          //On crée les labels
          QLineEdit *bordRadiusLineEdit = new QLineEdit(&dialog);
          QString bordRadius  = QString("Rayon des bords");

          QLineEdit *bordCouleurLineEdit = new QLineEdit(&dialog);
          QString bordCouleur  = QString("Couleur des bords");

          QLineEdit *largeurLineEdit = new QLineEdit(&dialog);
          QString largeur  = QString("Largeur");

          QLineEdit *hauteurLineEdit = new QLineEdit(&dialog);
          QString hauteur = QString("Hauteur");

          //On les ajoute au layout
          form.addRow(bordRadius, bordRadiusLineEdit);
          form.addRow(bordCouleur, bordCouleurLineEdit);
          form.addRow(largeur, largeurLineEdit);
          form.addRow(hauteur, hauteurLineEdit);


          fields << bordRadiusLineEdit
                 << bordCouleurLineEdit
                 << largeurLineEdit
                 << hauteurLineEdit;
      }
      else if (typeWidget == "FenChampDeTexte") {
          //On crée les labels
          QLineEdit *champLineEdit = new QLineEdit(&dialog);
          QString champ = QString("Nom");

          QLineEdit *policeCouleurLineEdit = new QLineEdit(&dialog);
          QString policeCouleur  = QString("Couleur de la police (en rgb)");

          QLineEdit *policeTailleLineEdit = new QLineEdit(&dialog);
          QString policeTaille  = QString("Taille de la police");

          QLineEdit *largeurLineEdit = new QLineEdit(&dialog);
          QString largeur  = QString("Largeur");

          QLineEdit *hauteurLineEdit = new QLineEdit(&dialog);
          QString hauteur = QString("Hauteur");

          //On les ajoute au layout
          form.addRow(champ, champLineEdit);
          form.addRow(policeCouleur, policeCouleurLineEdit);
          form.addRow(policeTaille, policeTailleLineEdit);
          form.addRow(largeur, largeurLineEdit);
          form.addRow(hauteur, hauteurLineEdit);


          fields << champLineEdit
                 << policeCouleurLineEdit
                 << policeTailleLineEdit
                 << largeurLineEdit
                 << hauteurLineEdit;
      }
      else if (typeWidget == "FenCheckBox") {
          //On crée les labels
          QLineEdit *nomLineEdit = new QLineEdit(&dialog);
          QString nom = QString("Nom");

          QLineEdit *largeurLineEdit = new QLineEdit(&dialog);
          QString largeur  = QString("Largeur");

          QLineEdit *hauteurLineEdit = new QLineEdit(&dialog);
          QString hauteur = QString("Hauteur");

          //On les ajoute au layout
          form.addRow(nom, nomLineEdit);
          form.addRow(largeur, largeurLineEdit);
          form.addRow(hauteur, hauteurLineEdit);


          fields << nomLineEdit
                 << largeurLineEdit
                 << hauteurLineEdit;
      }
      else if (typeWidget == "FenRadioBox") {
          //On crée les labels
          QLineEdit *nomLineEdit = new QLineEdit(&dialog);
          QString nom = QString("Nom");

          QLineEdit *largeurLineEdit = new QLineEdit(&dialog);
          QString largeur  = QString("Largeur");

          QLineEdit *hauteurLineEdit = new QLineEdit(&dialog);
          QString hauteur = QString("Hauteur");

          //On les ajoute au layout
          form.addRow(nom, nomLineEdit);
          form.addRow(largeur, largeurLineEdit);
          form.addRow(hauteur, hauteurLineEdit);


          fields << nomLineEdit
                 << largeurLineEdit
                 << hauteurLineEdit;
      }
      else if (typeWidget == "FenListeDeroulante") {


      }
      // Ajout des boutons Ok / Cancel
      QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                 Qt::Horizontal, &dialog);
      form.addRow(&buttonBox);
      QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
      QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
      // Affiche la boite de dialogue
      if (dialog.exec() == QDialog::Accepted) {
          /*
          foreach(QLineEdit * lineEdit, fields) {
              qDebug() << lineEdit->text();
          }*/
          qDebug() << fields.at(0)->text().toInt();
          if(typeWidget == "FenBouton"){
              if (fields.at(0)->text() == "")
                    infoString = QString("<nom>") + qobject_cast<FenBouton*>(composant)->text() + QString("</nom>");
              else
                    infoString = QString("<nom>") + fields.at(0)->text() + QString("</nom>");

              if (fields.at(1)->text() == "" && fields.at(2)->text() == "")
                    infoString = infoString + QString("<stylesheet>") + qobject_cast<FenBouton*>(composant)->styleSheet() + QString("</stylesheet>");
              else
                    infoString = infoString + QString("<stylesheet>") + stylesheet(typeWidget,fields.at(1)->text(),fields.at(2)->text()) + QString("</stylesheet>");
              if (fields.at(3)->text() == "")
                    infoString = infoString + QString("<largeur>") + QString::number(qobject_cast<FenBouton*>(composant)->size().width()) + QString("</largeur>");
              else
                    infoString = infoString + QString("<largeur>") + fields.at(3)->text() + QString("</largeur>");
              if (fields.at(4)->text() == "")
                    infoString = infoString + QString("<hauteur>") + QString::number(qobject_cast<FenBouton*>(composant)->size().height()) + QString("</hauteur>");
              else
                    infoString = infoString + QString("<hauteur>") + fields.at(4)->text() + QString("</hauteur>");

          }
          else if(typeWidget == "FenImage"){
              if (QImage(fields.at(0)->text()).isNull()){
                    infoString = QString("<lien>") + qobject_cast<FenBouton*>(composant)->text() + QString("</lien>");
                    qDebug() << "test";}
              else
                    infoString = QString("<lien>") + fields.at(0)->text() + QString("</lien>");

              if (fields.at(1)->text() == "")
                    infoString = infoString + QString("<largeur>") + QString::number(qobject_cast<FenBouton*>(composant)->size().width()) + QString("</largeur>");
              else
                    infoString = infoString + QString("<largeur>") + fields.at(1)->text() + QString("</largeur>");
              if (fields.at(2)->text() == "")
                    infoString = infoString + QString("<hauteur>") + QString::number(qobject_cast<FenBouton*>(composant)->size().height()) + QString("</hauteur>");
              else
                    infoString = infoString + QString("<hauteur>") + fields.at(2)->text() + QString("</hauteur>");
          }
          else if (typeWidget == "FenRectangle") {
              if (fields.at(0)->text() == "" && fields.at(1)->text() == "")
                    infoString = infoString + QString("<stylesheet>") + qobject_cast<FenRectangle*>(composant)->styleSheet() + QString("</stylesheet>");
              else
                    infoString = infoString + QString("<stylesheet>") + stylesheet(typeWidget,fields.at(1)->text(),fields.at(0)->text()) + QString("</stylesheet>");
              if (fields.at(2)->text() == "")
                    infoString = infoString + QString("<largeur>") + QString::number(qobject_cast<FenRectangle*>(composant)->size().width()) + QString("</largeur>");
              else
                    infoString = infoString + QString("<largeur>") + fields.at(2)->text() + QString("</largeur>");
              if (fields.at(3)->text() == "")
                    infoString = infoString + QString("<hauteur>") + QString::number(qobject_cast<FenRectangle*>(composant)->size().height()) + QString("</hauteur>");
              else
                    infoString = infoString + QString("<hauteur>") + fields.at(3)->text() + QString("</hauteur>");
          }
          else if (typeWidget == "FenChampDeTexte") {
              if (fields.at(0)->text() == "")
                    infoString = QString("<champ>") + qobject_cast<FenChampDeTexte*>(composant)->text() + QString("</champ>");
              else
                    infoString = QString("<champ>") + fields.at(0)->text() + QString("</champ>");

              if (fields.at(1)->text() == "" && fields.at(2)->text() == "")
                    infoString = infoString + QString("<stylesheet>") + qobject_cast<FenChampDeTexte*>(composant)->styleSheet() + QString("</stylesheet>");
              else
                    infoString = infoString + QString("<stylesheet>") + stylesheet(typeWidget,fields.at(1)->text(),fields.at(2)->text()) + QString("</stylesheet>");
              if (fields.at(3)->text() == "")
                    infoString = infoString + QString("<largeur>") + QString::number(qobject_cast<FenChampDeTexte*>(composant)->size().width()) + QString("</largeur>");
              else
                    infoString = infoString + QString("<largeur>") + fields.at(3)->text() + QString("</largeur>");
              if (fields.at(4)->text() == "")
                    infoString = infoString + QString("<hauteur>") + QString::number(qobject_cast<FenChampDeTexte*>(composant)->size().height()) + QString("</hauteur>");
              else
                    infoString = infoString + QString("<hauteur>") + fields.at(4)->text() + QString("</hauteur>");

          }
          else if (typeWidget == "FenCheckBox") {
              if (fields.at(0)->text() == "")
                    infoString = QString("<nom>") + qobject_cast<FenCheckBox*>(composant)->text() + QString("</nom>");
              else
                    infoString = QString("<nom>") + fields.at(0)->text() + QString("</nom>");
              if (fields.at(1)->text() == "")
                    infoString = infoString + QString("<largeur>") + QString::number(qobject_cast<FenCheckBox*>(composant)->size().width()) + QString("</largeur>");
              else
                    infoString = infoString + QString("<largeur>") + fields.at(1)->text() + QString("</largeur>");
              if (fields.at(2)->text() == "")
                    infoString = infoString + QString("<hauteur>") + QString::number(qobject_cast<FenCheckBox*>(composant)->size().height()) + QString("</hauteur>");
              else
                    infoString = infoString + QString("<hauteur>") + fields.at(2)->text() + QString("</hauteur>");
          }
          else if (typeWidget == "FenRadioBox") {
              if (fields.at(0)->text() == "")
                    infoString = QString("<nom>") + qobject_cast<FenRadioBox*>(composant)->text() + QString("</nom>");
              else
                    infoString = QString("<nom>") + fields.at(0)->text() + QString("</nom>");
              if (fields.at(1)->text() == "")
                    infoString = infoString + QString("<largeur>") + QString::number(qobject_cast<FenRadioBox*>(composant)->size().width()) + QString("</largeur>");
              else
                    infoString = infoString + QString("<largeur>") + fields.at(1)->text() + QString("</largeur>");
              if (fields.at(2)->text() == "")
                    infoString = infoString + QString("<hauteur>") + QString::number(qobject_cast<FenRadioBox*>(composant)->size().height()) + QString("</hauteur>");
              else
                    infoString = infoString + QString("<hauteur>") + fields.at(2)->text() + QString("</hauteur>");
          }
          else if (typeWidget == "FenListeDeroulante") {

          }
      }
   return infoString;

}

void DragWidget::modifierComposant(QString InfoString,QWidget * composant){

    QString typeWidget = composant->metaObject()->className();
    //On définit des patterns pour retrouver les variables
    QRegularExpression regNom("<nom>(.*)</nom>");
    QRegularExpression regStylesheet("<stylesheet>(.*)</stylesheet>");
    QRegularExpression regHauteur("<hauteur>(.*)</hauteur>");
    QRegularExpression regLargeur("<largeur>(.*)</largeur>");
    QRegularExpression regChamp("<champ>(.*)</champ>");
    QRegularExpression regLien("<lien>(.*)</lien>");

    QString nom ="";
    QString stylesheet ="";
    int hauteur = 0;
    int largeur = 0;
    QString champ = "";
    bool ok;
    QString lien = "";

    //bool checked=false; Pas nécessaire pour modification. On peut le faire directement
    qDebug() << "Info: " << InfoString;
    QRegularExpressionMatch matchNom = regNom.match(InfoString);
    QRegularExpressionMatch matchStylesheet = regStylesheet.match(InfoString);
    QRegularExpressionMatch matchHauteur = regHauteur.match(InfoString);
    QRegularExpressionMatch matchLargeur = regLargeur.match(InfoString);
    QRegularExpressionMatch matchChamp = regChamp.match(InfoString);
    QRegularExpressionMatch matchLien = regLien.match(InfoString);

/*
    qDebug() << "Nom : " << regNom;
    qDebug() << "Nom : " << matchNom;
    qDebug() <<  "Style : " << matchStylesheet;
    qDebug() << "Hauteur: " << matchHauteur;
    qDebug() << "Largeur: " << matchLargeur;
    qDebug() << "Champ: " << matchChamp;
    qDebug() << "Lien: " << matchLien;*/

    // On récupère les variables définies
    while(!InfoString.isEmpty()){
        if(matchNom.hasMatch()){
                        nom = matchNom.captured(1);
                        InfoString.replace(matchNom.captured(0),"");

        }
        if(matchStylesheet.hasMatch()){
                        stylesheet = matchStylesheet.captured(1);
                        InfoString.replace(matchStylesheet.captured(0),"");

        }
        if(matchHauteur.hasMatch()){
                        hauteur = matchHauteur.captured(1).toInt(&ok,10);
                        InfoString.replace(matchHauteur.captured(0),"");

        }
        if(matchLargeur.hasMatch()){
                        largeur = matchLargeur.captured(1).toInt(&ok,10);
                        InfoString.replace(matchLargeur.captured(0),"");

        }
        if(matchChamp.hasMatch()){
                        champ = matchChamp.captured(1);
                        InfoString.replace(matchChamp.captured(0),"");

        }
        if(matchLien.hasMatch()){
                        lien = matchLien.captured(1);
                        InfoString.replace(matchLien.captured(0),"");
        }

    }


    if(typeWidget == "FenBouton"){
        qobject_cast<FenBouton*>(composant)->setText(nom);
        qobject_cast<FenBouton*>(composant)->setStyleSheet(stylesheet);
        qobject_cast<FenBouton*>(composant)->setMinimumSize(largeur,hauteur);

    }
    else if(typeWidget == "FenImage"){
        if (!QImage(lien).isNull()){
            qobject_cast<FenImage*>(composant)->setPixmap(QPixmap(lien));
        }
        qobject_cast<FenRectangle*>(composant)->setMinimumSize(largeur,hauteur);

    }
    else if (typeWidget == "FenRectangle") {
        composant = qobject_cast<FenRectangle*>(composant);
        qobject_cast<FenRectangle*>(composant)->setStyleSheet(stylesheet);
        qobject_cast<FenRectangle*>(composant)->setMinimumSize(largeur,hauteur);
    }
    else if (typeWidget == "FenChampDeTexte") {
        qobject_cast<FenChampDeTexte*>(composant)->setText(nom);
        qobject_cast<FenChampDeTexte*>(composant)->setStyleSheet(stylesheet);
        qobject_cast<FenChampDeTexte*>(composant)->setMinimumSize(largeur,hauteur);
    }
    else if (typeWidget == "FenCheckBox") {
        qobject_cast<FenCheckBox*>(composant)->setText(nom);
        qobject_cast<FenCheckBox*>(composant)->setMinimumSize(largeur,hauteur);
    }
    else if (typeWidget == "FenRadioBox") {
        qobject_cast<FenRadioBox*>(composant)->setText(nom);
        qobject_cast<FenRadioBox*>(composant)->setMinimumSize(largeur,hauteur);
    }
    else if (typeWidget == "FenListeDeroulante") {

    }
    else{
        QErrorMessage * errorBox = new QErrorMessage();
        errorBox->showMessage("Type non reconnu");
    }
}



void DragWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DragWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DragWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        const QMimeData *mime = event->mimeData();
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        QString infoString = mime->text();
        QPoint offset;
        dataStream >> offset;
        QWidget * widget = this->creerComposantDepuisInfoString(infoString,type_widget);
        listeWidgets.insert(index_widget, widget);
        widget->move(event->pos() - offset);
        widget->show();
        widget->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DragWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget * fw = this->focusWidget(); // On crée une variable correspondant à l'élément sélectionné
    if (fw){ // fw existe  on le réinitialise et désélectionne
        fw->setStyleSheet(fw->property("stylesheet").toString());
        fw->clearFocus();
    }
    if (event->button()==Qt::LeftButton){
         this->dragStartPosition = event->pos();
    }

    else if (event->button()==Qt::RightButton)//TODO Menu contextuel ?
    {
        /*QWidget *child = childAt(event->pos());
        if (!child)
            return;
        this->type_widget = child->metaObject()->className();

        this->setContextMenuPolicy(Qt::CustomContextMenu);

        connect(child, SIGNAL(customContextMenuRequested(const QPoint &pos)),
                this, SLOT(showContextMenu()));*/


    }
}

void DragWidget::mouseMoveEvent(QMouseEvent *event){

    if (!(event->buttons() & Qt::LeftButton))
            return;
    if ((event->pos() - dragStartPosition).manhattanLength()
         < 10)
        return;

    QWidget *child = childAt(event->pos());
    if (!child)
        return;
    this->type_widget = child->metaObject()->className();
    index_widget = this->listeWidgets.indexOf(child);


    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << QPoint(event->pos() - child->pos());


    QMimeData *mimeData = new QMimeData;
    if(this->type_widget == "FenBouton"){
        mimeData->setText(qobject_cast<FenBouton *>(child)->obtenirInfoString());
    }
    else if(this->type_widget == "FenImage"){
        mimeData->setText(qobject_cast<FenImage *>(child)->obtenirInfoString());
    }
    else if (this->type_widget == "FenRectangle") {
        mimeData->setText(qobject_cast<FenRectangle *>(child)->obtenirInfoString());
    }
    else if (this->type_widget == "FenChampDeTexte") {
        mimeData->setText(qobject_cast<FenChampDeTexte *>(child)->obtenirInfoString());
    }
    else if (this->type_widget == "FenCheckBox") {
        mimeData->setText(qobject_cast<FenCheckBox *>(child)->obtenirInfoString());
    }
    else if (this->type_widget == "FenRadioBox") {
        mimeData->setText(qobject_cast<FenRadioBox *>(child)->obtenirInfoString());
    }
    else if (this->type_widget == "FenListeDeroulante") {
        mimeData->setText(qobject_cast<FenListeDeroulante*>(child)->obtenirInfoString());
    }
    mimeData->setData("application/x-dnditemdata", itemData);


    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setHotSpot(event->pos() - child->pos());



    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);

    if (dropAction == Qt::MoveAction)
        child->close();
    else
        child->show();

}

void DragWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
        {
        QWidget *child = childAt(event->pos()); //On crée une variable correspondant à la position sur laquelle on a double cliqué
        QWidget * fw = this->focusWidget(); // On crée une variable correspondant à l'élément sélectionné
        if (fw){ // fw existe  on le réinitialise et désélectionne
            fw->setStyleSheet(fw->property("stylesheet").toString());
            //rubberBand->hide();
            fw->clearFocus();
        }
        if (!child){ // Si la position double-cliquée ne correspond à aucun élément on ne fait rien
            return;
        }
        QPoint origin = event->pos();

        /*if (!rubberBand)
            rubberBand = new QRubberBand(QRubberBand::Rectangle, child);
        rubberBand->setGeometry(QRect(origin, QSize()));
        rubberBand->show();*/
        child->setProperty("stylesheet",child->styleSheet());
        child->setFocus();// On considère que l'élément child est sélectionné et on change sa couleur pour le démarquer des autres
        child->setStyleSheet("background-color: red");
    }
}

/*void DragWidget::showContextMenu()
{
   QAction action1("Supprimer", this);
   //connect(&action1, SIGNAL(triggered()), this, SLOT(removeDataPoint()));


   QMenu *pContextMenu = new QMenu( this);

   pContextMenu->addAction(&action1);
   pContextMenu->exec();
   delete pContextMenu;
   pContextMenu = NULL;
}*/


