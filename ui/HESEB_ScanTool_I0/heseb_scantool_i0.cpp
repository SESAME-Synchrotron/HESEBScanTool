#include "heseb_scantool_i0.h"
#include "ui_heseb_scantool_i0.h"

#include <QFileDialog>
#include <qepicspv.h>
#include <QEString.h>
#include <qstring.h>

HESEB_ScanTool_I0::HESEB_ScanTool_I0(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HESEB_ScanTool_I0)
{
    ui->setupUi(this);

    this->ScanPath = new QEpicsPV("SCAN:PATH");

}

HESEB_ScanTool_I0::~HESEB_ScanTool_I0()
{
    delete ui;
}


void HESEB_ScanTool_I0::on_pushButton_3_clicked()
{
    QString path = this->ScanPath->get().toString();
    QString file = QFileDialog::getOpenFileName(this, "Open", path);
}
