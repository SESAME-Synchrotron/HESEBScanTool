/********************************************************************************
** Form generated from reading UI file 'heseb_scantool_i0_itvstime.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HESEB_SCANTOOL_I0_ITVSTIME_H
#define UI_HESEB_SCANTOOL_I0_ITVSTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include "QEFrame.h"
#include "QEPlotter.h"
#include "QSimpleShape.h"

QT_BEGIN_NAMESPACE

class Ui_HESEB_ScanTool_I0_ItvsTime
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_7;
    QLabel *lblTitle_4;
    QGridLayout *gridLayout_9;
    QPushButton *Stop;
    QLineEdit *Int_time;
    QLabel *label;
    QPushButton *Start;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QGridLayout *gridLayout_2;
    QSimpleShape *qsimpleshape_2;
    QSimpleShape *qsimpleshape_8;
    QLabel *label_16;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_8;
    QLabel *label_18;
    QLabel *label_17;
    QLabel *Status;
    QEPlotter *qeplotter_4;

    void setupUi(QDialog *HESEB_ScanTool_I0_ItvsTime)
    {
        if (HESEB_ScanTool_I0_ItvsTime->objectName().isEmpty())
            HESEB_ScanTool_I0_ItvsTime->setObjectName(QStringLiteral("HESEB_ScanTool_I0_ItvsTime"));
        HESEB_ScanTool_I0_ItvsTime->resize(1080, 647);
        gridLayout = new QGridLayout(HESEB_ScanTool_I0_ItvsTime);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        lblTitle_4 = new QLabel(HESEB_ScanTool_I0_ItvsTime);
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


        gridLayout->addLayout(gridLayout_7, 0, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        Stop = new QPushButton(HESEB_ScanTool_I0_ItvsTime);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setCursor(QCursor(Qt::PointingHandCursor));
        Stop->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));

        gridLayout_9->addWidget(Stop, 0, 5, 1, 1);

        Int_time = new QLineEdit(HESEB_ScanTool_I0_ItvsTime);
        Int_time->setObjectName(QStringLiteral("Int_time"));
        QFont font1;
        font1.setPointSize(9);
        Int_time->setFont(font1);
        Int_time->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        Int_time->setCursorMoveStyle(Qt::LogicalMoveStyle);
        Int_time->setClearButtonEnabled(false);

        gridLayout_9->addWidget(Int_time, 0, 1, 1, 1);

        label = new QLabel(HESEB_ScanTool_I0_ItvsTime);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::StyledPanel);

        gridLayout_9->addWidget(label, 0, 0, 1, 1);

        Start = new QPushButton(HESEB_ScanTool_I0_ItvsTime);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setCursor(QCursor(Qt::PointingHandCursor));
        Start->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));

        gridLayout_9->addWidget(Start, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        pushButton = new QPushButton(HESEB_ScanTool_I0_ItvsTime);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_9->addWidget(pushButton, 0, 6, 1, 1);


        gridLayout->addLayout(gridLayout_9, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        qsimpleshape_2 = new QSimpleShape(HESEB_ScanTool_I0_ItvsTime);
        qsimpleshape_2->setObjectName(QStringLiteral("qsimpleshape_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qsimpleshape_2->sizePolicy().hasHeightForWidth());
        qsimpleshape_2->setSizePolicy(sizePolicy1);
        qsimpleshape_2->setShape(QSimpleShape::roundRectangle);
        qsimpleshape_2->setProperty("colour0", QVariant(QColor(23, 69, 243)));

        gridLayout_2->addWidget(qsimpleshape_2, 1, 1, 1, 1);

        qsimpleshape_8 = new QSimpleShape(HESEB_ScanTool_I0_ItvsTime);
        qsimpleshape_8->setObjectName(QStringLiteral("qsimpleshape_8"));
        sizePolicy1.setHeightForWidth(qsimpleshape_8->sizePolicy().hasHeightForWidth());
        qsimpleshape_8->setSizePolicy(sizePolicy1);
        qsimpleshape_8->setShape(QSimpleShape::roundRectangle);
        qsimpleshape_8->setProperty("colour0", QVariant(QColor(255, 0, 0)));

        gridLayout_2->addWidget(qsimpleshape_8, 0, 1, 1, 1);

        label_16 = new QLabel(HESEB_ScanTool_I0_ItvsTime);
        label_16->setObjectName(QStringLiteral("label_16"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_16->setFont(font2);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_16, 1, 2, 1, 1);

        label_19 = new QLabel(HESEB_ScanTool_I0_ItvsTime);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy2.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy2);
        label_19->setFont(font2);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_19, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(950, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 3, 1);


        gridLayout->addLayout(gridLayout_2, 2, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_18 = new QLabel(HESEB_ScanTool_I0_ItvsTime);
        label_18->setObjectName(QStringLiteral("label_18"));
        QFont font3;
        font3.setFamily(QStringLiteral("Monospace"));
        font3.setPointSize(14);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        font3.setKerning(true);
        font3.setStyleStrategy(QFont::PreferDefault);
        label_18->setFont(font3);
        label_18->setLayoutDirection(Qt::LeftToRight);
        label_18->setStyleSheet(QLatin1String(".label_14{\n"
"transform: rotate(-90deg);\n"
"}"));
        label_18->setAlignment(Qt::AlignCenter);
        label_18->setWordWrap(false);

        gridLayout_8->addWidget(label_18, 0, 0, 1, 1);

        label_17 = new QLabel(HESEB_ScanTool_I0_ItvsTime);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font3);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_17, 1, 1, 1, 1);

        Status = new QLabel(HESEB_ScanTool_I0_ItvsTime);
        Status->setObjectName(QStringLiteral("Status"));

        gridLayout_8->addWidget(Status, 2, 0, 1, 2);

        qeplotter_4 = new QEPlotter(HESEB_ScanTool_I0_ItvsTime);
        qeplotter_4->setObjectName(QStringLiteral("qeplotter_4"));
        qeplotter_4->setProperty("pvItemsIsVisible", QVariant(false));
        qeplotter_4->setProperty("statusIsVisible", QVariant(false));
        qeplotter_4->setXMaximum(1);
        qeplotter_4->setYMinimum(0);
        qeplotter_4->setYMaximum(1);

        gridLayout_8->addWidget(qeplotter_4, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_8, 3, 0, 1, 1);


        retranslateUi(HESEB_ScanTool_I0_ItvsTime);

        QMetaObject::connectSlotsByName(HESEB_ScanTool_I0_ItvsTime);
    } // setupUi

    void retranslateUi(QDialog *HESEB_ScanTool_I0_ItvsTime)
    {
        HESEB_ScanTool_I0_ItvsTime->setWindowTitle(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "Dialog", Q_NULLPTR));
        lblTitle_4->setText(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "<html><head/><body><p>DCA | HESEB | SCAN TOOL | I<span style=\" vertical-align:sub;\">0(A)_</span>Itrans<span style=\" vertical-align:sub;\">(A) </span>Time<span style=\" vertical-align:sub;\">(s)</span></p></body></html>", Q_NULLPTR));
        Stop->setText(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "Stop", Q_NULLPTR));
        Int_time->setPlaceholderText(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "Enter Integration Time ... * The allowable values are: {0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2, 2.25, 2.5, 2.75, 3, 3.25, 3.5, 3.75, 4, 5, 6, 7, 8, 9}", Q_NULLPTR));
        label->setText(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "Integration Time", Q_NULLPTR));
        Start->setText(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "Start ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "BL Parameters", Q_NULLPTR));
        label_16->setText(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "<html><head/><body><p>I<span style=\" vertical-align:sub;\">Trans.</span></p></body></html>", Q_NULLPTR));
        label_19->setText(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "<html><head/><body><p>I<span style=\" vertical-align:sub;\">0</span></p></body></html>", Q_NULLPTR));
        label_18->setText(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "Current (A)", Q_NULLPTR));
        label_17->setText(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "<html><head/><body><p>Time(s) = Index * Int. Time</p></body></html>", Q_NULLPTR));
        Status->setText(QString());
        qeplotter_4->setProperty("DataVariableX", QVariant(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "I0:PLOT:INDEX", Q_NULLPTR)));
        qeplotter_4->setProperty("DataVariableA", QVariant(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "PLOT:I0", Q_NULLPTR)));
        qeplotter_4->setProperty("DataVariableB", QVariant(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "PLOT:It", Q_NULLPTR)));
        qeplotter_4->setProperty("SizeVariableX", QVariant(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "I0:PLOT:INDEX.NORD", Q_NULLPTR)));
        qeplotter_4->setProperty("SizeVariableA", QVariant(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "PLOT:I0.NORD", Q_NULLPTR)));
        qeplotter_4->setProperty("SizeVariableB", QVariant(QApplication::translate("HESEB_ScanTool_I0_ItvsTime", "PLOT:It.NORD", Q_NULLPTR)));
    } // retranslateUi

};

namespace Ui {
    class HESEB_ScanTool_I0_ItvsTime: public Ui_HESEB_ScanTool_I0_ItvsTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HESEB_SCANTOOL_I0_ITVSTIME_H
