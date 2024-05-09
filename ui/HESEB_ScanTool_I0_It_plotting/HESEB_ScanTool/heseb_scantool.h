#ifndef HESEB_SCANTOOL_H
#define HESEB_SCANTOOL_H

#include "morevar.h"

#include <QMainWindow>
#include <QTimer>

#include <fstream>

#include <QFileDialog>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class HESEB_ScanTool; }
QT_END_NAMESPACE

class HESEB_ScanTool : public QMainWindow
{
    Q_OBJECT

public:
    HESEB_ScanTool(QWidget *parent = nullptr);
    ~HESEB_ScanTool();

private slots:

    void logs();

    void path();

    void on_SEDPathDir_clicked();

    void on_hide_show1_stateChanged(int arg1);

    void on_hide_show2_stateChanged(int arg1);

    void on_I0ItransPlotter_coordinateSelected(const QPointF &xyvalue);

    void on_IrefPlotter_coordinateSelected(const QPointF &xyvalue);

    void on_morevar_clicked();

    void on_morevar_closed();

    void on_scanStatusPV_dbValueChanged(bool out);

private:
    Ui::HESEB_ScanTool *ui;

    QString SED_Path;
    QTimer* checkLogs;
    QTimer* checkPath;
    moreVar *morevar;

    bool isOpened = false;
};
#endif // HESEB_SCANTOOL_H
