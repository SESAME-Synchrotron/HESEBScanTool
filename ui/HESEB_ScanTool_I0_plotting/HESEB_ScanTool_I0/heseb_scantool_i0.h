#ifndef HESEB_SCANTOOL_I0_H
#define HESEB_SCANTOOL_I0_H

#include "morevar.h"

#include <QMainWindow>
#include <QTimer>

#include <fstream>

#include <QFileDialog>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class HESEB_ScanTool_I0; }
QT_END_NAMESPACE

class HESEB_ScanTool_I0 : public QMainWindow
{
    Q_OBJECT

public:
    HESEB_ScanTool_I0(QWidget *parent = nullptr);
    ~HESEB_ScanTool_I0();

private slots:

    void logs();

    void path();

    void on_SEDPathDir_clicked();

    void on_plotter_coordinateSelected(const QPointF &xyvalue);

    void on_readMorePVs_clicked();

    void on_readMorePVs_closed();

    void on_scanStatusPV_dbValueChanged(bool out);

private:
    Ui::HESEB_ScanTool_I0 *ui;

    QString SED_Path;
    QTimer* checkLogs;
    QTimer* checkPath;
    moreVar *morevar;

    bool isOpened = false;
};
#endif // HESEB_SCANTOOL_I0_H
