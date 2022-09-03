#include "radiobox.h"

RadioboxSingle::RadioboxSingle()
    :nom("Element")
{
}

void RadioboxSingle::modifierNom(QString nom){
    this->nom = nom;
}

void RadioboxSingle::check(){
    this->isChecked = !(this->isChecked);
}

Radiobox::Radiobox()
{
    RadioboxSingle * radioboxSingle = new RadioboxSingle();
    this->radioboxes.append(radioboxSingle);
}

void Radiobox::ajouterElement(QString nom,bool isChecked){
    RadioboxSingle * radioboxSingle = new RadioboxSingle();
    radioboxSingle->modifierNom(nom);
    if (isChecked){
        radioboxSingle->check();
    }
    this->radioboxes.append(radioboxSingle);
}

QList<RadioboxSingle*> Radiobox::recupererRadioBoxes(){
    return this->radioboxes;
}

QString RadioboxSingle::recupererNom(){
    return this->nom;
}

bool RadioboxSingle::recupererIsChecked(){
    return this->isChecked;
}

QString Radiobox::classname(){
    return "Radiobox";
}
