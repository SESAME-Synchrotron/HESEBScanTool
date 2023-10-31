#include "heseb_scantool_i0_itvstime.h"
#include "ui_heseb_scantool_i0_itvstime.h"

using namespace std;

HESEB_ScanTool_I0_ItvsTime::HESEB_ScanTool_I0_ItvsTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HESEB_ScanTool_I0_ItvsTime)
{
    ui->setupUi(this);

    this->I0_run = new QEpicsPV("I0:RUN");
    this->It_run = new QEpicsPV("It:RUN");

    this->I0_intTime     = new QEpicsPV("I0:INT:TIME");
    this->It_intTime     = new QEpicsPV("It:INT:TIME");

    Client::writePV("I0:INT:TIME",0);
    Client::writePV("It:INT:TIME",0);

    string intTime = ui->IntTime->text().toStdString();
}

HESEB_ScanTool_I0_ItvsTime::~HESEB_ScanTool_I0_ItvsTime()
{
    delete ui;
}

void HESEB_ScanTool_I0_ItvsTime::on_IntTime_editingFinished()
{
    string intTime = ui->IntTime->text().toStdString();

    if (intTime == "0.25" || intTime == ".25"){         // 4 Samples

        Client::writePV("I0:INT:TIME",0.25);
        Client::writePV("It:INT:TIME",0.25);
    }
    else if (intTime == "0.5" || intTime == ".5"){      // 7 Samples

        Client::writePV("I0:INT:TIME",0.5);
        Client::writePV("It:INT:TIME",0.5);
    }
    else if (intTime == "0.75" || intTime == ".75"){    // 11 Samples

        Client::writePV("I0:INT:TIME",0.75);
        Client::writePV("It:INT:TIME",0.75);
    }
    else if (intTime == "1"){                           // 15 Samples

        Client::writePV("I0:INT:TIME",1);
        Client::writePV("It:INT:TIME",1);
    }
    else if (intTime == "1.25"){                        // 18 Samples

        Client::writePV("I0:INT:TIME",1.25);
        Client::writePV("It:INT:TIME",1.25);
    }
    else if (intTime == "1.5"){                         // 12 Samples

        Client::writePV("I0:INT:TIME",1.5);
        Client::writePV("It:INT:TIME",1.5);
    }
    else if (intTime == "1.75"){                        // 14 Samples

        Client::writePV("I0:INT:TIME",1.75);
        Client::writePV("It:INT:TIME",1.75);
    }
    else if (intTime == "2"){                           // 16 Samples

        Client::writePV("I0:INT:TIME",2);
        Client::writePV("It:INT:TIME",2);
    }
    else if (intTime == "2.25"){                        // 17 Samples

        Client::writePV("I0:INT:TIME",2.25);
        Client::writePV("It:INT:TIME",2.25);
    }
    else if (intTime == "2.5"){                         // 19 Samples

        Client::writePV("I0:INT:TIME",2.5);
        Client::writePV("It:INT:TIME",2.5);
    }
    else if (intTime == "2.75"){                        // 21 Samples

        Client::writePV("I0:INT:TIME",2.75);
        Client::writePV("It:INT:TIME",2.75);
    }
    else if (intTime == "3"){                           // 23 Samples

        Client::writePV("I0:INT:TIME",3);
        Client::writePV("It:INT:TIME",3);
    }
    else if (intTime == "3.25"){                        // 25 Samples

        Client::writePV("I0:INT:TIME",3.25);
        Client::writePV("It:INT:TIME",3.25);
    }
    else if (intTime == "3.5"){                         // 27 Samples

        Client::writePV("I0:INT:TIME",3.5);
        Client::writePV("It:INT:TIME",3.5);
    }
    else if (intTime == "3.75"){                        // 29 Samples

        Client::writePV("I0:INT:TIME",3.75);
        Client::writePV("It:INT:TIME",3.75);
    }
    else if (intTime == "4"){                           // 31 Samples

        Client::writePV("I0:INT:TIME",4);
        Client::writePV("It:INT:TIME",4);
    }
    else if (intTime == "5"){                           // 39 Samples

        Client::writePV("I0:INT:TIME",5);
        Client::writePV("It:INT:TIME",5);
    }
    else if (intTime == "6"){                           // 47 Samples

        Client::writePV("I0:INT:TIME",6);
        Client::writePV("It:INT:TIME",6);
    }
    else if (intTime == "7"){                           // 54 Samples

        Client::writePV("I0:INT:TIME",7);
        Client::writePV("It:INT:TIME",7);
    }
    else if (intTime == "8"){                           // 62 Samples

        Client::writePV("I0:INT:TIME",8);
        Client::writePV("It:INT:TIME",8);
    }
    else if (intTime == "9"){                           // 70 Samples

        Client::writePV("I0:INT:TIME",9);
        Client::writePV("It:INT:TIME",9);
    }
    else {

        QMessageBox::information(this,"Invalid Value","Please select one of these options: {0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2, 2.25, 2.5, 2.75, 3, 3.25, 3.5, 3.75, 4, 5, 6, 7, 8, 9}");
    }
}

