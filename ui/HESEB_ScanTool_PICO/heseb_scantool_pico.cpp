#include "heseb_scantool_pico.h"
#include "ui_heseb_scantool_pico.h"

#include <stdlib.h>
#include <iostream>

#include <qstring.h>
#include <string>

#include <QMessageBox>

#include <qepicspv.h>
#include <client.h>

#include <unistd.h>
#include <vector>

using namespace std;

HESEB_ScanTool_PICO::HESEB_ScanTool_PICO(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HESEB_ScanTool_PICO)
{
    ui->setupUi(this);

    this->NPLC           = new int;
    this->ActIntTime     = new float;
    this->stopCheck      = new int;

    *NPLC = 0;
    *ActIntTime = 0;
    *stopCheck = 0;

    this->picoReadOut = new QEpicsPV("K6487:1:Acquire");
    this->plotting    = new QEpicsPV("PLOT:I0");
}

HESEB_ScanTool_PICO::~HESEB_ScanTool_PICO()
{
    delete ui;
}


void HESEB_ScanTool_PICO::on_Int_time_editingFinished()
{
    string intTime = ui->Int_time->text().toStdString();

    if (intTime == "0.25" || intTime == ".25"){         // 4 Samples

        *NPLC = 1;
        *ActIntTime = 0.27;

    }
    else if (intTime == "0.5" || intTime == ".5"){      // 7 Samples

        *NPLC = 1;
        *ActIntTime = 0.45;

    }
    else if (intTime == "0.75" || intTime == ".75"){    // 11 Samples

        *NPLC = 1;
        *ActIntTime = 0.74;

    }
    else if (intTime == "1"){                           // 15 Samples

        *NPLC = 1;
        *ActIntTime = 0.94;

    }
    else if (intTime == "1.25"){                        // 18 Samples

        *NPLC = 1;
        *ActIntTime = 1.12;
    }
    else if (intTime == "1.5"){                         // 12 Samples

        *NPLC = 2;
        *ActIntTime = 1.49;
    }
    else if (intTime == "1.75"){                        // 14 Samples

        *NPLC = 2;
        *ActIntTime = 1.74;
    }
    else if (intTime == "2"){                           // 16 Samples

        *NPLC = 2;
        *ActIntTime = 1.99;
    }
    else if (intTime == "2.25"){                        // 17 Samples

        *NPLC = 2;
        *ActIntTime = 2.12;
    }
    else if (intTime == "2.5"){                         // 19 Samples

        *NPLC = 2;
        *ActIntTime = 2.37;
    }
    else if (intTime == "2.75"){                        // 21 Samples

        *NPLC = 2;
        *ActIntTime = 2.61;
    }
    else if (intTime == "3"){                           // 23 Samples

        *NPLC = 2;
        *ActIntTime = 2.85;
    }
    else if (intTime == "3.25"){                        // 25 Samples

        *NPLC = 2;
        *ActIntTime = 3.11;
    }
    else if (intTime == "3.5"){                         // 27 Samples

        *NPLC = 2;
        *ActIntTime = 3.35;
    }
    else if (intTime == "3.75"){                        // 29 Samples

        *NPLC = 2;
        *ActIntTime = 3.6;
    }
    else if (intTime == "4"){                           // 31 Samples

        *NPLC = 2;
        *ActIntTime = 3.84;
    }
    else if (intTime == "5"){                           // 39 Samples

        *NPLC = 2;
        *ActIntTime = 4.83;
    }
    else if (intTime == "6"){                           // 47 Samples

        *NPLC = 2;
        *ActIntTime = 5.81;
    }
    else if (intTime == "7"){                           // 54 Samples

        *NPLC = 2;
        *ActIntTime = 6.68;
    }
    else if (intTime == "8"){                           // 62 Samples

        *NPLC = 2;
        *ActIntTime = 7.66;
    }
    else if (intTime == "9"){                           // 70 Samples

        *NPLC = 2;
        *ActIntTime = 8.65;
    }
    else {

        QMessageBox::warning(this,"Invalid Value","Please select one of these options: {0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2, 2.25, 2.5, 2.75, 3, 3.25, 3.5, 3.75, 4, 5, 6, 7, 8, 9}");
    }

    cout<<"NPLC: "<<*NPLC<<endl;
    cout<<"ActIntTime: "<<*ActIntTime<<endl;

}

void HESEB_ScanTool_PICO::on_Start_clicked()
{
    float sleepTime = 0.001;
    int timerCounter = 0;
    stopCheck = 0;
    std::vector<float> data;
    int a[] = {};
    Client::writePV("K6487:1:RST.PROC",1);
    Client::writePV("K6487:1:Damping",0);
    Client::writePV("K6487:1:TimePerSampleStep",0);

    Client::writePV("K6487:1:TimePerSampleStep",*ActIntTime);
    Client::writePV("K6487:1:IntegrationTime",*NPLC);

    sleep(sleepTime);

    Client::writePV("K6487:1:Acquire.PROC",1);

    float pico_ReadOut = this->picoReadOut->get().toFloat();

    while (true && *stopCheck != 1){

        if (pico_ReadOut == this->picoReadOut->get().toFloat()){

            data.push_back(this->picoReadOut->get().toFloat());
            timerCounter =+1;
        }
        else {
            break;
        }

        sleep(sleepTime);
        if (((static_cast<float>(timerCounter))* sleepTime) >= (*ActIntTime * 5)){

            QMessageBox::warning(this,"-","Collection time has reached the maximum allowed time");
            break;
        }
    }
    Client::writeArray("PLOT:I0", data, 100000);
}

void HESEB_ScanTool_PICO::on_Stop_clicked()
{
    *stopCheck = 1;
}
