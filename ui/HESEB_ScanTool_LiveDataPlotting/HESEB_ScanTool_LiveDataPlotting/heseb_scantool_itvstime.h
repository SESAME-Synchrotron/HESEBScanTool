#ifndef HESEB_SCANTOOL_ITVSTIME_H
#define HESEB_SCANTOOL_ITVSTIME_H

#include "morevar.h"

#include <QDialog>
#include <QMainWindow>

#include <qepicspv.h>
#include "client.h"
#include <unistd.h>

#include <QTimer>
#include <QMessageBox>
#include <QDir>
#include <QProcess>

namespace Ui {
class HESEB_ScanTool_ItvsTime;
}

class HESEB_ScanTool_ItvsTime : public QDialog
{
    Q_OBJECT

private slots:

    void on_IntTime_editingFinished();

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
    HESEB_ScanTool_ItvsTime* OtherPVs;

    moreVar *morevar;

    QEpicsPV* run;
    QEpicsPV* intTime;

    bool isOpened = false;
};

#endif // HESEB_SCANTOOL_ITVSTIME_H
