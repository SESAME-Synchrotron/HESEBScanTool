#ifndef HESEB_SCANTOOL_I0VSTIME_H
#define HESEB_SCANTOOL_I0VSTIME_H

#include "morevar.h"

#include <QDialog>
#include <QMainWindow>
#include <QDir>

#include "client.h"

namespace Ui {
class HESEB_ScanTool_I0vsTime;
}

class HESEB_ScanTool_I0vsTime : public QDialog
{
    Q_OBJECT

private slots:

    void on_IntTime_textEdited(const QString &arg1);

    void on_Start_clicked();

    void on_Stop_clicked();

    void on_plotter_coordinateSelected(const QPointF &xyvalue);

    void on_readMorePVs_clicked();

    void on_readMorePVs_closed();

public:
    explicit HESEB_ScanTool_I0vsTime(QWidget *parent = nullptr);
    ~HESEB_ScanTool_I0vsTime();

private:
    Ui::HESEB_ScanTool_I0vsTime *ui;

    moreVar *morevar;

    bool exists = false;
    bool isOpened = false;

    QList<float> validIntTimes = {0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2, 2.25, 2.5, 2.75, 3, 3.25, 3.5, 3.75, 4, 5, 6, 7, 8, 9};
    QString runI0 = "HESEB:Run:I0";
    QString workingDir = "/home/control/HESEBScanTool/ui/HESEB_ScanTool_LiveDataPlotting";
};

#endif // HESEB_SCANTOOL_I0VSTIME_H
