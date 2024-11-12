#include "heseb_scantool_itvstime.h"
#include "ui_heseb_scantool_itvstime.h"

using namespace std;

HESEB_ScanTool_ItvsTime::HESEB_ScanTool_ItvsTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HESEB_ScanTool_ItvsTime)
{
    ui->setupUi(this);
    QDir::setCurrent(workingDir);
}

HESEB_ScanTool_ItvsTime::~HESEB_ScanTool_ItvsTime()
{
    delete ui;
}

void HESEB_ScanTool_ItvsTime::on_IntTime_textEdited(const QString &arg1)
{
    exists = validIntTimes.contains(arg1.trimmed().toFloat());
    ui->IntTime->setStyleSheet(exists? "" : "border: 2.25px solid red;");
}

void HESEB_ScanTool_ItvsTime::on_Start_clicked()
{
    if(exists)
    {
        Client::writePV(runIt, 1);
        std::string command = "python3.9 It_Acquire.py --time " + ui->IntTime->text().trimmed().toStdString() + " &";
        system(command.c_str());
        ui->Status->setText("In Process...");
    }
}

void HESEB_ScanTool_ItvsTime::on_Stop_clicked()
{
    ui->Status->setText("Stopped");
}

void HESEB_ScanTool_ItvsTime::on_plotter_coordinateSelected(const QPointF &xyvalue)
{
    ui->xy->setText(QString("X: %1, Y: %2").arg(xyvalue.x()).arg(xyvalue.y()));
    ui->plotter->setXYLineDashed(1, ui->lineDashed->checkState() == Qt::Checked? true : false);
    ui->plotter->setXYLineHasDots(1, ui->lineHasDots->checkState() == Qt::Checked? true : false);
}

void HESEB_ScanTool_ItvsTime::on_PVsReadout_clicked()
{
    if(!isOpened){
        morevar = new moreVar(this);
        morevar->setAttribute(Qt::WA_DeleteOnClose);
        connect(morevar, &QObject::destroyed, this, &HESEB_ScanTool_ItvsTime::on_PVsReadout_closed);
        morevar->show();
        isOpened = true;
    }
}

void HESEB_ScanTool_ItvsTime::on_PVsReadout_closed()
{
    isOpened = false;
}
