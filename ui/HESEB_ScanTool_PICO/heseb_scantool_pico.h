#ifndef HESEB_SCANTOOL_PICO_H
#define HESEB_SCANTOOL_PICO_H

#include <QMainWindow>
#include <qepicspv.h>

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

private:
    Ui::HESEB_ScanTool_PICO *ui;

    int* NPLC;
    float* ActIntTime;

    int* stopCheck;

    QEpicsPV* picoReadOut;
    QEpicsPV* plotting;
};
#endif // HESEB_SCANTOOL_PICO_H
