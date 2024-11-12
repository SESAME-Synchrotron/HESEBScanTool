#ifndef HESEB_SCANTOOL_LIVEDATAPLOTTING_H
#define HESEB_SCANTOOL_LIVEDATAPLOTTING_H

#include <QMainWindow>

#include "heseb_scantool_i0vstime.h"
#include "heseb_scantool_itvstime.h"

#include <QDesktopServices>
#include <QUrl>
#include <QKeyEvent>

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

    void on_I0_closed();

    void on_It_clicked();

    void on_It_closed();

    void on_enableVoltageSource_stateChanged(int arg1);

    void on_help_clicked();

    void keyPressEvent(QKeyEvent *event);

    void closeEvent(QCloseEvent *event);

private:
    Ui::HESEB_ScanTool_LiveDataPlotting *ui;

    HESEB_ScanTool_I0vsTime* I0;
    HESEB_ScanTool_ItvsTime* Itrans;

    bool isI0Opened = false;
    bool isItOpened = false;

    QString voltageValidation = "HESEB:VoltageValidation";
    QString scanStop = "HESEB:ScanStop";
};
#endif // HESEB_SCANTOOL_LIVEDATAPLOTTING_H
