#include "heseb_scantool.h"
#include "ui_heseb_scantool.h"
#include <QGraphicsRotation>

#include <QFileDialog>

HESEB_ScanTool::HESEB_ScanTool(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HESEB_ScanTool)
{
    ui->setupUi(this);
}

HESEB_ScanTool::~HESEB_ScanTool()
{
    delete ui;
}


void HESEB_ScanTool::on_pushButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Open", "/home");
}
