#include "image.h"

Image::Image()
    :lienImg("")//TODO A revoir
{

}

void Image::modifierLienImg(QString lien){
    this->lienImg = lien;
}

QString Image::recupererLienImg(){
    return this->lienImg;
}

QString Image::classname(){
    return "Image";
}
