/****************************************************************************
** Meta object code from reading C++ file 'viewSetting.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Qt/viewSetting.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewSetting.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ViewSetting_t {};
static constexpr auto qt_meta_stringdata_ViewSetting = QtMocHelpers::stringData(
    "ViewSetting",
    "clickValidateText",
    "",
    "clickValidateNumber",
    "clickYes",
    "clickNo"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_ViewSetting_t {
    uint offsetsAndSizes[12];
    char stringdata0[12];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[9];
    char stringdata5[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ViewSetting_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ViewSetting_t qt_meta_stringdata_ViewSetting = {
    {
        QT_MOC_LITERAL(0, 11),  // "ViewSetting"
        QT_MOC_LITERAL(12, 17),  // "clickValidateText"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 19),  // "clickValidateNumber"
        QT_MOC_LITERAL(51, 8),  // "clickYes"
        QT_MOC_LITERAL(60, 7)   // "clickNo"
    },
    "ViewSetting",
    "clickValidateText",
    "",
    "clickValidateNumber",
    "clickYes",
    "clickNo"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ViewSetting[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x0a,    1 /* Public */,
       3,    0,   39,    2, 0x0a,    2 /* Public */,
       4,    0,   40,    2, 0x0a,    3 /* Public */,
       5,    0,   41,    2, 0x0a,    4 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ViewSetting::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ViewSetting.offsetsAndSizes,
    qt_meta_data_ViewSetting,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ViewSetting_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ViewSetting, std::true_type>,
        // method 'clickValidateText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clickValidateNumber'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clickYes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clickNo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ViewSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ViewSetting *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clickValidateText(); break;
        case 1: _t->clickValidateNumber(); break;
        case 2: _t->clickYes(); break;
        case 3: _t->clickNo(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ViewSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ViewSetting.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ViewSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
