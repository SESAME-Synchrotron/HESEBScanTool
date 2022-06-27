#include "heseb_scantool.h"
#include "ui_heseb_scantool.h"

#include <iostream>
#include <fstream>
#include <string>

#include <QFileDialog>
#include <qepicspv.h>
#include <qstring.h>

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

//    this->ScanPath = new QEpicsPV("SCAN:PATH");

    checkLogs = new QTimer(this);
    this->checkLogs->start(500);

    connect(checkLogs,SIGNAL(timeout()),this,SLOT(logs()));

    checkPath = new QTimer(this);
    this->checkPath->start(500);

    connect(checkPath,SIGNAL(timeout()),this,SLOT(path()));
}

HESEB_ScanTool::~HESEB_ScanTool()
{
    delete ui;
}


void HESEB_ScanTool::on_pushButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Open",SED_Path);
}

void HESEB_ScanTool::logs()
{
    ifstream file("/home/control/SED_Scantool.log");

       if (file)
       {
           string line = getLastLine(file);
           QString log = QString::fromUtf8(line.c_str());
           ui->logs->setText(log);
           cout << log.toStdString() << '\n';
       }
       else
          cout << "Unable to open file.\n";
}

void HESEB_ScanTool::path()
{
    ifstream file("/home/control/SED_Scantool.log");

       if (file)
       {
           string line = getLastLine(file);
           this->SED_Path = QString::fromUtf8(line.c_str());
           ui->path->setText(SED_Path);
           cout << SED_Path.toStdString() << '\n';
       }
       else
          cout << "Unable to open file.\n";
}
