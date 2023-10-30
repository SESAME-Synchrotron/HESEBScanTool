#ifndef HESEB_SCANTOOL_I0VSTIME_H
#define HESEB_SCANTOOL_I0VSTIME_H

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
class HESEB_ScanTool_I0vsTime;
}

class HESEB_ScanTool_I0vsTime : public QDialog
{
    Q_OBJECT

private slots:

    void on_IntTime_editingFinished();

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

    QEpicsPV* run;
    QEpicsPV* intTime;
    moreVar *morevar;

    bool isOpened = false;
};

#endif // HESEB_SCANTOOL_I0VSTIME_H