void HESEB_ScanTool_I0_ItvsTime::on_Start_clicked()
{
    if (ui->IntTime->text().toStdString() == "")
    {
        QMessageBox::information(this,"Warning!","No integration time, please insert a value ....");
    }
    else {

        Client::writePV("I0:RUN",0);
        Client::writePV("PLOT:I0", 0);
        Client::writePV("I0:PLOT:INDEX", 0);

        Client::writePV("It:RUN",0);
        Client::writePV("PLOT:It", 0);
        Client::writePV("It:PLOT:INDEX", 0);

        QProcess *Acquire = new QProcess(0);
        QDir::setCurrent("/home/control/HESEBScanTool/ui/HESEB_ScanTool_LiveDataPlotting");
        Acquire->start("gnome-terminal -x ./I0_It_startAcquire.sh");

        ui->Status->setText("In Process...");
    }
}

void HESEB_ScanTool_I0_ItvsTime::on_Stop_clicked()
{
    Client::writePV("I0:RUN",1);
    Client::writePV("It:RUN",1);

    ui->Status->setText("Stopped");
    Client::writePV("I0:INT:TIME",0);
    Client::writePV("It:INT:TIME",0);

    usleep(1000000);

    QProcess *Acquire = new QProcess(0);
    QDir::setCurrent("/home/control/HESEBScanTool/ui/HESEB_ScanTool_LiveDataPlotting");
    Acquire->start("gnome-terminal -x ./I0_It_stopAcquire.sh");
}

void HESEB_ScanTool_I0_ItvsTime::on_plotter_coordinateSelected(const QPointF &xyvalue)
{
    ui->xy->setText(QString("X: %1, Y: %2").arg(xyvalue.x()).arg(xyvalue.y()));

    if(ui->lineDashed->checkState() == Qt::Checked)
    {
        ui->plotter->setXYLineDashed(1, true);
        ui->plotter->setXYLineDashed(2, true);
    }
    else
    {
        ui->plotter->setXYLineDashed(1, false);
        ui->plotter->setXYLineDashed(2, false);
    }

    if(ui->lineHasDots->checkState() == Qt::Checked)
    {
        ui->plotter->setXYLineHasDots(1, true);
        ui->plotter->setXYLineHasDots(2, true);
    }
    else
    {
        ui->plotter->setXYLineHasDots(1, false);
        ui->plotter->setXYLineHasDots(2, false);
    }
}

void HESEB_ScanTool_I0_ItvsTime::on_readMorePVsclicked()
{
    if(!isOpened){
        morevar = new moreVar(this);
        morevar->setAttribute(Qt::WA_DeleteOnClose);
        connect(morevar, &QObject::destroyed, this, &HESEB_ScanTool_I0_ItvsTime::on_readMorePVs_closed);
        morevar->show();
        isOpened = true;
    }
}

void HESEB_ScanTool_I0_ItvsTime::on_readMorePVs_closed()
{
    isOpened = false;
}


