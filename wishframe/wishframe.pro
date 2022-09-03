QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Affichage/dragwidget.cpp \
    Affichage/fenbouton.cpp \
    Affichage/fenchampdetexte.cpp \
    Affichage/fencheckbox.cpp \
    Affichage/fenimage.cpp \
    Affichage/fenlistederoulante.cpp \
    Affichage/fenradiobox.cpp \
    Affichage/fenrectangle.cpp \
    Modele/bouton.cpp \
    Modele/champdetexte.cpp \
    Modele/checkbox.cpp \
    Modele/composant.cpp \
    Modele/gestionnairepages.cpp \
    Modele/image.cpp \
    Modele/listederoulante.cpp \
    Modele/page.cpp \
    Modele/radiobox.cpp \
    Modele/rectangle.cpp \
    controlleur.cpp \
    frameless.cpp \
    main.cpp \
    mainwindow.cpp \
    qappsettings.cpp \

HEADERS += \
    Affichage/dragwidget.h \
    Affichage/fenbouton.h \
    Affichage/fenchampdetexte.h \
    Affichage/fencheckbox.h \
    Affichage/fenimage.h \
    Affichage/fenlistederoulante.h \
    Affichage/fenradiobox.h \
    Affichage/fenrectangle.h \
    Modele/bouton.h \
    Modele/champdetexte.h \
    Modele/checkbox.h \
    Modele/composant.h \
    Modele/gestionnairepages.h \
    Modele/image.h \
    Modele/listederoulante.h \
    Modele/page.h \
    Modele/radiobox.h \
    Modele/rectangle.h \
    controlleur.h \
    frameless.h \
    mainwindow.h \
    qappsettings.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    wishframe.qrc
