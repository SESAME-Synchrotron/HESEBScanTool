#ifndef HESEB_SCANTOOL_I0VSTIME_H
#define HESEB_SCANTOOL_I0VSTIME_H

#include <QDialog>
#include <QMainWindow>
#include <qepicspv.h>
#include <QTimer>

namespace Ui {
class HESEB_ScanTool_I0vsTime;
}

class HESEB_ScanTool_I0vsTime : public QDialog
{
    Q_OBJECT

private slots:

    void on_Int_time_editingFinished();

    void on_Start_clicked();

    void on_Stop_clicked();

public:
    explicit HESEB_ScanTool_I0vsTime(QWidget *parent = nullptr);
    ~HESEB_ScanTool_I0vsTime();

private:
    Ui::HESEB_ScanTool_I0vsTime *ui;

    QEpicsPV* run;
    QEpicsPV* intTime;
};

#endif // HESEB_SCANTOOL_I0VSTIME_H
