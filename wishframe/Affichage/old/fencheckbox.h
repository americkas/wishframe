#ifndef FENCHECKBOX_H
#define FENCHECKBOX_H

#include <QWidget>

namespace Ui {
class FenCheckBox;
}

class FenCheckBox : public QWidget
{
    Q_OBJECT

public:
    explicit FenCheckBox(QWidget *parent = nullptr, QString nom="nom", bool checked=false);
    ~FenCheckBox();
signals:
    void modifierNom (QString nom);
    void modifierCheck (bool checked);

private:
    Ui::FenCheckBox *ui;
};

#endif // FENCHECKBOX_H
