/****************************************************************************
** Meta object code from reading C++ file 'mrp.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MRP_CRP/mrp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mrp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRP_t {
    const uint offsetsAndSize[34];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MRP_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MRP_t qt_meta_stringdata_MRP = {
    {
QT_MOC_LITERAL(0, 3), // "MRP"
QT_MOC_LITERAL(4, 16), // "on_Salir_clicked"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 27), // "on_pushButton_Excel_clicked"
QT_MOC_LITERAL(50, 19), // "on_Ejecutar_clicked"
QT_MOC_LITERAL(70, 3), // "LaL"
QT_MOC_LITERAL(74, 1), // "a"
QT_MOC_LITERAL(76, 4), // "PCTE"
QT_MOC_LITERAL(81, 3), // "EOQ"
QT_MOC_LITERAL(85, 3), // "POQ"
QT_MOC_LITERAL(89, 2), // "PF"
QT_MOC_LITERAL(92, 3), // "MCU"
QT_MOC_LITERAL(96, 3), // "MCT"
QT_MOC_LITERAL(100, 2), // "SM"
QT_MOC_LITERAL(103, 12), // "actualizarui"
QT_MOC_LITERAL(116, 5), // "lotes"
QT_MOC_LITERAL(122, 25) // "on_pushButton_CRP_clicked"

    },
    "MRP\0on_Salir_clicked\0\0on_pushButton_Excel_clicked\0"
    "on_Ejecutar_clicked\0LaL\0a\0PCTE\0EOQ\0"
    "POQ\0PF\0MCU\0MCT\0SM\0actualizarui\0lotes\0"
    "on_pushButton_CRP_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRP[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    0,   94,    2, 0x08,    3 /* Private */,
       5,    1,   95,    2, 0x08,    4 /* Private */,
       7,    0,   98,    2, 0x08,    6 /* Private */,
       8,    0,   99,    2, 0x08,    7 /* Private */,
       9,    0,  100,    2, 0x08,    8 /* Private */,
      10,    0,  101,    2, 0x08,    9 /* Private */,
      11,    0,  102,    2, 0x08,   10 /* Private */,
      12,    0,  103,    2, 0x08,   11 /* Private */,
      13,    0,  104,    2, 0x08,   12 /* Private */,
      14,    2,  105,    2, 0x08,   13 /* Private */,
      16,    0,  110,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,    6,
    QMetaType::Void,

       0        // eod
};

void MRP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MRP *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_Salir_clicked(); break;
        case 1: _t->on_pushButton_Excel_clicked(); break;
        case 2: _t->on_Ejecutar_clicked(); break;
        case 3: _t->LaL((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->PCTE(); break;
        case 5: _t->EOQ(); break;
        case 6: _t->POQ(); break;
        case 7: _t->PF(); break;
        case 8: _t->MCU(); break;
        case 9: _t->MCT(); break;
        case 10: _t->SM(); break;
        case 11: _t->actualizarui((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->on_pushButton_CRP_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MRP::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MRP.offsetsAndSize,
    qt_meta_data_MRP,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MRP_t
, QtPrivate::TypeAndForceComplete<MRP, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MRP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MRP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MRP.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MRP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
