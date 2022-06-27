#ifndef HESEB_SCANTOOL_PICO_H
#define HESEB_SCANTOOL_PICO_H

#include <QMainWindow>
#include <qepicspv.h>
#include <QTimer>
#include <QPushButton>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class HESEB_ScanTool_PICO; }
QT_END_NAMESPACE

class HESEB_ScanTool_PICO : public QMainWindow
{
    Q_OBJECT

public:
    HESEB_ScanTool_PICO(QWidget *parent = nullptr);
    ~HESEB_ScanTool_PICO();

private slots:

    void on_Int_time_editingFinished();

    void on_Start_clicked();

    void on_Stop_clicked();

    void startAcquire();

private:
    Ui::HESEB_ScanTool_PICO *ui;

    int* NPLC;
    float* ActIntTime;
    float pico_ReadOut;

    QEpicsPV* picoReadOut;
    QEpicsPV* plotting;

    QTimer* acquireTimer;

    long double* data;
    bool startAcq;
    int i;

    unsigned int sleepTime;
    int timerCounter;
};
#endif // HESEB_SCANTOOL_PICO_H
