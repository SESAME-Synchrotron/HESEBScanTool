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

    void startAcquire();

    void checkAcquire();

public:
    HESEB_ScanTool_I0vsTime(QWidget *parent = nullptr);
    ~HESEB_ScanTool_I0vsTime();

private:
    Ui::HESEB_ScanTool_I0vsTime *ui;

    int* NPLC;
    float* ActIntTime;
    float pico_ReadOut;

    QEpicsPV* picoReadOut;
    QEpicsPV* plotting;
    QEpicsPV* calibEnergy;
    QEpicsPV* intTime;

    QTimer* acquireTimer;
    QTimer* chkkAcquire;

    double* data;
    bool startAcq;
    bool checkAcq;
    bool go;
    int i;

    unsigned int sleepTime;
    int timerCounter;
    int samples;

    double* dataIndex;
};
#endif // HESEB_SCANTOOL_I0VSTIME_H
