#include "heseb_scantool_i0vstime.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HESEB_ScanTool_I0vsTime w;
    w.show();
    return a.exec();
}
