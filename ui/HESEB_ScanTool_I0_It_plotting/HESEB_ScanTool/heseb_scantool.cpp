#include "heseb_scantool.h"
#include "ui_heseb_scantool.h"

using namespace std;
string getLastLine(ifstream& in)
{
    string line;
    while (in >> ws && getline(in, line)) // skip empty lines
        ;

    return line;
}

HESEB_ScanTool::HESEB_ScanTool(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HESEB_ScanTool)
{
    ui->setupUi(this);

    checkLogs = new QTimer(this);
    this->checkLogs->start(100);
    connect(checkLogs,SIGNAL(timeout()),this,SLOT(logs()));

    checkPath = new QTimer(this);
    this->checkPath->start(500);
    connect(checkPath,SIGNAL(timeout()),this,SLOT(path()));
}

HESEB_ScanTool::~HESEB_ScanTool()
{
    delete ui;
}

void HESEB_ScanTool::on_SEDPathDir_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Open",SED_Path);
    QDesktopServices::openUrl(QUrl(file, QUrl::TolerantMode));
}

void HESEB_ScanTool::logs()
{
    ifstream file("/home/control/HESEBScanTool/SED_Scantool.log");

       if (file)
       {
           string line = getLastLine(file);
           QString log = QString::fromUtf8(line.c_str());
           ui->logs->setText(log);
       }
}

void HESEB_ScanTool::path()
{
    ifstream file("/home/control/HESEBScanTool/tmp/SEDPath.txt");

       if (file)
       {
           string line = getLastLine(file);
           SED_Path = QString::fromUtf8(line.c_str());
           ui->SEDPathVal->setText(SED_Path);
       }
}

void HESEB_ScanTool::on_I0ItransPlotter_coordinateSelected(const QPointF &xyvalue)
{
    ui->xyI0Itrans->setText(QString("X: %1, Y: %2").arg(xyvalue.x()).arg(xyvalue.y()));
}

void HESEB_ScanTool::on_IrefPlotter_coordinateSelected(const QPointF &xyvalue)
{
    ui->xyIref->setText(QString("X: %1, Y: %2").arg(xyvalue.x()).arg(xyvalue.y()));
}

void HESEB_ScanTool::on_morevar_clicked()
{
    if(!isOpened){
        morevar = new moreVar(this);
        morevar->setAttribute(Qt::WA_DeleteOnClose);
        connect(morevar, &QObject::destroyed, this, &HESEB_ScanTool::on_morevar_closed);
        morevar->show();
        isOpened = true;
    }
}

void HESEB_ScanTool::on_morevar_closed()
{
    isOpened = false;
}
