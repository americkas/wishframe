#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollArea>
#include <QDebug>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QStandardPaths>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , controlleur(new Controlleur(this,ui->tabWidget))
{

    nvCount = 1;
    ui->setupUi(this);

    this->setWindowTitle("Wishframe");
    this->setWindowIcon(QIcon(QPixmap(":/images/wish.png")));
    bool firstTab = true; // Permet de démarquer le premier appel à Nouveau fichier des autres
    //ui->tabWidget->removeTab(0);
    on_actionNouveau_fichier_triggered(firstTab);


    //documentPaths.clear();
    //documentPaths = settings.value("recentDocuments").toStringList();
    //updateRecentMenu();
    //connect(ui->menuDocuments_r_cents, SIGNAL(triggered(QAction *) ),
             //this, SLOT(openRecent(QAction *) ));
    //DragWidget * dragwidget = new DragWidget();
    //ui->tabWidget->addTab(new DragWidget(),"dragwidget");


}

MainWindow::~MainWindow()
{
    delete ui;
}


// PARTIE GESTION ONGLETS ET FICHIERS

void MainWindow::on_actionNouveau_fichier_triggered(bool firstTab)
{

        QString text = "";
        if (!firstTab){
            text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Nom de la page :"), QLineEdit::Normal,
                                            "", &firstTab);
        }
            int ct;
            if (text.isEmpty()){
                text = tr("Tab ") + QString::number(nvCount++);
                ct = ui->tabWidget->addTab(
            new QWidget(), text);
                }
            else{
                ct = ui->tabWidget->addTab(
                new QWidget(), text);
            }
            ui->tabWidget->setCurrentIndex(ct);
            //ui->tabWidget->layout()->addWidget(ui->tabWidget->currentWidget());
            DragWidget * dragwidget = new DragWidget(ui->tabWidget->currentWidget());
            QGridLayout *layout = new QGridLayout;
            // Si on veut avoir des tailles fixes, faire condition et ne pas ajouter layout si taille préciser
            layout->addWidget(dragwidget);
            ui->tabWidget->currentWidget()->setLayout(layout);
            dragwidget->setFrameShape(QFrame::Box);
            dragwidget->setObjectName(tr("frame_") + QString::number(ct));
            dragwidget->setProperty("fileName", text);
            dragwidget->setProperty("imgFileName", text);
            dragwidget->show();
            //connect(dragwidget,&DragWidget::fermerOnglet,&controlleur,&Controlleur::supprPage); // TODO connect page fermée
            //connect(dragwidget,DragWidget::modifierTaille(int,int),page,); // TODO connect page taille modifiée*/

}



void MainWindow::on_actionSauvegarder_sous_triggered()
{
    QDir docsDir(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
    QUrl pName = QUrl::fromLocalFile(docsDir.filePath(""));
    QUrl fileName = QFileDialog::getSaveFileUrl(this, tr("Enregister sous..."), pName, "Fichiers texte (*.txt)");
    if (!fileName.isEmpty())
    {
        statusBar()->showMessage(fileName.toLocalFile());
        Page * page = new Page();
        page->ajouterComposant(Typecomposant::Bouton);
        page->ajouterComposant(Typecomposant::RadioBox);

        GestionnairePages * gestionnaire = new GestionnairePages();
        gestionnaire->sauvegarderPage(page, fileName.toLocalFile());

        //sauvegarderFichier(fileName);
    }
}


void MainWindow::on_actionSauvegarder_triggered()
{
    /*QTextEdit * editor = currentTextEdit();
    if (editor != nullptr)
    {
        QVariant fileNameProperty = editor->property("fileName");
        if (fileNameProperty.isValid())
        {
            sauvegarderFichier(fileNameProperty.toString());
        }
        else
        {
            on_actionSauvegarder_sous_triggered();
        }
    }*/
}

void MainWindow::sauvegarderFichier(const QString & fileName)
{
    /*QTextEdit * editor = currentTextEdit();
    if (editor != nullptr)
    {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly))
        {
            manageRecentDocument(fileName);
            QTextStream ts(&file);
            ts << editor->toPlainText();
            ts.flush();
            file.close();
            editor->setProperty("fileName", fileName);
            editor->document()->setModified(false);
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),
                                      QFileInfo(fileName).fileName());
        }
        else
        {
            QMessageBox::critical(
                this,
                tr("Echec de sauvegarde"),
                tr("Le fichier ") + fileName + tr(" n'a pas pu être sauvegardé."));
        }
    }*/
}

void MainWindow::on_actionSauvegarder_sous_forme_d_image_triggered()
{
    DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
    QString name = currentDragwidget->property("imgFileName").toString();
    QString fileName = QFileDialog::getSaveFileName(
        this, tr("Enregister sous..."), name , tr("Fichiers png (*.png)"));
    if (!fileName.isEmpty())
    {
            if (currentDragwidget != nullptr)
            {
                    currentDragwidget->grab().save(fileName);
                    int pos = fileName.lastIndexOf(QChar('.'));
                    currentDragwidget->setProperty("imgFileName", fileName.left(pos));
                    //ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),
                                              //QFileInfo(fileName).fileName());
            }
    }

}
void MainWindow::on_actionRenommer_Onglet_triggered()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                     tr("Nom de la page :"), QLineEdit::Normal,
                                    "", &ok);
    if (ok){
    DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),text);
    currentDragwidget->setProperty("imgFileName", text);
    currentDragwidget->setProperty("fileName", text);
    }

}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->setCurrentIndex(index);
    on_actionFermer_triggered(index);
    //ui->tabWidget->removeTab(index);
}

