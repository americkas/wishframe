#ifndef FENRADIOBOX_H
#define FENRADIOBOX_H

#include <QWidget>

namespace Ui {
class FenRadioBox;
}

class FenRadioBox : public QWidget
{
    Q_OBJECT

public:
    explicit FenRadioBox(QWidget *parent = nullptr, QString name="radiohead", bool checked=false);
    ~FenRadioBox();
signals:
    void modifierCheck();
    void modifierNom(QString nom);

private:
    Ui::FenRadioBox *ui;
};

#endif // FENRADIOBOX_H
