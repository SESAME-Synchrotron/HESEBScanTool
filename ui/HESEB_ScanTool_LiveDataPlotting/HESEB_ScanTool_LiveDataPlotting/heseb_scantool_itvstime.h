#ifndef HESEB_SCANTOOL_ITVSTIME_H
#define HESEB_SCANTOOL_ITVSTIME_H

#include "morevar.h"

#include <QDialog>
#include <QMainWindow>
#include <QDir>

#include "client.h"

namespace Ui {
class HESEB_ScanTool_ItvsTime;
}

class HESEB_ScanTool_ItvsTime : public QDialog
{
    Q_OBJECT

private slots:

    void on_IntTime_textEdited(const QString &arg1);

    void on_Start_clicked();

    void on_Stop_clicked();

    void on_plotter_coordinateSelected(const QPointF &xyvalue);

    void on_PVsReadout_clicked();

    void on_PVsReadout_closed();

public:
    explicit HESEB_ScanTool_ItvsTime(QWidget *parent = nullptr);
    ~HESEB_ScanTool_ItvsTime();

private:
    Ui::HESEB_ScanTool_ItvsTime *ui;

    moreVar *morevar;

    bool exists = false;
    bool isOpened = false;

    QList<float> validIntTimes = {0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2, 2.25, 2.5, 2.75, 3, 3.25, 3.5, 3.75, 4, 5, 6, 7, 8, 9};
    QString runIt = "HESEB:Run:It";
    QString workingDir = "/home/control/HESEBScanTool/ui/HESEB_ScanTool_LiveDataPlotting";
};

#endif // HESEB_SCANTOOL_ITVSTIME_H
