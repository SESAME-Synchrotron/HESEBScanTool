#ifndef HESEB_SCANTOOL_I0_H
#define HESEB_SCANTOOL_I0_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class HESEB_ScanTool_I0; }
QT_END_NAMESPACE

class HESEB_ScanTool_I0 : public QMainWindow
{
    Q_OBJECT

public:
    HESEB_ScanTool_I0(QWidget *parent = nullptr);
    ~HESEB_ScanTool_I0();

private:
    Ui::HESEB_ScanTool_I0 *ui;
};
#endif // HESEB_SCANTOOL_I0_H
