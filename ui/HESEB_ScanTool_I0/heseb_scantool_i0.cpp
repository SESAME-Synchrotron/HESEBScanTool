#include "heseb_scantool_i0.h"
#include "ui_heseb_scantool_i0.h"

HESEB_ScanTool_I0::HESEB_ScanTool_I0(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HESEB_ScanTool_I0)
{
    ui->setupUi(this);
}

HESEB_ScanTool_I0::~HESEB_ScanTool_I0()
{
    delete ui;
}
