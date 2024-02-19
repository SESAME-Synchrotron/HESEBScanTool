#include "heseb_scantool_i0.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HESEB_ScanTool_I0 w;
    w.show();
    return a.exec();
}
