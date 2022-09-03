#ifndef FENLISTEDEROULANTE_H
#define FENLISTEDEROULANTE_H

#include <QWidget>
#include "Modele/listederoulante.h"


namespace Ui {
class FenListeDeroulante;
}

class FenListeDeroulante : public QWidget
{
    Q_OBJECT

public:
    explicit FenListeDeroulante(QWidget *parent = nullptr, QList<ElementListe*> elements = QList<ElementListe*>() << new ElementListe("pillule bleue") << new ElementListe("pillule rouge") << new ElementListe("pillule verte"));
    ~FenListeDeroulante();
signals:
    void modifierNom(QString nom,ElementListe * element);

private:
    Ui::FenListeDeroulante *ui;
};

#endif // FENLISTEDEROULANTE_H
