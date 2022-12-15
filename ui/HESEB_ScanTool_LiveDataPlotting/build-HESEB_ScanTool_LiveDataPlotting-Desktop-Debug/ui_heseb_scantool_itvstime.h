/********************************************************************************
** Form generated from reading UI file 'heseb_scantool_itvstime.ui'
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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "QEFrame.h"
#include "QEPlotter.h"

QT_BEGIN_NAMESPACE

class Ui_HESEB_ScanTool_ItvsTime
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_7;
    QLabel *lblTitle_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Int_time;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *PVsReadout;
    QPushButton *Start;
    QPushButton *Stop;
    QGridLayout *gridLayout_8;
    QLabel *label_17;
    QLabel *label_18;
    QEPlotter *qeplotter_4;
    QLabel *Status;

    void setupUi(QDialog *HESEB_ScanTool_ItvsTime)
    {
        if (HESEB_ScanTool_ItvsTime->objectName().isEmpty())
            HESEB_ScanTool_ItvsTime->setObjectName(QStringLiteral("HESEB_ScanTool_ItvsTime"));
        HESEB_ScanTool_ItvsTime->resize(1122, 665);
        verticalLayout = new QVBoxLayout(HESEB_ScanTool_ItvsTime);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        lblTitle_4 = new QLabel(HESEB_ScanTool_ItvsTime);
        lblTitle_4->setObjectName(QStringLiteral("lblTitle_4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblTitle_4->sizePolicy().hasHeightForWidth());
        lblTitle_4->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        lblTitle_4->setFont(font);
        lblTitle_4->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-radius: 5px;\n"
"margin-top: 0.5em;\n"
"subcontrol-origin: margin;\n"
"left: 10px;\n"
"padding: 0 3px 0 3px;"));
        lblTitle_4->setAlignment(Qt::AlignCenter);
        lblTitle_4->setMargin(11);

        gridLayout_7->addWidget(lblTitle_4, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(HESEB_ScanTool_ItvsTime);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::StyledPanel);

        horizontalLayout->addWidget(label);

        Int_time = new QLineEdit(HESEB_ScanTool_ItvsTime);
        Int_time->setObjectName(QStringLiteral("Int_time"));
        QFont font1;
        font1.setPointSize(9);
        Int_time->setFont(font1);
        Int_time->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        Int_time->setCursorMoveStyle(Qt::LogicalMoveStyle);
        Int_time->setClearButtonEnabled(false);

        horizontalLayout->addWidget(Int_time);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        PVsReadout = new QPushButton(HESEB_ScanTool_ItvsTime);
        PVsReadout->setObjectName(QStringLiteral("PVsReadout"));

        horizontalLayout->addWidget(PVsReadout);

        Start = new QPushButton(HESEB_ScanTool_ItvsTime);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setCursor(QCursor(Qt::PointingHandCursor));
        Start->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(Start);

        Stop = new QPushButton(HESEB_ScanTool_ItvsTime);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setCursor(QCursor(Qt::PointingHandCursor));
        Stop->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(Stop);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_17 = new QLabel(HESEB_ScanTool_ItvsTime);
        label_17->setObjectName(QStringLiteral("label_17"));
        QFont font2;
        font2.setFamily(QStringLiteral("Monospace"));
        font2.setPointSize(14);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        label_17->setFont(font2);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_17, 1, 1, 1, 1);

        label_18 = new QLabel(HESEB_ScanTool_ItvsTime);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font2);
        label_18->setLayoutDirection(Qt::LeftToRight);
        label_18->setStyleSheet(QLatin1String(".label_14{\n"
"transform: rotate(-90deg);\n"
"}"));
        label_18->setAlignment(Qt::AlignCenter);
        label_18->setWordWrap(false);

        gridLayout_8->addWidget(label_18, 0, 0, 1, 1);

        qeplotter_4 = new QEPlotter(HESEB_ScanTool_ItvsTime);
        qeplotter_4->setObjectName(QStringLiteral("qeplotter_4"));
        qeplotter_4->setProperty("pvItemsIsVisible", QVariant(false));
        qeplotter_4->setProperty("statusIsVisible", QVariant(false));
        qeplotter_4->setXMaximum(1);
        qeplotter_4->setYMinimum(0);
        qeplotter_4->setYMaximum(1);

        gridLayout_8->addWidget(qeplotter_4, 0, 1, 1, 1);

        Status = new QLabel(HESEB_ScanTool_ItvsTime);
        Status->setObjectName(QStringLiteral("Status"));
        Status->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 0);"));

        gridLayout_8->addWidget(Status, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_8);


        retranslateUi(HESEB_ScanTool_ItvsTime);

        QMetaObject::connectSlotsByName(HESEB_ScanTool_ItvsTime);
    } // setupUi

    void retranslateUi(QDialog *HESEB_ScanTool_ItvsTime)
    {
        HESEB_ScanTool_ItvsTime->setWindowTitle(QApplication::translate("HESEB_ScanTool_ItvsTime", "Dialog", Q_NULLPTR));
        lblTitle_4->setText(QApplication::translate("HESEB_ScanTool_ItvsTime", "<html><head/><body><p>DCA | HESEB | SCAN TOOL | Itrans<span style=\" vertical-align:sub;\">(A)_ </span>Time<span style=\" vertical-align:sub;\">(s)</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("HESEB_ScanTool_ItvsTime", "Integration Time", Q_NULLPTR));
        Int_time->setPlaceholderText(QApplication::translate("HESEB_ScanTool_ItvsTime", "Enter Integration Time ... * The allowable values are: {0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2, 2.25, 2.5, 2.75, 3, 3.25, 3.5, 3.75, 4, 5, 6, 7, 8, 9}", Q_NULLPTR));
        PVsReadout->setText(QApplication::translate("HESEB_ScanTool_ItvsTime", "BL Parameters", Q_NULLPTR));
        Start->setText(QApplication::translate("HESEB_ScanTool_ItvsTime", "Start ", Q_NULLPTR));
        Stop->setText(QApplication::translate("HESEB_ScanTool_ItvsTime", "Stop", Q_NULLPTR));
        label_17->setText(QApplication::translate("HESEB_ScanTool_ItvsTime", "<html><head/><body><p>Time(s) = Index * Int. Time</p></body></html>", Q_NULLPTR));
        label_18->setText(QApplication::translate("HESEB_ScanTool_ItvsTime", "Current (A)", Q_NULLPTR));
        qeplotter_4->setProperty("DataVariableX", QVariant(QApplication::translate("HESEB_ScanTool_ItvsTime", "It:PLOT:INDEX", Q_NULLPTR)));
        qeplotter_4->setProperty("DataVariableA", QVariant(QApplication::translate("HESEB_ScanTool_ItvsTime", "PLOT:It", Q_NULLPTR)));
        qeplotter_4->setProperty("SizeVariableX", QVariant(QApplication::translate("HESEB_ScanTool_ItvsTime", "It:PLOT:INDEX.NORD", Q_NULLPTR)));
        qeplotter_4->setProperty("SizeVariableA", QVariant(QApplication::translate("HESEB_ScanTool_ItvsTime", "PLOT:It.NORD", Q_NULLPTR)));
        Status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HESEB_ScanTool_ItvsTime: public Ui_HESEB_ScanTool_ItvsTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HESEB_SCANTOOL_ITVSTIME_H
