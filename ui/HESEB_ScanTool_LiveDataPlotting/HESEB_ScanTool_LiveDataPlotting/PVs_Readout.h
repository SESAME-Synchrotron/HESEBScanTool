#ifndef PVS_READOUT_H
#define PVS_READOUT_H

#include <QDialog>

namespace Ui {
class PVS_Readout;
}

class PVS_Readout : public QDialog
{
    Q_OBJECT

public:
    explicit PVS_Readout(QWidget *parent = nullptr);
    ~PVS_Readout();

private:
    Ui::PVS_Readout *ui;
};


#endif // PVS_READOUT_H
