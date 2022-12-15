#include "morevar.h"
#include "ui_morevar.h"

moreVar::moreVar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::moreVar)
{
    ui->setupUi(this);
}

moreVar::~moreVar()
{
    delete ui;
}
