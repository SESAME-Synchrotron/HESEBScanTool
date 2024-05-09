#include "heseb_scantool_i0.h"
#include "ui_heseb_scantool_i0.h"

using namespace std;
string getLastLine(ifstream& in)
{
    string line;
    while (in >> ws && getline(in, line)) // skip empty lines
        ;

    return line;
}

HESEB_ScanTool_I0::HESEB_ScanTool_I0(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HESEB_ScanTool_I0)
{
    ui->setupUi(this);

    checkLogs = new QTimer(this);
    this->checkLogs->start(100);
    connect(checkLogs,SIGNAL(timeout()),this,SLOT(logs()));

    checkPath = new QTimer(this);
    this->checkPath->start(500);
    connect(checkPath,SIGNAL(timeout()),this,SLOT(path()));

    ui->scanStatusPV->setHidden(true);
}

HESEB_ScanTool_I0::~HESEB_ScanTool_I0()
{
    delete ui;
}

void HESEB_ScanTool_I0::on_SEDPathDir_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Open",SED_Path);
    QDesktopServices::openUrl(QUrl(file, QUrl::TolerantMode));
}

void HESEB_ScanTool_I0::logs()
{
    ifstream file("/home/control/HESEBScanTool/SED_Scantool.log");

       if (file)
       {
           string line = getLastLine(file);
           QString log = QString::fromUtf8(line.c_str());
           ui->logs->setText(log);
       }
}

void HESEB_ScanTool_I0::path()
{
    ifstream file("/home/control/HESEBScanTool/tmp/SEDPath.txt");

       if (file)
       {
           string line = getLastLine(file);
           SED_Path = QString::fromUtf8(line.c_str());
           ui->SEDPathVal->setText(SED_Path);
       }
}

void HESEB_ScanTool_I0::on_plotter_coordinateSelected(const QPointF &xyvalue)
{
    ui->xy->setText(QString("X: %1, Y: %2").arg(xyvalue.x()).arg(xyvalue.y()));

    if(ui->lineDashed->checkState() == Qt::Checked)
        ui->plotter->setXYLineDashed(1, true);
    else
        ui->plotter->setXYLineDashed(1, false);

    if(ui->lineHasDots->checkState() == Qt::Checked)
        ui->plotter->setXYLineHasDots(1, true);
    else
        ui->plotter->setXYLineHasDots(1, false);
}

void HESEB_ScanTool_I0::on_readMorePVs_clicked()
{
    if(!isOpened){
        morevar = new moreVar(this);
        morevar->setAttribute(Qt::WA_DeleteOnClose);
        connect(morevar, &QObject::destroyed, this, &HESEB_ScanTool_I0::on_readMorePVs_closed);
        morevar->show();
        isOpened = true;
    }
}

void HESEB_ScanTool_I0::on_readMorePVs_closed()
{
    isOpened = false;
}

void HESEB_ScanTool_I0::on_scanStatusPV_dbValueChanged(bool out)
{
    ui->scanStatus->setText(out ? "Finished" : "Running");
    ui->scanStatusSymbol->setFlash1Property(out);
    ui->scanStatusSymbol->setFlashRate(QEScanTimers::Slow);
}
