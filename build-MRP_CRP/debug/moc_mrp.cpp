/****************************************************************************
** Meta object code from reading C++ file 'mrp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MRP_CRP/mrp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mrp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MRP_t {
    QByteArrayData data[18];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MRP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MRP_t qt_meta_stringdata_MRP = {
    {
QT_MOC_LITERAL(0, 0, 3), // "MRP"
QT_MOC_LITERAL(1, 4, 16), // "on_Salir_clicked"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 27), // "on_pushButton_Excel_clicked"
QT_MOC_LITERAL(4, 50, 19), // "on_Ejecutar_clicked"
QT_MOC_LITERAL(5, 70, 3), // "LaL"
QT_MOC_LITERAL(6, 74, 1), // "a"
QT_MOC_LITERAL(7, 76, 4), // "PCTE"
QT_MOC_LITERAL(8, 81, 3), // "EOQ"
QT_MOC_LITERAL(9, 85, 3), // "POQ"
QT_MOC_LITERAL(10, 89, 2), // "PF"
QT_MOC_LITERAL(11, 92, 3), // "MCU"
QT_MOC_LITERAL(12, 96, 3), // "MCT"
QT_MOC_LITERAL(13, 100, 2), // "SM"
QT_MOC_LITERAL(14, 103, 12), // "actualizarui"
QT_MOC_LITERAL(15, 116, 5), // "lotes"
QT_MOC_LITERAL(16, 122, 25), // "on_pushButton_CRP_clicked"
QT_MOC_LITERAL(17, 148, 19) // "on_Exportar_clicked"

    },
    "MRP\0on_Salir_clicked\0\0on_pushButton_Excel_clicked\0"
    "on_Ejecutar_clicked\0LaL\0a\0PCTE\0EOQ\0"
    "POQ\0PF\0MCU\0MCT\0SM\0actualizarui\0lotes\0"
    "on_pushButton_CRP_clicked\0on_Exportar_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MRP[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    1,   87,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    2,   97,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,

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
    QMetaType::Void,

       0        // eod
};

void MRP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MRP *>(_o);
        Q_UNUSED(_t)
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
        case 13: _t->on_Exportar_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MRP::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MRP.data,
    qt_meta_data_MRP,
    qt_static_metacall,
    nullptr,
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
