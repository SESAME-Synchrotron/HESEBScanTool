#include "PVs_Readout.h"
#include "ui_PVS_Readout.h"

PVS_Readout::PVS_Readout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
}

Help::~Help()
{
    delete ui;
}
