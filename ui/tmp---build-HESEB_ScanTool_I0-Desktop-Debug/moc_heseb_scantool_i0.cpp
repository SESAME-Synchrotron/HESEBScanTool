/****************************************************************************
** Meta object code from reading C++ file 'heseb_scantool_i0.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HESEB_ScanTool_I0_plotting/HESEB_ScanTool_I0/heseb_scantool_i0.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'heseb_scantool_i0.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HESEB_ScanTool_I0_t {
    QByteArrayData data[6];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HESEB_ScanTool_I0_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HESEB_ScanTool_I0_t qt_meta_stringdata_HESEB_ScanTool_I0 = {
    {
QT_MOC_LITERAL(0, 0, 17), // "HESEB_ScanTool_I0"
QT_MOC_LITERAL(1, 18, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 4), // "logs"
QT_MOC_LITERAL(4, 48, 4), // "path"
QT_MOC_LITERAL(5, 53, 22) // "on_readMorePVs_clicked"

    },
    "HESEB_ScanTool_I0\0on_pushButton_3_clicked\0"
    "\0logs\0path\0on_readMorePVs_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HESEB_ScanTool_I0[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HESEB_ScanTool_I0::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HESEB_ScanTool_I0 *_t = static_cast<HESEB_ScanTool_I0 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_3_clicked(); break;
        case 1: _t->logs(); break;
        case 2: _t->path(); break;
        case 3: _t->on_readMorePVs_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HESEB_ScanTool_I0::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HESEB_ScanTool_I0.data,
      qt_meta_data_HESEB_ScanTool_I0,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HESEB_ScanTool_I0::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HESEB_ScanTool_I0::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HESEB_ScanTool_I0.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int HESEB_ScanTool_I0::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
