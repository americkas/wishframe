#ifndef FENRECTANGLE_H
#define FENRECTANGLE_H

#include <QWidget>

namespace Ui {
class FenRectangle;
}

class FenRectangle : public QWidget
{
    Q_OBJECT

public:
    explicit FenRectangle(QWidget *parent = nullptr, int bordRadius = 25, QString bordCouleur = "red");
    ~FenRectangle();
signals:
    void changerBordRadius(int radius);
    void changerBordCouleur(QString couleur);

private:
    Ui::FenRectangle *ui;
};

#endif // FENRECTANGLE_H
