/********************************************************************************
** Form generated from reading UI file 'HESEB_ScanTool_ItvsTime.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HESEB_SCANTOOL_ITVSTIME_H
#define UI_HESEB_SCANTOOL_ITVSTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "QEFrame.h"
#include "QEPlotter.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *lblTitle_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *Start;
    QLineEdit *Int_time;
    QSpacerItem *horizontalSpacer;
    QPushButton *Stop;
    QGridLayout *gridLayout_3;
    QLabel *label_13;
    QLabel *label_14;
    QEPlotter *qeplotter_2;
    QLabel *Status;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(1059, 670);
        gridLayout_4 = new QGridLayout(Form);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblTitle_2 = new QLabel(Form);
        lblTitle_2->setObjectName(QStringLiteral("lblTitle_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblTitle_2->sizePolicy().hasHeightForWidth());
        lblTitle_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        lblTitle_2->setFont(font);
        lblTitle_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-radius: 5px;\n"
"margin-top: 0.5em;\n"
"subcontrol-origin: margin;\n"
"left: 10px;\n"
"padding: 0 3px 0 3px;"));
        lblTitle_2->setAlignment(Qt::AlignCenter);
        lblTitle_2->setMargin(11);

        gridLayout->addWidget(lblTitle_2, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::StyledPanel);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        Start = new QPushButton(Form);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setCursor(QCursor(Qt::PointingHandCursor));
        Start->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(Start, 0, 3, 1, 1);

        Int_time = new QLineEdit(Form);
        Int_time->setObjectName(QStringLiteral("Int_time"));
        QFont font1;
        font1.setPointSize(9);
        Int_time->setFont(font1);
        Int_time->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        Int_time->setCursorMoveStyle(Qt::LogicalMoveStyle);
        Int_time->setClearButtonEnabled(false);

        gridLayout_2->addWidget(Int_time, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        Stop = new QPushButton(Form);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setCursor(QCursor(Qt::PointingHandCursor));
        Stop->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(Stop, 0, 4, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_13 = new QLabel(Form);
        label_13->setObjectName(QStringLiteral("label_13"));
        QFont font2;
        font2.setFamily(QStringLiteral("Monospace"));
        font2.setPointSize(14);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        label_13->setFont(font2);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_13, 1, 1, 1, 1);

        label_14 = new QLabel(Form);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font2);
        label_14->setLayoutDirection(Qt::LeftToRight);
        label_14->setStyleSheet(QLatin1String(".label_14{\n"
"transform: rotate(-90deg);\n"
"}"));
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setWordWrap(false);

        gridLayout_3->addWidget(label_14, 0, 0, 1, 1);

        qeplotter_2 = new QEPlotter(Form);
        qeplotter_2->setObjectName(QStringLiteral("qeplotter_2"));
        qeplotter_2->setProperty("pvItemsIsVisible", QVariant(false));
        qeplotter_2->setProperty("statusIsVisible", QVariant(false));
        qeplotter_2->setXMaximum(1);
        qeplotter_2->setYMinimum(0);
        qeplotter_2->setYMaximum(1);

        gridLayout_3->addWidget(qeplotter_2, 0, 1, 1, 1);

        Status = new QLabel(Form);
        Status->setObjectName(QStringLiteral("Status"));

        gridLayout_3->addWidget(Status, 2, 0, 1, 2);


        gridLayout_4->addLayout(gridLayout_3, 2, 0, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        lblTitle_2->setText(QApplication::translate("Form", "<html><head/><body><p>DCA | HESEB | SCAN TOOL | Itrans<span style=\" vertical-align:sub;\">(A)_ </span>Time<span style=\" vertical-align:sub;\">(s)</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "Integration Time", Q_NULLPTR));
        Start->setText(QApplication::translate("Form", "Start ", Q_NULLPTR));
        Int_time->setPlaceholderText(QApplication::translate("Form", "Enter Integration Time ... * The allowable values are: {0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2, 2.25, 2.5, 2.75, 3, 3.25, 3.5, 3.75, 4, 5, 6, 7, 8, 9}", Q_NULLPTR));
        Stop->setText(QApplication::translate("Form", "Stop", Q_NULLPTR));
        label_13->setText(QApplication::translate("Form", "<html><head/><body><p>Time(s) = Index * Int. Time</p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("Form", "Current (A)", Q_NULLPTR));
        qeplotter_2->setProperty("DataVariableX", QVariant(QApplication::translate("Form", "PLOT:INDEX", Q_NULLPTR)));
        qeplotter_2->setProperty("DataVariableA", QVariant(QApplication::translate("Form", "PLOT:I0", Q_NULLPTR)));
        qeplotter_2->setProperty("SizeVariableX", QVariant(QApplication::translate("Form", "PLOT:INDEX.NORD", Q_NULLPTR)));
        qeplotter_2->setProperty("SizeVariableA", QVariant(QApplication::translate("Form", "PLOT:I0.NORD", Q_NULLPTR)));
        Status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HESEB_SCANTOOL_ITVSTIME_H
