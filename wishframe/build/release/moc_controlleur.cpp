/****************************************************************************
** Meta object code from reading C++ file 'controlleur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../controlleur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlleur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controlleur_t {
    QByteArrayData data[18];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controlleur_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controlleur_t qt_meta_stringdata_Controlleur = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Controlleur"
QT_MOC_LITERAL(1, 12, 12), // "nouvellePage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "ajouterComposant"
QT_MOC_LITERAL(4, 43, 13), // "Typecomposant"
QT_MOC_LITERAL(5, 57, 9), // "composant"
QT_MOC_LITERAL(6, 67, 17), // "modifierComposant"
QT_MOC_LITERAL(7, 85, 10), // "Composant*"
QT_MOC_LITERAL(8, 96, 8), // "QWidget*"
QT_MOC_LITERAL(9, 105, 6), // "widget"
QT_MOC_LITERAL(10, 112, 9), // "supprPage"
QT_MOC_LITERAL(11, 122, 5), // "Page*"
QT_MOC_LITERAL(12, 128, 4), // "page"
QT_MOC_LITERAL(13, 133, 14), // "chargerFichier"
QT_MOC_LITERAL(14, 148, 4), // "lien"
QT_MOC_LITERAL(15, 153, 11), // "DragWidget*"
QT_MOC_LITERAL(16, 165, 10), // "dragwidget"
QT_MOC_LITERAL(17, 176, 14) // "supprComposant"

    },
    "Controlleur\0nouvellePage\0\0ajouterComposant\0"
    "Typecomposant\0composant\0modifierComposant\0"
    "Composant*\0QWidget*\0widget\0supprPage\0"
    "Page*\0page\0chargerFichier\0lien\0"
    "DragWidget*\0dragwidget\0supprComposant"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controlleur[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       6,    2,   48,    2, 0x0a /* Public */,
      10,    1,   53,    2, 0x0a /* Public */,
      13,    2,   56,    2, 0x0a /* Public */,
      17,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 8,    5,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 7,    5,

       0        // eod
};

void Controlleur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controlleur *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nouvellePage(); break;
        case 1: _t->ajouterComposant((*reinterpret_cast< Typecomposant(*)>(_a[1]))); break;
        case 2: _t->modifierComposant((*reinterpret_cast< Composant*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 3: _t->supprPage((*reinterpret_cast< Page*(*)>(_a[1]))); break;
        case 4: _t->chargerFichier((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DragWidget*(*)>(_a[2]))); break;
        case 5: _t->supprComposant((*reinterpret_cast< Composant*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Composant* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Page* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Composant* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Controlleur::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Controlleur.data,
    qt_meta_data_Controlleur,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controlleur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controlleur::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controlleur.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controlleur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
