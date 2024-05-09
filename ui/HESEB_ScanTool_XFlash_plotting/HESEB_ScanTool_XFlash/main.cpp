#include "heseb_scantool_xfalsh.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    heseb_Scantool_xfalsh w;
    w.show();
    return a.exec();
}
