/****************************************************************************
** Meta object code from reading C++ file 'heseb_scantool_i0vstime.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HESEB_ScanTool_LiveDataPlotting/heseb_scantool_i0vstime.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'heseb_scantool_i0vstime.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HESEB_ScanTool_I0vsTime_t {
    QByteArrayData data[6];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HESEB_ScanTool_I0vsTime_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HESEB_ScanTool_I0vsTime_t qt_meta_stringdata_HESEB_ScanTool_I0vsTime = {
    {
QT_MOC_LITERAL(0, 0, 23), // "HESEB_ScanTool_I0vsTime"
QT_MOC_LITERAL(1, 24, 27), // "on_Int_time_editingFinished"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 16), // "on_Start_clicked"
QT_MOC_LITERAL(4, 70, 15), // "on_Stop_clicked"
QT_MOC_LITERAL(5, 86, 21) // "on_pushButton_clicked"

    },
    "HESEB_ScanTool_I0vsTime\0"
    "on_Int_time_editingFinished\0\0"
    "on_Start_clicked\0on_Stop_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HESEB_ScanTool_I0vsTime[] = {

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

void HESEB_ScanTool_I0vsTime::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HESEB_ScanTool_I0vsTime *_t = static_cast<HESEB_ScanTool_I0vsTime *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Int_time_editingFinished(); break;
        case 1: _t->on_Start_clicked(); break;
        case 2: _t->on_Stop_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HESEB_ScanTool_I0vsTime::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_HESEB_ScanTool_I0vsTime.data,
      qt_meta_data_HESEB_ScanTool_I0vsTime,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HESEB_ScanTool_I0vsTime::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HESEB_ScanTool_I0vsTime::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HESEB_ScanTool_I0vsTime.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int HESEB_ScanTool_I0vsTime::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
