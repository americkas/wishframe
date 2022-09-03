#ifndef FENCHAMPDETEXTE_H
#define FENCHAMPDETEXTE_H

#include <QWidget>

namespace Ui {
class FenChampDeTexte;
}

class FenChampDeTexte : public QWidget
{
    Q_OBJECT

public:
    explicit FenChampDeTexte(QWidget *parent = nullptr, QString champ = "...", QString policeCouleur = "#FF0000", int policeTaille = 42);
    ~FenChampDeTexte();

signals:
    void modifierChamp(QString champ);
    void modifierPoliceCouleur(QString policeCouleur); //Format rgb
    void modifierPoliceTaille(int policeTaille);

private:
    Ui::FenChampDeTexte *ui;
};

#endif // FENCHAMPDETEXTE_H
