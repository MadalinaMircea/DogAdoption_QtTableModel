/****************************************************************************
** Meta object code from reading C++ file 'GUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUI_t {
    QByteArrayData data[17];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUI_t qt_meta_stringdata_GUI = {
    {
QT_MOC_LITERAL(0, 0, 3), // "GUI"
QT_MOC_LITERAL(1, 4, 17), // "updatedDogsSignal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 18), // "updatedAdoptSignal"
QT_MOC_LITERAL(4, 42, 19), // "addDogButtonHandler"
QT_MOC_LITERAL(5, 62, 22), // "deleteDogButtonHandler"
QT_MOC_LITERAL(6, 85, 22), // "updateDogButtonHandler"
QT_MOC_LITERAL(7, 108, 21), // "seePhotoButtonHandler"
QT_MOC_LITERAL(8, 130, 18), // "adoptButtonHandler"
QT_MOC_LITERAL(9, 149, 20), // "openCSVButtonHandler"
QT_MOC_LITERAL(10, 170, 21), // "openHTMLButtonHandler"
QT_MOC_LITERAL(11, 192, 19), // "sortedButtonHandler"
QT_MOC_LITERAL(12, 212, 21), // "shuffledButtonHandler"
QT_MOC_LITERAL(13, 234, 4), // "plot"
QT_MOC_LITERAL(14, 239, 17), // "undoButtonHandler"
QT_MOC_LITERAL(15, 257, 17), // "redoButtonHandler"
QT_MOC_LITERAL(16, 275, 22) // "showTableButtonHandler"

    },
    "GUI\0updatedDogsSignal\0\0updatedAdoptSignal\0"
    "addDogButtonHandler\0deleteDogButtonHandler\0"
    "updateDogButtonHandler\0seePhotoButtonHandler\0"
    "adoptButtonHandler\0openCSVButtonHandler\0"
    "openHTMLButtonHandler\0sortedButtonHandler\0"
    "shuffledButtonHandler\0plot\0undoButtonHandler\0"
    "redoButtonHandler\0showTableButtonHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    1,   98,    2, 0x0a /* Public */,
      12,    1,  101,    2, 0x0a /* Public */,
      13,    0,  104,    2, 0x0a /* Public */,
      14,    0,  105,    2, 0x0a /* Public */,
      15,    0,  106,    2, 0x0a /* Public */,
      16,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUI *_t = static_cast<GUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatedDogsSignal(); break;
        case 1: _t->updatedAdoptSignal(); break;
        case 2: _t->addDogButtonHandler(); break;
        case 3: _t->deleteDogButtonHandler(); break;
        case 4: _t->updateDogButtonHandler(); break;
        case 5: _t->seePhotoButtonHandler(); break;
        case 6: _t->adoptButtonHandler(); break;
        case 7: _t->openCSVButtonHandler(); break;
        case 8: _t->openHTMLButtonHandler(); break;
        case 9: _t->sortedButtonHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->shuffledButtonHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->plot(); break;
        case 12: _t->undoButtonHandler(); break;
        case 13: _t->redoButtonHandler(); break;
        case 14: _t->showTableButtonHandler(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI::updatedDogsSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (GUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI::updatedAdoptSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject GUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GUI.data,
      qt_meta_data_GUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUI.stringdata0))
        return static_cast<void*>(const_cast< GUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int GUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void GUI::updatedDogsSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void GUI::updatedAdoptSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
