#include "heseb_scantool_livedataplotting.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HESEB_ScanTool_LiveDataPlotting w;
    w.show();
    return a.exec();
}
