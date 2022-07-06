#ifndef HESEB_SCANTOOL_I0VSTIME_H
#define HESEB_SCANTOOL_I0VSTIME_H

#include <QMainWindow>
#include <qepicspv.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class HESEB_ScanTool_I0vsTime; }
QT_END_NAMESPACE

class HESEB_ScanTool_I0vsTime : public QMainWindow
{
    Q_OBJECT

private slots:

    void on_Int_time_editingFinished();

    void on_Start_clicked();

    void on_Stop_clicked();

    void checkAcquire();

public:
    HESEB_ScanTool_I0vsTime(QWidget *parent = nullptr);
    ~HESEB_ScanTool_I0vsTime();

private:
    Ui::HESEB_ScanTool_I0vsTime *ui;

    QEpicsPV* calibEnergy;
    QEpicsPV* intTime;
    QEpicsPV* actIntTime;
    QEpicsPV* maxTime;

    QTimer* acquireTimer;
    QTimer* chkkAcquire;

    unsigned int sleepTime;
};
#endif // HESEB_SCANTOOL_I0VSTIME_H
