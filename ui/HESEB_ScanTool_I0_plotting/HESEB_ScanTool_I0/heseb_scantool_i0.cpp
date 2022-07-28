#include "heseb_scantool_i0.h"
#include "ui_heseb_scantool_i0.h"

#include <iostream>
#include <fstream>
#include <string>

#include <QFileDialog>
#include <QDesktopServices>
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

HESEB_ScanTool_I0::HESEB_ScanTool_I0(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HESEB_ScanTool_I0)
{
    ui->setupUi(this);

//    this->ScanPath = new QEpicsPV("SCAN:PATH");


    checkLogs = new QTimer(this);
    this->checkLogs->start(100);

    connect(checkLogs,SIGNAL(timeout()),this,SLOT(logs()));

    checkPath = new QTimer(this);
    this->checkPath->start(500);

    connect(checkPath,SIGNAL(timeout()),this,SLOT(path()));

}

HESEB_ScanTool_I0::~HESEB_ScanTool_I0()
{
    delete ui;
}

void HESEB_ScanTool_I0::on_pushButton_3_clicked()
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
//           cout << log.toStdString() << '\n';
       }
//       else
//          cout << "Unable to open file.\n";
}

void HESEB_ScanTool_I0::path()
{
    ifstream file("/home/control/HESEBScanTool/tmp/SEDPath.txt");

       if (file)
       {
           string line = getLastLine(file);
           this->SED_Path = QString::fromUtf8(line.c_str());
           ui->path->setText(SED_Path);
//           cout << SED_Path.toStdString() << '\n';
       }
//       else
//          cout << "Unable to open file.\n";
}
