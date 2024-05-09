#include "heseb_scantool_xfalsh.h"
#include "ui_heseb_scantool_xfalsh.h"

heseb_Scantool_xfalsh::heseb_Scantool_xfalsh(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::heseb_Scantool_xfalsh)
{
    ui->setupUi(this);
}

heseb_Scantool_xfalsh::~heseb_Scantool_xfalsh()
{
    delete ui;
}


void heseb_Scantool_xfalsh::on_plotter_coordinateSelected(const QPointF &xyvalue)
{
    ui->xy->setText(QString("X: %1, Y: %2").arg(xyvalue.x()).arg(xyvalue.y()));

    bool val1 = ui->lineDashed->checkState() == Qt::Checked;
    ui->plotter->setXYLineDashed(1, val1);
    ui->plotter->setXYLineDashed(2, val1);

    bool val2 = ui->lineHasDots->checkState() == Qt::Checked;
    ui->plotter->setXYLineHasDots(1, val2);
    ui->plotter->setXYLineHasDots(2, val2);
}
