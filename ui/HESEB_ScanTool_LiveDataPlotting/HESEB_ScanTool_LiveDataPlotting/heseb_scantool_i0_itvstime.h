#ifndef HESEB_SCANTOOL_I0_ITVSTIME_H
#define HESEB_SCANTOOL_I0_ITVSTIME_H

#include <QDialog>
#include <QMainWindow>
#include <qepicspv.h>
#include <QTimer>

namespace Ui {
class HESEB_ScanTool_I0_ItvsTime;
}

class HESEB_ScanTool_I0_ItvsTime : public QDialog
{
    Q_OBJECT

private slots:

    void on_Int_time_editingFinished();

    void on_Start_clicked();

    void on_Stop_clicked();

public:
    explicit HESEB_ScanTool_I0_ItvsTime(QWidget *parent = nullptr);
    ~HESEB_ScanTool_I0_ItvsTime();

private:
    Ui::HESEB_ScanTool_I0_ItvsTime *ui;

    QEpicsPV* I0_run;
    QEpicsPV* It_run;
    QEpicsPV* I0_intTime;
    QEpicsPV* It_intTime;
};

#endif // HESEB_SCANTOOL_I0_ITVSTIME_H
