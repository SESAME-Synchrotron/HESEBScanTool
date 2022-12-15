#ifndef HESEB_SCANTOOL_ITVSTIME_H
#define HESEB_SCANTOOL_ITVSTIME_H

#include <QDialog>
#include <QMainWindow>
#include <qepicspv.h>
#include <QTimer>
#include "morevar.h"

namespace Ui {
class HESEB_ScanTool_ItvsTime;
}

class HESEB_ScanTool_ItvsTime : public QDialog
{
    Q_OBJECT

private slots:

    void on_Int_time_editingFinished();

    void on_Start_clicked();

    void on_Stop_clicked();

    //void on_pushButton_clicked();

    void on_PVsReadout_clicked();

public:
    explicit HESEB_ScanTool_ItvsTime(QWidget *parent = nullptr);
    ~HESEB_ScanTool_ItvsTime();

private:
    Ui::HESEB_ScanTool_ItvsTime *ui;
    HESEB_ScanTool_ItvsTime* OtherPVs;

    moreVar *morevar;

    QEpicsPV* run;
    QEpicsPV* intTime;
};

#endif // HESEB_SCANTOOL_ITVSTIME_H
