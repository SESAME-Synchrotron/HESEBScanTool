#ifndef HESEB_SCANTOOL_XFALSH_H
#define HESEB_SCANTOOL_XFALSH_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class heseb_Scantool_xfalsh; }
QT_END_NAMESPACE

class heseb_Scantool_xfalsh : public QMainWindow
{
    Q_OBJECT

public:
    heseb_Scantool_xfalsh(QWidget *parent = nullptr);
    ~heseb_Scantool_xfalsh();

private slots:
    void on_plotter_coordinateSelected(const QPointF &xyvalue);

private:
    Ui::heseb_Scantool_xfalsh *ui;
};
#endif // HESEB_SCANTOOL_XFALSH_H
