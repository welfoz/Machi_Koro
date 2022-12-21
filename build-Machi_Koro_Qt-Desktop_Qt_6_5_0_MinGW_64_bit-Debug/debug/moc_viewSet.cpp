/****************************************************************************
** Meta object code from reading C++ file 'viewSet.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Qt/viewSet.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
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
struct qt_meta_stringdata_ViewSet_t {};
static constexpr auto qt_meta_stringdata_ViewSet = QtMocHelpers::stringData(
    "ViewSet",
    "cardClick",
    "",
    "ViewCard*",
    "vc",
    "monumentClick",
    "ViewMonument*",
    "vm",
    "diceClick",
    "ViewDice*",
    "vd"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_ViewSet_t {
    uint offsetsAndSizes[22];
    char stringdata0[8];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[3];
    char stringdata5[14];
    char stringdata6[14];
    char stringdata7[3];
    char stringdata8[10];
    char stringdata9[10];
    char stringdata10[3];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ViewSet_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ViewSet_t qt_meta_stringdata_ViewSet = {
    {
        QT_MOC_LITERAL(0, 7),  // "ViewSet"
        QT_MOC_LITERAL(8, 9),  // "cardClick"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 9),  // "ViewCard*"
        QT_MOC_LITERAL(29, 2),  // "vc"
        QT_MOC_LITERAL(32, 13),  // "monumentClick"
        QT_MOC_LITERAL(46, 13),  // "ViewMonument*"
        QT_MOC_LITERAL(60, 2),  // "vm"
        QT_MOC_LITERAL(63, 9),  // "diceClick"
        QT_MOC_LITERAL(73, 9),  // "ViewDice*"
        QT_MOC_LITERAL(83, 2)   // "vd"
    },
    "ViewSet",
    "cardClick",
    "",
    "ViewCard*",
    "vc",
    "monumentClick",
    "ViewMonument*",
    "vm",
    "diceClick",
    "ViewDice*",
    "vd"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ViewSet[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x08,    1 /* Private */,
       5,    1,   35,    2, 0x08,    3 /* Private */,
       8,    1,   38,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject ViewSet::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ViewSet.offsetsAndSizes,
    qt_meta_data_ViewSet,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ViewSet_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ViewSet, std::true_type>,
        // method 'cardClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ViewCard *, std::false_type>,
        // method 'monumentClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ViewMonument *, std::false_type>,
        // method 'diceClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ViewDice *, std::false_type>
    >,
    nullptr
} };

void ViewSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ViewSet *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->cardClick((*reinterpret_cast< std::add_pointer_t<ViewCard*>>(_a[1]))); break;
        case 1: _t->monumentClick((*reinterpret_cast< std::add_pointer_t<ViewMonument*>>(_a[1]))); break;
        case 2: _t->diceClick((*reinterpret_cast< std::add_pointer_t<ViewDice*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ViewCard* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ViewMonument* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ViewDice* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *ViewSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewSet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ViewSet.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ViewSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
