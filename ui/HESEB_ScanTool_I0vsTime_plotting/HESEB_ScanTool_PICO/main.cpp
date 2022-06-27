#include "heseb_scantool_pico.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HESEB_ScanTool_PICO w;
    w.show();
    return a.exec();
}
