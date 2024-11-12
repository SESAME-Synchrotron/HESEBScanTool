#include "heseb_scantool_livedataplotting.h"
#include "ui_heseb_scantool_livedataplotting.h"

HESEB_ScanTool_LiveDataPlotting::HESEB_ScanTool_LiveDataPlotting(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HESEB_ScanTool_LiveDataPlotting)
{
    ui->setupUi(this);
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

void HESEB_ScanTool_LiveDataPlotting::on_enableVoltageSource_stateChanged(int arg1)
{
    Client::writePV("HESEB:ScanStop", arg1 == Qt::Checked? 0 : 1);
}

void HESEB_ScanTool_LiveDataPlotting::on_help_clicked()
{
    QDesktopServices::openUrl(QUrl("https://hesebscantool.readthedocs.io/en/latest/runScan.html#live-data-plotting"));
}

void HESEB_ScanTool_LiveDataPlotting::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape) {
        Client::writePV(voltageValidation, 1);
        this->close();
    }
}

void HESEB_ScanTool_LiveDataPlotting::closeEvent(QCloseEvent *event)
{
    Client::writePV(voltageValidation, 1);
    this->close();
}
