/****************************************************************************
** Meta object code from reading C++ file 'crp.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MRP_CRP/crp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'crp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CRP_t {
    const uint offsetsAndSize[16];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CRP_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CRP_t qt_meta_stringdata_CRP = {
    {
QT_MOC_LITERAL(0, 3), // "CRP"
QT_MOC_LITERAL(4, 16), // "on_SALIR_clicked"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 19), // "on_Ejecutar_clicked"
QT_MOC_LITERAL(42, 12), // "actualizarui"
QT_MOC_LITERAL(55, 28), // "on_pushButton_ExcelA_clicked"
QT_MOC_LITERAL(84, 28), // "on_pushButton_ExcelB_clicked"
QT_MOC_LITERAL(113, 32) // "on_pushButton_ExcelComun_clicked"

    },
    "CRP\0on_SALIR_clicked\0\0on_Ejecutar_clicked\0"
    "actualizarui\0on_pushButton_ExcelA_clicked\0"
    "on_pushButton_ExcelB_clicked\0"
    "on_pushButton_ExcelComun_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRP[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CRP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CRP *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_SALIR_clicked(); break;
        case 1: _t->on_Ejecutar_clicked(); break;
        case 2: _t->actualizarui(); break;
        case 3: _t->on_pushButton_ExcelA_clicked(); break;
        case 4: _t->on_pushButton_ExcelB_clicked(); break;
        case 5: _t->on_pushButton_ExcelComun_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject CRP::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CRP.offsetsAndSize,
    qt_meta_data_CRP,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CRP_t
, QtPrivate::TypeAndForceComplete<CRP, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CRP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CRP.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CRP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
