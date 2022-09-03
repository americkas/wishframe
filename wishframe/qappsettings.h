#ifndef QAPPSETTINGS_H
#define QAPPSETTINGS_H

#include <QSettings>
#include <QLocale>
#include <QTranslator>
#include <QApplication>

class QAppSettings : public QObject
{
Q_OBJECT
public:
    QAppSettings();
private:
    // --------------------------------------------------------------------
    // Paramètres constants
    // --------------------------------------------------------------------
    /**
     * Nom Organisation
     */
    static const QString organisationName;

    /**
     * Nom Application
     */
    static const QString applicationName;


};



#endif // QAPPSETTINGS_H
