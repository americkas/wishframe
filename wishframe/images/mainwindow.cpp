#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollArea>
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

void MainWindow::on_actionOuvrir_un_fichier_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/Users/mirnicolas/Documents",
                                                    tr("Fichiers (*.txt)"));
    if (!fileName.isEmpty()){
        on_actionNouveau_fichier_triggered(false);
        DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
        this->controlleur.chargerFichier(fileName, currentDragwidget);
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
    fw->close();
}




void MainWindow::on_actionModifier_objet_triggered()
{
    QWidget * fw = qApp->focusWidget();
    /* Composant  QDialog dialog(this);
      // Use a layout allowing to have a label next to each field
      QFormLayout form(&dialog);

      // Add some text above the fields
      form.addRow(new QLabel("Modifier bouton"));

      // Add the lineEdits with their respective labels
      QList<QLineEdit *> fields;
      for(int i = 0; i < 4; ++i) {
          QLineEdit *lineEdit = new QLineEdit(&dialog);
          QString label = QString("Value %1").arg(i + 1);
          form.addRow(label, lineEdit);

          fields << lineEdit;
      }

      // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
      QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                 Qt::Horizontal, &dialog);
      form.addRow(&buttonBox);
      QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
      QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

      // Show the dialog as modal
      if (dialog.exec() == QDialog::Accepted) {
          // If the user didn't dismiss the dialog, do something with the fields
          foreach(QLineEdit * lineEdit, fields) {
              qDebug() << lineEdit->text();
          }
      }*/

    if (fw){
        DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
        currentDragwidget->modifierComposant("",fw);
        statusBar()->showMessage( QString::number(currentDragwidget->enfants().indexOf(fw)));
    }


}

void MainWindow::on_actionModifier_taille_objet_triggered()
{
    QWidget * fw = qApp->focusWidget();
    //DragWidget * currentDragwidget = ui->tabWidget->currentWidget()->findChild<DragWidget *>(tr("frame_") + QString::number(ui->tabWidget->currentIndex()));
    //fw->setWindowFlags(Qt::SubWindow);

    /*FrameLess * frameless = new FrameLess(fw);

    frameless->setBorderWidth(1);*/
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
