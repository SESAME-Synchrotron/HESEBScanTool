/********************************************************************************
** Form generated from reading UI file 'heseb_scantool.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HESEB_SCANTOOL_H
#define UI_HESEB_SCANTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "QEFrame.h"
#include "QELabel.h"
#include "QEPlotter.h"
#include "QEPushButton.h"
#include "QSimpleShape.h"

QT_BEGIN_NAMESPACE

class Ui_HESEB_ScanTool
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QELabel *qelabel_10;
    QGridLayout *gridLayout_9;
    QLabel *label_12;
    QELabel *qelabel_12;
    QLabel *label;
    QELabel *qelabel_11;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_4;
    QLabel *label_14;
    QEPlotter *qeplotter;
    QLabel *label_13;
    QGridLayout *gridLayout_2;
    QEPushButton *qepushbutton_2;
    QEPushButton *qepushbutton;
    QEPushButton *qepushbutton_3;
    QGridLayout *gridLayout;
    QLabel *label_11;
    QLabel *label_9;
    QELabel *qelabel_9;
    QLabel *label_6;
    QELabel *qelabel_6;
    QELabel *qelabel_7;
    QLabel *label_3;
    QELabel *qelabel;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_10;
    QELabel *qelabel_4;
    QELabel *qelabel_3;
    QELabel *qelabel_2;
    QLabel *label_5;
    QELabel *qelabel_8;
    QELabel *qelabel_5;
    QGridLayout *gridLayout_6;
    QLabel *lblTitle_2;
    QGridLayout *gridLayout_7;
    QSimpleShape *qsimpleshape_2;
    QSimpleShape *qsimpleshape_8;
    QLabel *label_15;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer;
    QELabel *qelabel_13;
    QPushButton *pushButton;
    QLabel *label_17;

    void setupUi(QMainWindow *HESEB_ScanTool)
    {
        if (HESEB_ScanTool->objectName().isEmpty())
            HESEB_ScanTool->setObjectName(QStringLiteral("HESEB_ScanTool"));
        HESEB_ScanTool->resize(1280, 857);
        centralwidget = new QWidget(HESEB_ScanTool);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_8 = new QGridLayout(centralwidget);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        qelabel_10 = new QELabel(centralwidget);
        qelabel_10->setObjectName(QStringLiteral("qelabel_10"));

        gridLayout_3->addWidget(qelabel_10, 1, 0, 2, 1);


        gridLayout_8->addLayout(gridLayout_3, 1, 1, 3, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);

        gridLayout_9->addWidget(label_12, 0, 3, 1, 1);

        qelabel_12 = new QELabel(centralwidget);
        qelabel_12->setObjectName(QStringLiteral("qelabel_12"));
        qelabel_12->setFrameShape(QFrame::StyledPanel);
        qelabel_12->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(qelabel_12, 0, 4, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_9->addWidget(label, 0, 0, 1, 1);

        qelabel_11 = new QELabel(centralwidget);
        qelabel_11->setObjectName(QStringLiteral("qelabel_11"));
        qelabel_11->setFrameShape(QFrame::StyledPanel);
        qelabel_11->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(qelabel_11, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout_9, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        QFont font;
        font.setFamily(QStringLiteral("Monospace"));
        font.setPointSize(14);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        label_14->setFont(font);
        label_14->setLayoutDirection(Qt::LeftToRight);
        label_14->setStyleSheet(QLatin1String(".label_14{\n"
"transform: rotate(-90deg);\n"
"}"));
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setWordWrap(false);

        gridLayout_4->addWidget(label_14, 0, 0, 1, 1);

        qeplotter = new QEPlotter(centralwidget);
        qeplotter->setObjectName(QStringLiteral("qeplotter"));
        qeplotter->setCursor(QCursor(Qt::CrossCursor));
        qeplotter->setProperty("toolBarIsVisible", QVariant(false));
        qeplotter->setProperty("pvItemsIsVisible", QVariant(false));
        qeplotter->setProperty("statusIsVisible", QVariant(false));
        qeplotter->setColourA(QColor(23, 69, 243));
        qeplotter->setColourB(QColor(255, 0, 0));

        gridLayout_4->addWidget(qeplotter, 0, 1, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_13, 1, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_4, 4, 0, 1, 3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        qepushbutton_2 = new QEPushButton(centralwidget);
        qepushbutton_2->setObjectName(QStringLiteral("qepushbutton_2"));
        qepushbutton_2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(qepushbutton_2, 0, 2, 1, 1);

        qepushbutton = new QEPushButton(centralwidget);
        qepushbutton->setObjectName(QStringLiteral("qepushbutton"));
        qepushbutton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(qepushbutton, 0, 1, 1, 1);

        qepushbutton_3 = new QEPushButton(centralwidget);
        qepushbutton_3->setObjectName(QStringLiteral("qepushbutton_3"));
        QPalette palette;
        QBrush brush(QColor(239, 41, 41, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        qepushbutton_3->setPalette(palette);
        QFont font1;
        font1.setUnderline(false);
        font1.setKerning(false);
        qepushbutton_3->setFont(font1);
        qepushbutton_3->setCursor(QCursor(Qt::PointingHandCursor));
        qepushbutton_3->setAutoFillBackground(true);

        gridLayout_2->addWidget(qepushbutton_3, 0, 3, 1, 1);


        gridLayout_8->addLayout(gridLayout_2, 1, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 2, 2, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 1, 2, 1, 1);

        qelabel_9 = new QELabel(centralwidget);
        qelabel_9->setObjectName(QStringLiteral("qelabel_9"));
        qelabel_9->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_9, 2, 5, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 2, 4, 1, 1);

        qelabel_6 = new QELabel(centralwidget);
        qelabel_6->setObjectName(QStringLiteral("qelabel_6"));
        qelabel_6->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_6, 1, 3, 1, 1);

        qelabel_7 = new QELabel(centralwidget);
        qelabel_7->setObjectName(QStringLiteral("qelabel_7"));
        qelabel_7->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_7, 0, 5, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        qelabel = new QELabel(centralwidget);
        qelabel->setObjectName(QStringLiteral("qelabel"));
        qelabel->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel, 0, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 4, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 0, 2, 1, 1);

        qelabel_4 = new QELabel(centralwidget);
        qelabel_4->setObjectName(QStringLiteral("qelabel_4"));
        qelabel_4->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_4, 0, 3, 1, 1);

        qelabel_3 = new QELabel(centralwidget);
        qelabel_3->setObjectName(QStringLiteral("qelabel_3"));
        qelabel_3->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_3, 2, 1, 1, 1);

        qelabel_2 = new QELabel(centralwidget);
        qelabel_2->setObjectName(QStringLiteral("qelabel_2"));
        qelabel_2->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_2, 1, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 4, 1, 1);

        qelabel_8 = new QELabel(centralwidget);
        qelabel_8->setObjectName(QStringLiteral("qelabel_8"));
        qelabel_8->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_8, 1, 5, 1, 1);

        qelabel_5 = new QELabel(centralwidget);
        qelabel_5->setObjectName(QStringLiteral("qelabel_5"));
        qelabel_5->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_5, 2, 3, 1, 1);


        gridLayout_8->addLayout(gridLayout, 2, 0, 2, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setSizeConstraint(QLayout::SetMinimumSize);
        lblTitle_2 = new QLabel(centralwidget);
        lblTitle_2->setObjectName(QStringLiteral("lblTitle_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblTitle_2->sizePolicy().hasHeightForWidth());
        lblTitle_2->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(16);
        lblTitle_2->setFont(font2);
        lblTitle_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-radius: 5px;\n"
"margin-top: 0.5em;\n"
"subcontrol-origin: margin;\n"
"left: 10px;\n"
"padding: 0 3px 0 3px;"));
        lblTitle_2->setAlignment(Qt::AlignCenter);
        lblTitle_2->setMargin(11);

        gridLayout_6->addWidget(lblTitle_2, 0, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_6, 0, 0, 1, 3);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        qsimpleshape_2 = new QSimpleShape(centralwidget);
        qsimpleshape_2->setObjectName(QStringLiteral("qsimpleshape_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(qsimpleshape_2->sizePolicy().hasHeightForWidth());
        qsimpleshape_2->setSizePolicy(sizePolicy2);
        qsimpleshape_2->setShape(QSimpleShape::roundRectangle);
        qsimpleshape_2->setProperty("colour0", QVariant(QColor(23, 69, 243)));

        gridLayout_7->addWidget(qsimpleshape_2, 2, 2, 1, 1);

        qsimpleshape_8 = new QSimpleShape(centralwidget);
        qsimpleshape_8->setObjectName(QStringLiteral("qsimpleshape_8"));
        sizePolicy2.setHeightForWidth(qsimpleshape_8->sizePolicy().hasHeightForWidth());
        qsimpleshape_8->setSizePolicy(sizePolicy2);
        qsimpleshape_8->setShape(QSimpleShape::roundRectangle);
        qsimpleshape_8->setProperty("colour0", QVariant(QColor(255, 0, 0)));

        gridLayout_7->addWidget(qsimpleshape_8, 3, 2, 1, 1);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label_15->setFont(font3);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_15, 2, 3, 1, 1);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy3.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy3);
        label_16->setFont(font3);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_16, 3, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 2, 0, 2, 1);

        qelabel_13 = new QELabel(centralwidget);
        qelabel_13->setObjectName(QStringLiteral("qelabel_13"));
        qelabel_13->setFrameShape(QFrame::StyledPanel);

        gridLayout_7->addWidget(qelabel_13, 0, 1, 2, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy4);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_7->addWidget(pushButton, 0, 2, 2, 1);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_17, 0, 0, 2, 1);


        gridLayout_8->addLayout(gridLayout_7, 3, 2, 1, 1);

        HESEB_ScanTool->setCentralWidget(centralwidget);

        retranslateUi(HESEB_ScanTool);

        QMetaObject::connectSlotsByName(HESEB_ScanTool);
    } // setupUi

    void retranslateUi(QMainWindow *HESEB_ScanTool)
    {
        HESEB_ScanTool->setWindowTitle(QApplication::translate("HESEB_ScanTool", "HESEB_ScanTool", Q_NULLPTR));
        label_7->setText(QApplication::translate("HESEB_ScanTool", "Scan tool status ", Q_NULLPTR));
        qelabel_10->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "EXPERIMENT:LOGS", Q_NULLPTR)));
        label_12->setText(QApplication::translate("HESEB_ScanTool", "Elapse time", Q_NULLPTR));
        qelabel_12->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "ELAPSE:TIME:SCAN", Q_NULLPTR)));
        label->setText(QApplication::translate("HESEB_ScanTool", "Start time", Q_NULLPTR));
        qelabel_11->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "START:TIME:SCAN", Q_NULLPTR)));
        label_14->setText(QApplication::translate("HESEB_ScanTool", "Current (A)", Q_NULLPTR));
        qeplotter->setProperty("DataVariableX", QVariant(QApplication::translate("HESEB_ScanTool", "PLOT:Energy", Q_NULLPTR)));
        qeplotter->setProperty("DataVariableA", QVariant(QApplication::translate("HESEB_ScanTool", "PLOT:I0", Q_NULLPTR)));
        qeplotter->setProperty("DataVariableB", QVariant(QApplication::translate("HESEB_ScanTool", "PLOT:It", Q_NULLPTR)));
        qeplotter->setProperty("DataVariableC", QVariant(QString()));
        qeplotter->setProperty("SizeVariableX", QVariant(QApplication::translate("HESEB_ScanTool", "PLOT:Energy.NORD", Q_NULLPTR)));
        qeplotter->setProperty("SizeVariableA", QVariant(QApplication::translate("HESEB_ScanTool", "PLOT:I0.NORD", Q_NULLPTR)));
        qeplotter->setProperty("SizeVariableB", QVariant(QApplication::translate("HESEB_ScanTool", "PLOT:It.NORD", Q_NULLPTR)));
        qeplotter->setProperty("SizeVariableC", QVariant(QString()));
        qeplotter->setProperty("AliasNameX", QVariant(QString()));
        qeplotter->setProperty("AliasNameA", QVariant(QString()));
        qeplotter->setProperty("aliasNames", QVariant(QStringList()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()
            << QString()));
        label_13->setText(QApplication::translate("HESEB_ScanTool", "Energy (eV)", Q_NULLPTR));
        qepushbutton_2->setText(QApplication::translate("HESEB_ScanTool", "Resume", Q_NULLPTR));
        qepushbutton_2->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "SCAN:XAFSPause", Q_NULLPTR)));
        qepushbutton_2->setClickText(QApplication::translate("HESEB_ScanTool", "0", Q_NULLPTR));
        qepushbutton->setText(QApplication::translate("HESEB_ScanTool", "Pause", Q_NULLPTR));
        qepushbutton->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "SCAN:XAFSPause", Q_NULLPTR)));
        qepushbutton_3->setText(QApplication::translate("HESEB_ScanTool", "Stop!!", Q_NULLPTR));
        qepushbutton_3->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "SCAN:PATH", Q_NULLPTR)));
        qepushbutton_3->setClickText(QApplication::translate("HESEB_ScanTool", "1", Q_NULLPTR));
        label_11->setText(QApplication::translate("HESEB_ScanTool", "out of", Q_NULLPTR));
        label_9->setText(QApplication::translate("HESEB_ScanTool", "out of", Q_NULLPTR));
        qelabel_9->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "I11OH-PGM:getEnergy", Q_NULLPTR)));
        label_6->setText(QApplication::translate("HESEB_ScanTool", "Energy (eV)", Q_NULLPTR));
        qelabel_6->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "SCAN:Nscans", Q_NULLPTR)));
        qelabel_7->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "motorSimIOC:FE-M1-STP-TRSX1", Q_NULLPTR)));
        label_3->setText(QApplication::translate("HESEB_ScanTool", "Intervals", Q_NULLPTR));
        qelabel->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "SCAN:CurrentSample", Q_NULLPTR)));
        label_4->setText(QApplication::translate("HESEB_ScanTool", "Sample X", Q_NULLPTR));
        label_2->setText(QApplication::translate("HESEB_ScanTool", "Scans", Q_NULLPTR));
        label_8->setText(QApplication::translate("HESEB_ScanTool", "Sample", Q_NULLPTR));
        label_10->setText(QApplication::translate("HESEB_ScanTool", "out of", Q_NULLPTR));
        qelabel_4->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "SCAN:Nsamples", Q_NULLPTR)));
        qelabel_3->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "SCAN:CurrentInterval", Q_NULLPTR)));
        qelabel_2->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "SCAN:CurrentScan", Q_NULLPTR)));
        label_5->setText(QApplication::translate("HESEB_ScanTool", "Sample Y", Q_NULLPTR));
        qelabel_8->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "motorSimIOC:FE-M1-STP-TRSY1", Q_NULLPTR)));
        qelabel_5->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "SCAN:NIntervals", Q_NULLPTR)));
        lblTitle_2->setText(QApplication::translate("HESEB_ScanTool", "<html><head/><body><p>DCA | HESEB | SCAN TOOL | I<span style=\" vertical-align:sub;\">0(A)_ </span>I<span style=\" vertical-align:sub;\">Trans(A) vs. </span>Energy<span style=\" vertical-align:sub;\">(eV)</span></p></body></html>", Q_NULLPTR));
        label_15->setText(QApplication::translate("HESEB_ScanTool", "<html><head/><body><p>I<span style=\" vertical-align:sub;\">0</span></p></body></html>", Q_NULLPTR));
        label_16->setText(QApplication::translate("HESEB_ScanTool", "<html><head/><body><p>I<span style=\" vertical-align:sub;\">Trans.</span></p></body></html>", Q_NULLPTR));
        qelabel_13->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool", "SCAN:PATH", Q_NULLPTR)));
        pushButton->setText(QApplication::translate("HESEB_ScanTool", "...", Q_NULLPTR));
        label_17->setText(QApplication::translate("HESEB_ScanTool", "SED Path:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HESEB_ScanTool: public Ui_HESEB_ScanTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HESEB_SCANTOOL_H
