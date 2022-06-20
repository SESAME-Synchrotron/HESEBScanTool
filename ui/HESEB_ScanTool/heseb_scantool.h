#ifndef HESEB_SCANTOOL_H
#define HESEB_SCANTOOL_H

#include <QMainWindow>

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
    void on_pushButton_clicked();

private:
    Ui::HESEB_ScanTool *ui;
};
#endif // HESEB_SCANTOOL_H
