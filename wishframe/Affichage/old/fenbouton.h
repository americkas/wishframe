#ifndef FENBOUTON_H
#define FENBOUTON_H

#include <QWidget>

namespace Ui {
class FenBouton;
}

class FenBouton : public QWidget
{
    Q_OBJECT

public:
    explicit FenBouton(QWidget *parent = nullptr, QString nom = "voila", QString policeCouleur= "rgb(0,0,0)", int PoliceTaille = 11);
    ~FenBouton();

signals:
    void modifierChamp(QString champ);
    void modifierPoliceCouleur(QString policeCouleur); //Format rgb
    void modifierPoliceTaille(int policeTaille);

private:
    Ui::FenBouton *ui;
};

#endif // FENBOUTON_H
