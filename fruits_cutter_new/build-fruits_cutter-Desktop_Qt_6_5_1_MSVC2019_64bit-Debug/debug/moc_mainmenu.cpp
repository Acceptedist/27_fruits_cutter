/****************************************************************************
** Meta object code from reading C++ file 'mainmenu.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../fruits_cutter/mainmenu.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSmainmenuENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSmainmenuENDCLASS = QtMocHelpers::stringData(
    "mainmenu",
    "cutslot",
    "",
    "std::string",
    "name",
    "delclassic",
    "del",
    "NO",
    "Dehealth",
    "cutcheck",
    "reset",
    "helpbuttonclick",
    "tipsbuttonclick"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSmainmenuENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[9];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[5];
    char stringdata5[11];
    char stringdata6[4];
    char stringdata7[3];
    char stringdata8[9];
    char stringdata9[9];
    char stringdata10[6];
    char stringdata11[16];
    char stringdata12[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSmainmenuENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSmainmenuENDCLASS_t qt_meta_stringdata_CLASSmainmenuENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "mainmenu"
        QT_MOC_LITERAL(9, 7),  // "cutslot"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 11),  // "std::string"
        QT_MOC_LITERAL(30, 4),  // "name"
        QT_MOC_LITERAL(35, 10),  // "delclassic"
        QT_MOC_LITERAL(46, 3),  // "del"
        QT_MOC_LITERAL(50, 2),  // "NO"
        QT_MOC_LITERAL(53, 8),  // "Dehealth"
        QT_MOC_LITERAL(62, 8),  // "cutcheck"
        QT_MOC_LITERAL(71, 5),  // "reset"
        QT_MOC_LITERAL(77, 15),  // "helpbuttonclick"
        QT_MOC_LITERAL(93, 15)   // "tipsbuttonclick"
    },
    "mainmenu",
    "cutslot",
    "",
    "std::string",
    "name",
    "delclassic",
    "del",
    "NO",
    "Dehealth",
    "cutcheck",
    "reset",
    "helpbuttonclick",
    "tipsbuttonclick"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmainmenuENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x0a,    1 /* Public */,
       5,    0,   65,    2, 0x0a,    3 /* Public */,
       6,    1,   66,    2, 0x0a,    4 /* Public */,
       8,    0,   69,    2, 0x0a,    6 /* Public */,
       9,    1,   70,    2, 0x0a,    7 /* Public */,
      10,    0,   73,    2, 0x0a,    9 /* Public */,
      11,    0,   74,    2, 0x0a,   10 /* Public */,
      12,    0,   75,    2, 0x0a,   11 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject mainmenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_CLASSmainmenuENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmainmenuENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmainmenuENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<mainmenu, std::true_type>,
        // method 'cutslot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'delclassic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'del'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'Dehealth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cutcheck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'reset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'helpbuttonclick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tipsbuttonclick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void mainmenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainmenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->cutslot((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 1: _t->delclassic(); break;
        case 2: _t->del((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->Dehealth(); break;
        case 4: _t->cutcheck((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 5: _t->reset(); break;
        case 6: _t->helpbuttonclick(); break;
        case 7: _t->tipsbuttonclick(); break;
        default: ;
        }
    }
}

const QMetaObject *mainmenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainmenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmainmenuENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int mainmenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
