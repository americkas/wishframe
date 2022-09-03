#include "listederoulante.h"

ElementListe::ElementListe(QString nom)
    :nom(nom)
{
}

QString ElementListe::recupererNom(){
    return this->nom;
}

void ElementListe::modifierNom(QString nom){
    this->nom = nom;
}

ListeDeroulante::ListeDeroulante()
{
    ElementListe * element = new ElementListe("ac");
    this->elements.append(element);
}

void ListeDeroulante::ajouterElement(QString nom){
    ElementListe * element = new ElementListe(nom);
    this->elements.append(element);
}

QList<ElementListe*> ListeDeroulante::recupererElements(){
    return this->elements;
}

QString ListeDeroulante::classname(){
    return "ListeDeroulante";
}