void MainWindow::on_actionFermer_triggered(int index)
{
       QWidget * currentTab = ui->tabWidget->currentWidget();
        if (currentTab != nullptr)
        {
            /*if (editor->document()->isModified())
            {
                if (QMessageBox::question(this,
                                          tr("Modification détectée"),
                                          tr("Le fichier en cours d'édition a été "
                                          "modifié.\nVoulez-vous le sauvegarder ?"),
                                          QMessageBox::Yes,
                                          QMessageBox::No) == QMessageBox::Yes)
                    on_actionEnregistrer_triggered();
            }*/
            ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
            int count = ui->tabWidget->count();
            int temp_index = index+1;
            while (temp_index <= count && temp_index > 0){
                DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(temp_index));
                currentDragwidget->setObjectName(tr("frame_") + QString::number(temp_index - 1));
                ui->tabWidget->setCurrentIndex(temp_index);
                temp_index ++;
            }


        }
}

// PARTIE OBJETS


void MainWindow::on_actionajouterBouton_triggered()
{
    DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
    currentDragwidget->ajouterComposant(Typecomposant::Bouton);
}

void MainWindow::on_actionajouterImage_triggered()
{
    DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
    currentDragwidget->ajouterComposant(Typecomposant::Image);
}

void MainWindow::on_actionajouterRectangle_triggered()
{
    DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
    currentDragwidget->ajouterComposant(Typecomposant::Rectangle);
}

void MainWindow::on_actionajouterChampDeTexte_triggered()
{
    DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
    currentDragwidget->ajouterComposant(Typecomposant::ChampDeTexte);
}

void MainWindow::on_actionajouterCheckBox_triggered()
{
    DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
    currentDragwidget->ajouterComposant(Typecomposant::Checkbox);
}

void MainWindow::on_actionajouterRadioBox_triggered()
{
    DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
   currentDragwidget->ajouterComposant(Typecomposant::RadioBox);
}

void MainWindow::on_actionajouterListeDeroulante_triggered()
{
    DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
    currentDragwidget->ajouterComposant(Typecomposant::ListeDeroulante);
}


void MainWindow::on_actionSupprimer_triggered()
{
    QWidget * fw = qApp->focusWidget();
    QString widgetType = fw->metaObject()->className();
    if (widgetType=="FenCheckBox" || widgetType=="FenRadioBox" || widgetType=="FenBouton" || widgetType=="FenRectangle" || widgetType=="FenImage" || widgetType=="FenChampDeTexte" || widgetType=="FenListeDeroulante"){
        fw->close();
    }

}




void MainWindow::on_actionModifier_objet_triggered()
{
    QWidget * fw = qApp->focusWidget();


    if (fw){
        DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
        QString infoString = currentDragwidget->obtenirDialogBoxComposant(fw,this);
        currentDragwidget->modifierComposant(infoString,fw);
        //currentDragwidget->modifierComposant("",fw);
        statusBar()->showMessage( QString::number(currentDragwidget->enfants().indexOf(fw)));
        qDebug() << "index : " << currentDragwidget->enfants().indexOf(fw);
        fw->clearFocus();
    }


}


void MainWindow::on_actionCopier_triggered()
{
    QWidget * fw = qApp->focusWidget();
    DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
    QString infoString = currentDragwidget->obtenirInfoString(fw);
    ui->tabWidget->setProperty("InfoStringCopie",infoString);// Sauvegarde des infos de l'élément copié dans les propriétés du gestionnaire d'onglets
    ui->tabWidget->setProperty("typeCopie",fw->metaObject()->className());// Pareil pour le type
    ui->tabWidget->setProperty("positionCopie",fw->pos());//Pareil pour la position
}

void MainWindow::on_actionColler_triggered()
{
    DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
    QWidget * widget = currentDragwidget->creerComposantDepuisInfoString(ui->tabWidget->property("InfoStringCopie").toString(),ui->tabWidget->property("typeCopie").toString());
    currentDragwidget->ajouterComposant(widget,ui->tabWidget->property("positionCopie").toPoint());
}

void MainWindow::on_actionCouper_triggered()
{
    QWidget * fw = qApp->focusWidget();
    on_actionCopier_triggered();
    fw->close();
}
