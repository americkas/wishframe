/****************************************************************************
** Meta object code from reading C++ file 'fenbouton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../wishframe/Affichage/fenbouton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenbouton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FenBouton_t {
    QByteArrayData data[8];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FenBouton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FenBouton_t qt_meta_stringdata_FenBouton = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FenBouton"
QT_MOC_LITERAL(1, 10, 13), // "modifierChamp"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "champ"
QT_MOC_LITERAL(4, 31, 21), // "modifierPoliceCouleur"
QT_MOC_LITERAL(5, 53, 13), // "policeCouleur"
QT_MOC_LITERAL(6, 67, 20), // "modifierPoliceTaille"
QT_MOC_LITERAL(7, 88, 12) // "policeTaille"

    },
    "FenBouton\0modifierChamp\0\0champ\0"
    "modifierPoliceCouleur\0policeCouleur\0"
    "modifierPoliceTaille\0policeTaille"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenBouton[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       6,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void FenBouton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FenBouton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modifierChamp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->modifierPoliceCouleur((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->modifierPoliceTaille((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FenBouton::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenBouton::modifierChamp)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FenBouton::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenBouton::modifierPoliceCouleur)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FenBouton::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenBouton::modifierPoliceTaille)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FenBouton::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_FenBouton.data,
    qt_meta_data_FenBouton,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FenBouton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenBouton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenBouton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int FenBouton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FenBouton::modifierChamp(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FenBouton::modifierPoliceCouleur(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FenBouton::modifierPoliceTaille(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
