/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu May 30 22:30:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ImProc_suite/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      47,   40,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      94,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     142,   11,   11,   11, 0x08,
     171,   11,   11,   11, 0x08,
     195,   11,   11,   11, 0x08,
     227,   11,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,
     281,   11,   11,   11, 0x08,
     307,   11,   11,   11, 0x08,
     348,  331,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_btnCannyFilter_clicked()\0"
    "qImage\0showImage(QImage*)\0"
    "on_btnSobelFilter_clicked()\0"
    "on_btnUmbBin_clicked()\0on_mnOpenImage_clicked()\0"
    "on_btnLoadDefImage_clicked()\0"
    "on_btnContour_clicked()\0"
    "on_btnSegWaterSheds_2_clicked()\0"
    "on_btnGaussFilter_clicked()\0"
    "on_btnContour_2_clicked()\0"
    "on_btnContour_3_clicked()\0"
    "on_btnKittler_clicked()\0descriptorValues\0"
    "displayHOGHistogram(vector<float>)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_btnCannyFilter_clicked(); break;
        case 1: _t->showImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 2: _t->on_btnSobelFilter_clicked(); break;
        case 3: _t->on_btnUmbBin_clicked(); break;
        case 4: _t->on_mnOpenImage_clicked(); break;
        case 5: _t->on_btnLoadDefImage_clicked(); break;
        case 6: _t->on_btnContour_clicked(); break;
        case 7: _t->on_btnSegWaterSheds_2_clicked(); break;
        case 8: _t->on_btnGaussFilter_clicked(); break;
        case 9: _t->on_btnContour_2_clicked(); break;
        case 10: _t->on_btnContour_3_clicked(); break;
        case 11: _t->on_btnKittler_clicked(); break;
        case 12: _t->displayHOGHistogram((*reinterpret_cast< vector<float>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
