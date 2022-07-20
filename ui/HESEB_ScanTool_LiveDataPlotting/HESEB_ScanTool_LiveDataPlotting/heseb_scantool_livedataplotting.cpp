#include "heseb_scantool_livedataplotting.h"
#include "ui_heseb_scantool_livedataplotting.h"

#include <qobject.h>
#include <QObject>
#include <QDesktopServices>
#include <QUrl>

HESEB_ScanTool_LiveDataPlotting::HESEB_ScanTool_LiveDataPlotting(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HESEB_ScanTool_LiveDataPlotting)
{
    ui->setupUi(this);

    this->I0_run     = new QEpicsPV("I0:RUN");
    this->It_run     = new QEpicsPV("It:RUN");

    this->timer = new QTimer;
    this->timer->start(500);

    interlock = 0;

    connect(this->timer,SIGNAL(timeout()),this, SLOT(check()));
}

HESEB_ScanTool_LiveDataPlotting::~HESEB_ScanTool_LiveDataPlotting()
{
    delete ui;
}

void HESEB_ScanTool_LiveDataPlotting::on_I0_clicked()
{
    I0 = new HESEB_ScanTool_I0vsTime(this);
    I0->show();
}

void HESEB_ScanTool_LiveDataPlotting::on_It_clicked()
{
    Itrans = new HESEB_ScanTool_ItvsTime(this);
    Itrans->show();
}

void HESEB_ScanTool_LiveDataPlotting::on_I0_It_clicked()
{
    I0_Itrans = new HESEB_ScanTool_I0_ItvsTime(this);
//    I0_Itrans->show();
    interlock = 1;
}

void HESEB_ScanTool_LiveDataPlotting::on_help_clicked()
{
    help = new Help(this);
//    help->show();
    QDesktopServices::openUrl(QUrl("https://hesebscantool.readthedocs.io/en/latest/runScan.html#live-data-plotting"));
}

void HESEB_ScanTool_LiveDataPlotting::check()
{
    if (this->I0_run->get().toFloat() == 0)
    {
        ui->I0_sts->setText("In Process ...");
    }

    else
        ui->I0_sts->setText("Stopped");

    if (this->It_run->get().toFloat() == 0)
    {
        ui->It_sts->setText("In Process ...");
    }

    else
        ui->It_sts->setText("Stopped");

    if (this->It_run->get().toFloat() == 0 and this->I0_run->get().toFloat() == 0 and interlock == 1)
    {
//        ui->both_sts->setText("In Process ...");
        ui->I0->setEnabled(false);
        ui->It->setEnabled(false);
    }

    else
    {
//        ui->both_sts->setText("Stopped");
        ui->I0->setEnabled(true);
        ui->It->setEnabled(true);
    }

    if ((this->It_run->get().toFloat() == 0 or this->I0_run->get().toFloat() == 0))
        ui->I0_It->setEnabled(false);
    else
        ui->I0_It->setEnabled(true);
}
