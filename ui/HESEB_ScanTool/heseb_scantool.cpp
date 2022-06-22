#include "heseb_scantool.h"
#include "ui_heseb_scantool.h"

#include <QFileDialog>
#include <qepicspv.h>
#include <QEString.h>
#include <qstring.h>

HESEB_ScanTool::HESEB_ScanTool(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HESEB_ScanTool)
{
    ui->setupUi(this);

    this->ScanPath = new QEpicsPV("SCAN:PATH");

}

HESEB_ScanTool::~HESEB_ScanTool()
{
    delete ui;
}


void HESEB_ScanTool::on_pushButton_clicked()
{
    QString path = this->ScanPath->get().toString();
    QString file = QFileDialog::getOpenFileName(this, "Open", path);
}
