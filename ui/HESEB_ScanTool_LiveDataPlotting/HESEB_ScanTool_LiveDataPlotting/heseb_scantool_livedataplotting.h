#ifndef HESEB_SCANTOOL_LIVEDATAPLOTTING_H
#define HESEB_SCANTOOL_LIVEDATAPLOTTING_H

#include <QMainWindow>

#include <heseb_scantool_i0_itvstime.h>
#include <heseb_scantool_i0vstime.h>
#include <heseb_scantool_itvstime.h>
#include <help.h>
#include <qepicspv.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class HESEB_ScanTool_LiveDataPlotting; }
QT_END_NAMESPACE

class HESEB_ScanTool_LiveDataPlotting : public QMainWindow
{
    Q_OBJECT

public:
    HESEB_ScanTool_LiveDataPlotting(QWidget *parent = nullptr);
    ~HESEB_ScanTool_LiveDataPlotting();

private slots:
    void on_I0_clicked();

    void on_It_clicked();

    void on_I0_It_clicked();

    void on_help_clicked();

    void check();

private:
    Ui::HESEB_ScanTool_LiveDataPlotting *ui;

    HESEB_ScanTool_I0vsTime* I0;
    HESEB_ScanTool_ItvsTime* Itrans;
    HESEB_ScanTool_I0_ItvsTime* I0_Itrans;
    Help* help;

    QEpicsPV* I0_run;
    QEpicsPV* It_run;

    QTimer* timer;
};
#endif // HESEB_SCANTOOL_LIVEDATAPLOTTING_H
