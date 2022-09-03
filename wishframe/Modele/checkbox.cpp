#include "checkbox.h"

Checkbox::Checkbox()
    :checked(false)
{

}
void Checkbox::check(){
    this->checked = !(this->checked);
}

void Checkbox::modifierNom(QString nom){
    this->nom = nom;
}

QString Checkbox::recupererNom(){
    return this->nom;
}
bool Checkbox::recupererChecked(){
    return this->checked;
}

QString Checkbox::classname(){
    return "Checkbox";
}
