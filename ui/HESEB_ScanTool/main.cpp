#include "heseb_scantool.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HESEB_ScanTool w;
    w.show();
    return a.exec();
}
