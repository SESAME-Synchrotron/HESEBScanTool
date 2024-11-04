#include "heseb_scantool_livedataplotting.h"
#include "ui_heseb_scantool_livedataplotting.h"

HESEB_ScanTool_LiveDataPlotting::HESEB_ScanTool_LiveDataPlotting(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HESEB_ScanTool_LiveDataPlotting)
{
    ui->setupUi(this);

    ui->I0_It->setEnabled(false);

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
    if(!isI0Opened){
        I0 = new HESEB_ScanTool_I0vsTime(this);
        I0->setAttribute(Qt::WA_DeleteOnClose);
        connect(I0, &QObject::destroyed, this, &HESEB_ScanTool_LiveDataPlotting::on_I0_closed);
        I0->show();
        isI0Opened = true;
    }
}

void HESEB_ScanTool_LiveDataPlotting::on_I0_closed()
{
    isI0Opened = false;
}

void HESEB_ScanTool_LiveDataPlotting::on_It_clicked()
{
    if(!isItOpened){
        Itrans = new HESEB_ScanTool_ItvsTime(this);
        Itrans->setAttribute(Qt::WA_DeleteOnClose);
        connect(Itrans, &QObject::destroyed, this, &HESEB_ScanTool_LiveDataPlotting::on_I0_closed);
        Itrans->show();
        isItOpened = true;
    }
}

void HESEB_ScanTool_LiveDataPlotting::on_It_closed()
{
    isItOpened = false;
}

void HESEB_ScanTool_LiveDataPlotting::on_I0_It_clicked()
{
    if(!isI0ItOpened){
        I0_Itrans = new HESEB_ScanTool_I0_ItvsTime(this);
        I0_Itrans->setAttribute(Qt::WA_DeleteOnClose);
        connect(I0_Itrans, &QObject::destroyed, this, &HESEB_ScanTool_LiveDataPlotting::on_I0_closed);
        //    I0_Itrans->show();
        interlock = 1;
        isI0ItOpened = true;
    }
}

void HESEB_ScanTool_LiveDataPlotting::on_I0_It_closed()
{
    isI0ItOpened = false;
}

void HESEB_ScanTool_LiveDataPlotting::on_help_clicked()
{
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

void HESEB_ScanTool_LiveDataPlotting::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape) {
        Client::writePV("VOLTAGE:VALIDATION", 1);
        this->close();
    }
}

void HESEB_ScanTool_LiveDataPlotting::closeEvent(QCloseEvent *event)
{
    Client::writePV("VOLTAGE:VALIDATION", 1);
    this->close();
}

void HESEB_ScanTool_LiveDataPlotting::on_qecheckbox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        Client::writePV("SCAN:STOP", 0);
    }
    else
    {
        Client::writePV("SCAN:STOP", 1);
    }
}
