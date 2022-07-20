/****************************************************************************
** Meta object code from reading C++ file 'heseb_scantool_livedataplotting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HESEB_ScanTool_LiveDataPlotting/heseb_scantool_livedataplotting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'heseb_scantool_livedataplotting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HESEB_ScanTool_LiveDataPlotting_t {
    QByteArrayData data[7];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HESEB_ScanTool_LiveDataPlotting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HESEB_ScanTool_LiveDataPlotting_t qt_meta_stringdata_HESEB_ScanTool_LiveDataPlotting = {
    {
QT_MOC_LITERAL(0, 0, 31), // "HESEB_ScanTool_LiveDataPlotting"
QT_MOC_LITERAL(1, 32, 13), // "on_I0_clicked"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 13), // "on_It_clicked"
QT_MOC_LITERAL(4, 61, 16), // "on_I0_It_clicked"
QT_MOC_LITERAL(5, 78, 15), // "on_help_clicked"
QT_MOC_LITERAL(6, 94, 5) // "check"

    },
    "HESEB_ScanTool_LiveDataPlotting\0"
    "on_I0_clicked\0\0on_It_clicked\0"
    "on_I0_It_clicked\0on_help_clicked\0check"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HESEB_ScanTool_LiveDataPlotting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HESEB_ScanTool_LiveDataPlotting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HESEB_ScanTool_LiveDataPlotting *_t = static_cast<HESEB_ScanTool_LiveDataPlotting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_I0_clicked(); break;
        case 1: _t->on_It_clicked(); break;
        case 2: _t->on_I0_It_clicked(); break;
        case 3: _t->on_help_clicked(); break;
        case 4: _t->check(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HESEB_ScanTool_LiveDataPlotting::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HESEB_ScanTool_LiveDataPlotting.data,
      qt_meta_data_HESEB_ScanTool_LiveDataPlotting,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HESEB_ScanTool_LiveDataPlotting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HESEB_ScanTool_LiveDataPlotting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HESEB_ScanTool_LiveDataPlotting.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int HESEB_ScanTool_LiveDataPlotting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
