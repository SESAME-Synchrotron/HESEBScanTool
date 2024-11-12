#include "heseb_scantool_i0vstime.h"
#include "ui_heseb_scantool_i0vstime.h"

using namespace std;

HESEB_ScanTool_I0vsTime::HESEB_ScanTool_I0vsTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HESEB_ScanTool_I0vsTime)
{
    ui->setupUi(this);
    QDir::setCurrent(workingDir);
}

HESEB_ScanTool_I0vsTime::~HESEB_ScanTool_I0vsTime()
{
    delete ui;
}

void HESEB_ScanTool_I0vsTime::on_IntTime_textEdited(const QString &arg1)
{
    exists = validIntTimes.contains(arg1.trimmed().toFloat());
    ui->IntTime->setStyleSheet(exists? "" : "border: 2.25px solid red;");
}

void HESEB_ScanTool_I0vsTime::on_Start_clicked()
{
    if(exists)
    {
        Client::writePV(runI0, 1);
        QProcess *Acquire = new QProcess(this);
        QString command = "./I0_startAcquire.py --" + ui->IntTime->text().trimmed();
        Acquire->start("gnome-terminal -- bash -c " + command);
        ui->Status->setText("In Process...");
    }
}

void HESEB_ScanTool_I0vsTime::on_Stop_clicked()
{
    ui->Status->setText("Stopped");
}

void HESEB_ScanTool_I0vsTime::on_plotter_coordinateSelected(const QPointF &xyvalue)
{
    ui->xy->setText(QString("X: %1, Y: %2").arg(xyvalue.x()).arg(xyvalue.y()));
    ui->plotter->setXYLineDashed(1, ui->lineDashed->checkState() == Qt::Checked? true : false);
    ui->plotter->setXYLineHasDots(1, ui->lineHasDots->checkState() == Qt::Checked? true : false);
}

void HESEB_ScanTool_I0vsTime::on_readMorePVs_clicked()
{
    if(!isOpened){
        morevar = new moreVar(this);
        morevar->setAttribute(Qt::WA_DeleteOnClose);
        connect(morevar, &QObject::destroyed, this, &HESEB_ScanTool_I0vsTime::on_readMorePVs_closed);
        morevar->show();
        isOpened = true;
    }
}

void HESEB_ScanTool_I0vsTime::on_readMorePVs_closed()
{
    isOpened = false;
}
