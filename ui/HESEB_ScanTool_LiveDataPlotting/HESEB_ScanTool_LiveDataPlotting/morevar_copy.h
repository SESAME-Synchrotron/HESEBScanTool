#ifndef MOREVAR_H
#define MOREVAR_H

#include <QDialog>

namespace Ui {
class moreVar;
}

class moreVar : public QDialog
{
    Q_OBJECT

public:
    explicit moreVar(QWidget *parent = nullptr);
    ~moreVar();

private slots:



private:
    Ui::moreVar *ui;
};

#endif // MOREVAR_H
