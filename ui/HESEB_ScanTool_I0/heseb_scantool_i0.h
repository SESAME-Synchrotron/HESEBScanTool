#ifndef HESEB_SCANTOOL_I0_H
#define HESEB_SCANTOOL_I0_H

#include <QMainWindow>
#include <qepicspv.h>

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
    void on_pushButton_3_clicked();

private:
    Ui::HESEB_ScanTool_I0 *ui;

    QEpicsPV* ScanPath;
};
#endif // HESEB_SCANTOOL_I0_H
