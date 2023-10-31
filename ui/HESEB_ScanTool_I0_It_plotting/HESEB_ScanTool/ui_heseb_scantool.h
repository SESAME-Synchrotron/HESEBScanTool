/********************************************************************************
** Form generated from reading UI file 'heseb_scantool.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HESEB_SCANTOOL_H
#define UI_HESEB_SCANTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
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
    QGridLayout *actionsLayout;
    QEPushButton *stop;
    QEPushButton *resume;
    QEPushButton *pause;
    QPushButton *morevar;
    QGridLayout *scanParametersLayout;
    QLabel *outof3Label;
    QLabel *outof2Label;
    QELabel *energyVal;
    QLabel *energyLabel;
    QELabel *qelabel_6;
    QELabel *sampleXVal;
    QLabel *intervalsLabel;
    QELabel *samplesVal;
    QLabel *sampleXLabel;
    QLabel *scansLabel;
    QLabel *samplesLabel;
    QLabel *outof1Label;
    QELabel *qelabel_4;
    QELabel *intervalsVal;
    QELabel *scansVal;
    QLabel *sampleYLabel;
    QELabel *sampleYVal;
    QELabel *qelabel_5;
    QGridLayout *titleLayout;
    QLabel *titleLabel;
    QGridLayout *logsLayout;
    QLabel *logsLabel;
    QLabel *logs;
    QGridLayout *plottingLayout;
    QLabel *yLabel;
    QCheckBox *lineHasDots;
    QCheckBox *lineDashed;
    QSpacerItem *horizontalSpacer_3;
    QEPlotter *I0ItransPlotter;
    QEPlotter *IrefPlotter;
    QLabel *xyI0Itrans;
    QLabel *xyIref;
    QLabel *xLabel;
    QGridLayout *file_label_Layout;
    QSimpleShape *ItransInd;
    QLabel *ItransLabel;
    QLabel *SEDPathVal;
    QPushButton *SEDPathDir;
    QLabel *I0Label;
    QLabel *SEDPathLabel;
    QSimpleShape *I0Ind;
    QSimpleShape *IrefInd;
    QLabel *IrefLabel;
    QSpacerItem *horizontalSpacer;
    QGridLayout *timeLayout;
    QLabel *elapsedTimeLabel;
    QELabel *elapsedTimeVal;
    QLabel *startTimeLabel;
    QELabel *startTimeVal;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *HESEB_ScanTool)
    {
        if (HESEB_ScanTool->objectName().isEmpty())
            HESEB_ScanTool->setObjectName(QString::fromUtf8("HESEB_ScanTool"));
        HESEB_ScanTool->resize(1300, 1000);
        centralwidget = new QWidget(HESEB_ScanTool);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_8 = new QGridLayout(centralwidget);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        actionsLayout = new QGridLayout();
        actionsLayout->setObjectName(QString::fromUtf8("actionsLayout"));
        stop = new QEPushButton(centralwidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        QPalette palette;
        QBrush brush(QColor(239, 41, 41, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        stop->setPalette(palette);
        QFont font;
        font.setUnderline(false);
        font.setKerning(false);
        stop->setFont(font);
        stop->setCursor(QCursor(Qt::PointingHandCursor));
        stop->setAutoFillBackground(true);

        actionsLayout->addWidget(stop, 0, 3, 1, 1);

        resume = new QEPushButton(centralwidget);
        resume->setObjectName(QString::fromUtf8("resume"));
        resume->setCursor(QCursor(Qt::PointingHandCursor));

        actionsLayout->addWidget(resume, 0, 2, 1, 1);

        pause = new QEPushButton(centralwidget);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setCursor(QCursor(Qt::PointingHandCursor));

        actionsLayout->addWidget(pause, 0, 1, 1, 1);

        morevar = new QPushButton(centralwidget);
        morevar->setObjectName(QString::fromUtf8("morevar"));
        morevar->setCursor(QCursor(Qt::PointingHandCursor));

        actionsLayout->addWidget(morevar, 0, 4, 1, 1);


        gridLayout_8->addLayout(actionsLayout, 1, 2, 1, 1);

        scanParametersLayout = new QGridLayout();
        scanParametersLayout->setSpacing(0);
        scanParametersLayout->setObjectName(QString::fromUtf8("scanParametersLayout"));
        outof3Label = new QLabel(centralwidget);
        outof3Label->setObjectName(QString::fromUtf8("outof3Label"));
        outof3Label->setAlignment(Qt::AlignCenter);

        scanParametersLayout->addWidget(outof3Label, 2, 2, 1, 1);

        outof2Label = new QLabel(centralwidget);
        outof2Label->setObjectName(QString::fromUtf8("outof2Label"));
        outof2Label->setAlignment(Qt::AlignCenter);

        scanParametersLayout->addWidget(outof2Label, 1, 2, 1, 1);

        energyVal = new QELabel(centralwidget);
        energyVal->setObjectName(QString::fromUtf8("energyVal"));
        energyVal->setFrameShape(QFrame::StyledPanel);

        scanParametersLayout->addWidget(energyVal, 2, 5, 1, 1);

        energyLabel = new QLabel(centralwidget);
        energyLabel->setObjectName(QString::fromUtf8("energyLabel"));
        energyLabel->setAlignment(Qt::AlignCenter);

        scanParametersLayout->addWidget(energyLabel, 2, 4, 1, 1);

        qelabel_6 = new QELabel(centralwidget);
        qelabel_6->setObjectName(QString::fromUtf8("qelabel_6"));
        qelabel_6->setFrameShape(QFrame::StyledPanel);

        scanParametersLayout->addWidget(qelabel_6, 1, 3, 1, 1);

        sampleXVal = new QELabel(centralwidget);
        sampleXVal->setObjectName(QString::fromUtf8("sampleXVal"));
        sampleXVal->setFrameShape(QFrame::StyledPanel);

        scanParametersLayout->addWidget(sampleXVal, 0, 5, 1, 1);

        intervalsLabel = new QLabel(centralwidget);
        intervalsLabel->setObjectName(QString::fromUtf8("intervalsLabel"));

        scanParametersLayout->addWidget(intervalsLabel, 2, 0, 1, 1);

        samplesVal = new QELabel(centralwidget);
        samplesVal->setObjectName(QString::fromUtf8("samplesVal"));
        samplesVal->setFrameShape(QFrame::StyledPanel);

        scanParametersLayout->addWidget(samplesVal, 0, 1, 1, 1);

        sampleXLabel = new QLabel(centralwidget);
        sampleXLabel->setObjectName(QString::fromUtf8("sampleXLabel"));
        sampleXLabel->setAlignment(Qt::AlignCenter);

        scanParametersLayout->addWidget(sampleXLabel, 0, 4, 1, 1);

        scansLabel = new QLabel(centralwidget);
        scansLabel->setObjectName(QString::fromUtf8("scansLabel"));

        scanParametersLayout->addWidget(scansLabel, 1, 0, 1, 1);

        samplesLabel = new QLabel(centralwidget);
        samplesLabel->setObjectName(QString::fromUtf8("samplesLabel"));

        scanParametersLayout->addWidget(samplesLabel, 0, 0, 1, 1);

        outof1Label = new QLabel(centralwidget);
        outof1Label->setObjectName(QString::fromUtf8("outof1Label"));
        outof1Label->setAlignment(Qt::AlignCenter);

        scanParametersLayout->addWidget(outof1Label, 0, 2, 1, 1);

        qelabel_4 = new QELabel(centralwidget);
        qelabel_4->setObjectName(QString::fromUtf8("qelabel_4"));
        qelabel_4->setFrameShape(QFrame::StyledPanel);

        scanParametersLayout->addWidget(qelabel_4, 0, 3, 1, 1);

        intervalsVal = new QELabel(centralwidget);
        intervalsVal->setObjectName(QString::fromUtf8("intervalsVal"));
        intervalsVal->setFrameShape(QFrame::StyledPanel);

        scanParametersLayout->addWidget(intervalsVal, 2, 1, 1, 1);

        scansVal = new QELabel(centralwidget);
        scansVal->setObjectName(QString::fromUtf8("scansVal"));
        scansVal->setFrameShape(QFrame::StyledPanel);

        scanParametersLayout->addWidget(scansVal, 1, 1, 1, 1);

        sampleYLabel = new QLabel(centralwidget);
        sampleYLabel->setObjectName(QString::fromUtf8("sampleYLabel"));
        sampleYLabel->setAlignment(Qt::AlignCenter);

        scanParametersLayout->addWidget(sampleYLabel, 1, 4, 1, 1);

        sampleYVal = new QELabel(centralwidget);
        sampleYVal->setObjectName(QString::fromUtf8("sampleYVal"));
        sampleYVal->setFrameShape(QFrame::StyledPanel);

        scanParametersLayout->addWidget(sampleYVal, 1, 5, 1, 1);

        qelabel_5 = new QELabel(centralwidget);
        qelabel_5->setObjectName(QString::fromUtf8("qelabel_5"));
        qelabel_5->setFrameShape(QFrame::StyledPanel);

        scanParametersLayout->addWidget(qelabel_5, 2, 3, 1, 1);


        gridLayout_8->addLayout(scanParametersLayout, 2, 0, 2, 1);

        titleLayout = new QGridLayout();
        titleLayout->setObjectName(QString::fromUtf8("titleLayout"));
        titleLayout->setSizeConstraint(QLayout::SetMinimumSize);
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(16);
        titleLabel->setFont(font1);
        titleLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-radius: 5px;\n"
"margin-top: 0.5em;\n"
"subcontrol-origin: margin;\n"
"left: 10px;\n"
"padding: 0 3px 0 3px;"));
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setMargin(11);

        titleLayout->addWidget(titleLabel, 0, 0, 1, 1);


        gridLayout_8->addLayout(titleLayout, 0, 0, 1, 3);

        logsLayout = new QGridLayout();
        logsLayout->setObjectName(QString::fromUtf8("logsLayout"));
        logsLabel = new QLabel(centralwidget);
        logsLabel->setObjectName(QString::fromUtf8("logsLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logsLabel->sizePolicy().hasHeightForWidth());
        logsLabel->setSizePolicy(sizePolicy1);
        logsLabel->setMargin(5);

        logsLayout->addWidget(logsLabel, 0, 0, 1, 1);

        logs = new QLabel(centralwidget);
        logs->setObjectName(QString::fromUtf8("logs"));
        logs->setCursor(QCursor(Qt::IBeamCursor));
        logs->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        logs->setFrameShape(QFrame::StyledPanel);
        logs->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        logs->setWordWrap(true);
        logs->setIndent(6);

        logsLayout->addWidget(logs, 1, 0, 1, 1);


        gridLayout_8->addLayout(logsLayout, 1, 1, 3, 1);

        plottingLayout = new QGridLayout();
        plottingLayout->setObjectName(QString::fromUtf8("plottingLayout"));
        yLabel = new QLabel(centralwidget);
        yLabel->setObjectName(QString::fromUtf8("yLabel"));

        plottingLayout->addWidget(yLabel, 1, 0, 3, 1);

        lineHasDots = new QCheckBox(centralwidget);
        lineHasDots->setObjectName(QString::fromUtf8("lineHasDots"));
        lineHasDots->setCursor(QCursor(Qt::PointingHandCursor));

        plottingLayout->addWidget(lineHasDots, 0, 2, 1, 1);

        lineDashed = new QCheckBox(centralwidget);
        lineDashed->setObjectName(QString::fromUtf8("lineDashed"));
        lineDashed->setCursor(QCursor(Qt::PointingHandCursor));

        plottingLayout->addWidget(lineDashed, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        plottingLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        I0ItransPlotter = new QEPlotter(centralwidget);
        I0ItransPlotter->setObjectName(QString::fromUtf8("I0ItransPlotter"));
        I0ItransPlotter->setCursor(QCursor(Qt::CrossCursor));
        I0ItransPlotter->setMouseTracking(true);
        I0ItransPlotter->setProperty("toolBarIsVisible", QVariant(true));
        I0ItransPlotter->setProperty("pvItemsIsVisible", QVariant(false));
        I0ItransPlotter->setProperty("statusIsVisible", QVariant(false));
        I0ItransPlotter->setColourA(QColor(23, 69, 243));
        I0ItransPlotter->setColourB(QColor(255, 0, 0));

        plottingLayout->addWidget(I0ItransPlotter, 1, 1, 1, 3);

        IrefPlotter = new QEPlotter(centralwidget);
        IrefPlotter->setObjectName(QString::fromUtf8("IrefPlotter"));
        IrefPlotter->setCursor(QCursor(Qt::CrossCursor));
        IrefPlotter->setMouseTracking(true);
        IrefPlotter->setScaledContents(false);
        IrefPlotter->setProperty("toolBarIsVisible", QVariant(true));
        IrefPlotter->setProperty("pvItemsIsVisible", QVariant(false));
        IrefPlotter->setProperty("statusIsVisible", QVariant(false));
        IrefPlotter->setColourA(QColor(0, 255, 0));

        plottingLayout->addWidget(IrefPlotter, 3, 1, 1, 3);

        xyI0Itrans = new QLabel(centralwidget);
        xyI0Itrans->setObjectName(QString::fromUtf8("xyI0Itrans"));
        xyI0Itrans->setCursor(QCursor(Qt::IBeamCursor));

        plottingLayout->addWidget(xyI0Itrans, 2, 1, 1, 3);

        xyIref = new QLabel(centralwidget);
        xyIref->setObjectName(QString::fromUtf8("xyIref"));
        xyIref->setCursor(QCursor(Qt::IBeamCursor));

        plottingLayout->addWidget(xyIref, 4, 1, 1, 3);

        xLabel = new QLabel(centralwidget);
        xLabel->setObjectName(QString::fromUtf8("xLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Monospace"));
        font2.setPointSize(9);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        xLabel->setFont(font2);
        xLabel->setAlignment(Qt::AlignCenter);

        plottingLayout->addWidget(xLabel, 5, 1, 1, 3);


        gridLayout_8->addLayout(plottingLayout, 4, 0, 1, 3);

        file_label_Layout = new QGridLayout();
        file_label_Layout->setObjectName(QString::fromUtf8("file_label_Layout"));
        ItransInd = new QSimpleShape(centralwidget);
        ItransInd->setObjectName(QString::fromUtf8("ItransInd"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ItransInd->sizePolicy().hasHeightForWidth());
        ItransInd->setSizePolicy(sizePolicy2);
        ItransInd->setShape(QSimpleShape::roundRectangle);
        ItransInd->setProperty("colour0", QVariant(QColor(255, 0, 0)));

        file_label_Layout->addWidget(ItransInd, 3, 2, 1, 1);

        ItransLabel = new QLabel(centralwidget);
        ItransLabel->setObjectName(QString::fromUtf8("ItransLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ItransLabel->sizePolicy().hasHeightForWidth());
        ItransLabel->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        ItransLabel->setFont(font3);
        ItransLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        file_label_Layout->addWidget(ItransLabel, 3, 3, 1, 1);

        SEDPathVal = new QLabel(centralwidget);
        SEDPathVal->setObjectName(QString::fromUtf8("SEDPathVal"));
        SEDPathVal->setCursor(QCursor(Qt::IBeamCursor));
        SEDPathVal->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        SEDPathVal->setFrameShape(QFrame::StyledPanel);
        SEDPathVal->setWordWrap(true);
        SEDPathVal->setIndent(6);

        file_label_Layout->addWidget(SEDPathVal, 0, 1, 2, 1);

        SEDPathDir = new QPushButton(centralwidget);
        SEDPathDir->setObjectName(QString::fromUtf8("SEDPathDir"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(SEDPathDir->sizePolicy().hasHeightForWidth());
        SEDPathDir->setSizePolicy(sizePolicy4);
        SEDPathDir->setCursor(QCursor(Qt::PointingHandCursor));

        file_label_Layout->addWidget(SEDPathDir, 0, 2, 2, 1);

        I0Label = new QLabel(centralwidget);
        I0Label->setObjectName(QString::fromUtf8("I0Label"));
        sizePolicy3.setHeightForWidth(I0Label->sizePolicy().hasHeightForWidth());
        I0Label->setSizePolicy(sizePolicy3);
        I0Label->setFont(font3);
        I0Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        file_label_Layout->addWidget(I0Label, 2, 3, 1, 1);

        SEDPathLabel = new QLabel(centralwidget);
        SEDPathLabel->setObjectName(QString::fromUtf8("SEDPathLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(SEDPathLabel->sizePolicy().hasHeightForWidth());
        SEDPathLabel->setSizePolicy(sizePolicy5);

        file_label_Layout->addWidget(SEDPathLabel, 0, 0, 2, 1);

        I0Ind = new QSimpleShape(centralwidget);
        I0Ind->setObjectName(QString::fromUtf8("I0Ind"));
        sizePolicy2.setHeightForWidth(I0Ind->sizePolicy().hasHeightForWidth());
        I0Ind->setSizePolicy(sizePolicy2);
        I0Ind->setShape(QSimpleShape::roundRectangle);
        I0Ind->setProperty("colour0", QVariant(QColor(23, 69, 243)));

        file_label_Layout->addWidget(I0Ind, 2, 2, 1, 1);

        IrefInd = new QSimpleShape(centralwidget);
        IrefInd->setObjectName(QString::fromUtf8("IrefInd"));
        IrefInd->setShape(QSimpleShape::roundRectangle);
        IrefInd->setProperty("colour0", QVariant(QColor(0, 255, 0)));

        file_label_Layout->addWidget(IrefInd, 4, 2, 1, 1);

        IrefLabel = new QLabel(centralwidget);
        IrefLabel->setObjectName(QString::fromUtf8("IrefLabel"));
        QFont font4;
        font4.setPointSize(12);
        IrefLabel->setFont(font4);
        IrefLabel->setMouseTracking(true);
        IrefLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        file_label_Layout->addWidget(IrefLabel, 4, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        file_label_Layout->addItem(horizontalSpacer, 2, 0, 3, 1);


        gridLayout_8->addLayout(file_label_Layout, 3, 2, 1, 1);

        timeLayout = new QGridLayout();
        timeLayout->setObjectName(QString::fromUtf8("timeLayout"));
        elapsedTimeLabel = new QLabel(centralwidget);
        elapsedTimeLabel->setObjectName(QString::fromUtf8("elapsedTimeLabel"));
        sizePolicy5.setHeightForWidth(elapsedTimeLabel->sizePolicy().hasHeightForWidth());
        elapsedTimeLabel->setSizePolicy(sizePolicy5);

        timeLayout->addWidget(elapsedTimeLabel, 0, 3, 1, 1);

        elapsedTimeVal = new QELabel(centralwidget);
        elapsedTimeVal->setObjectName(QString::fromUtf8("elapsedTimeVal"));
        elapsedTimeVal->setFrameShape(QFrame::StyledPanel);
        elapsedTimeVal->setAlignment(Qt::AlignCenter);

        timeLayout->addWidget(elapsedTimeVal, 0, 4, 1, 1);

        startTimeLabel = new QLabel(centralwidget);
        startTimeLabel->setObjectName(QString::fromUtf8("startTimeLabel"));
        sizePolicy5.setHeightForWidth(startTimeLabel->sizePolicy().hasHeightForWidth());
        startTimeLabel->setSizePolicy(sizePolicy5);

        timeLayout->addWidget(startTimeLabel, 0, 0, 1, 1);

        startTimeVal = new QELabel(centralwidget);
        startTimeVal->setObjectName(QString::fromUtf8("startTimeVal"));
        startTimeVal->setFrameShape(QFrame::StyledPanel);
        startTimeVal->setAlignment(Qt::AlignCenter);

        timeLayout->addWidget(startTimeVal, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        timeLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_8->addLayout(timeLayout, 1, 0, 1, 1);

        HESEB_ScanTool->setCentralWidget(centralwidget);

        retranslateUi(HESEB_ScanTool);

        QMetaObject::connectSlotsByName(HESEB_ScanTool);
    } // setupUi

    void retranslateUi(QMainWindow *HESEB_ScanTool)
    {
        HESEB_ScanTool->setWindowTitle(QCoreApplication::translate("HESEB_ScanTool", "HESEB_ScanTool", nullptr));
        stop->setText(QCoreApplication::translate("HESEB_ScanTool", "Stop!!", nullptr));
        stop->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:STOP", nullptr)));
        stop->setClickText(QCoreApplication::translate("HESEB_ScanTool", "1", nullptr));
        resume->setText(QCoreApplication::translate("HESEB_ScanTool", "Resume", nullptr));
        resume->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:XAFSPause", nullptr)));
        resume->setClickText(QCoreApplication::translate("HESEB_ScanTool", "0", nullptr));
        pause->setText(QCoreApplication::translate("HESEB_ScanTool", "Pause", nullptr));
        pause->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:XAFSPause", nullptr)));
        morevar->setText(QCoreApplication::translate("HESEB_ScanTool", "BL Parameters", nullptr));
        outof3Label->setText(QCoreApplication::translate("HESEB_ScanTool", "out of", nullptr));
        outof2Label->setText(QCoreApplication::translate("HESEB_ScanTool", "out of", nullptr));
        energyVal->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "I11OH-PGM:getEnergy", nullptr)));
        energyLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "Energy (eV)", nullptr));
        qelabel_6->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:Nscans", nullptr)));
        sampleXVal->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "motorSimIOC:FE-M1-STP-TRSX1", nullptr)));
        intervalsLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "Intervals", nullptr));
        samplesVal->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:CurrentSample", nullptr)));
        sampleXLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "Sample X", nullptr));
        scansLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "Scans", nullptr));
        samplesLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "Sample", nullptr));
        outof1Label->setText(QCoreApplication::translate("HESEB_ScanTool", "out of", nullptr));
        qelabel_4->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:Nsamples", nullptr)));
        intervalsVal->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:CurrentInterval", nullptr)));
        scansVal->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:CurrentScan", nullptr)));
        sampleYLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "Sample Y", nullptr));
        sampleYVal->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "motorSimIOC:FE-M1-STP-TRSY1", nullptr)));
        qelabel_5->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:NIntervals", nullptr)));
        titleLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "<html><head/><body><p>DCA | HESEB | SCAN TOOL | I<span style=\" vertical-align:sub;\">0(A)_ </span>I<span style=\" vertical-align:sub;\">Trans(A) vs. </span>Energy<span style=\" vertical-align:sub;\">(eV)</span></p></body></html>", nullptr));
        logsLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "Scan tool status ", nullptr));
        logs->setText(QString());
        yLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "<html><head/><body><p><span style=\" font-weight:600;\">Current (A)</span></p></body></html>", nullptr));
        lineHasDots->setText(QCoreApplication::translate("HESEB_ScanTool", "Line HasDots", nullptr));
        lineDashed->setText(QCoreApplication::translate("HESEB_ScanTool", "Line Dashed", nullptr));
        I0ItransPlotter->setProperty("contextMenuEmitText", QVariant(QCoreApplication::translate("HESEB_ScanTool", "X,Y", nullptr)));
        I0ItransPlotter->setProperty("DataVariableX", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:Energy", nullptr)));
        I0ItransPlotter->setProperty("DataVariableA", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:I0", nullptr)));
        I0ItransPlotter->setProperty("DataVariableB", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:It", nullptr)));
        I0ItransPlotter->setProperty("DataVariableC", QVariant(QString()));
        I0ItransPlotter->setProperty("SizeVariableX", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:Energy.NORD", nullptr)));
        I0ItransPlotter->setProperty("SizeVariableA", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:I0.NORD", nullptr)));
        I0ItransPlotter->setProperty("SizeVariableB", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:It.NORD", nullptr)));
        I0ItransPlotter->setProperty("SizeVariableC", QVariant(QString()));
        I0ItransPlotter->setProperty("AliasNameX", QVariant(QString()));
        I0ItransPlotter->setProperty("AliasNameA", QVariant(QString()));
        I0ItransPlotter->setProperty("aliasNames", QVariant(QStringList()
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
        IrefPlotter->setProperty("contextMenuEmitText", QVariant(QCoreApplication::translate("HESEB_ScanTool", "X,Y", nullptr)));
        IrefPlotter->setProperty("DataVariableX", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:Energy", nullptr)));
        IrefPlotter->setProperty("DataVariableA", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:AbsTr", nullptr)));
        IrefPlotter->setProperty("SizeVariableX", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:Energy.NORD", nullptr)));
        IrefPlotter->setProperty("SizeVariableA", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:AbsTr.NORD", nullptr)));
        xyI0Itrans->setText(QString());
        xyIref->setText(QString());
        xLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "<html><head/><body><p><span style=\" font-weight:600;\">Energy (eV)</span></p></body></html>", nullptr));
        ItransLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "<html><head/><body><p>I<span style=\" vertical-align:sub;\">Trans.</span></p></body></html>", nullptr));
        SEDPathVal->setText(QString());
        SEDPathDir->setText(QCoreApplication::translate("HESEB_ScanTool", "...", nullptr));
        I0Label->setText(QCoreApplication::translate("HESEB_ScanTool", "<html><head/><body><p>I<span style=\" vertical-align:sub;\">0</span></p></body></html>", nullptr));
        SEDPathLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "SED Path:", nullptr));
        IrefLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "<html><head/><body><p><span style=\" font-weight:600;\">I</span><span style=\" font-weight:600; vertical-align:sub;\">ref</span></p></body></html>", nullptr));
        elapsedTimeLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "Elapsed time", nullptr));
        elapsedTimeVal->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:ELAPSE", nullptr)));
        startTimeLabel->setText(QCoreApplication::translate("HESEB_ScanTool", "Start time", nullptr));
        startTimeVal->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:START", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class HESEB_ScanTool: public Ui_HESEB_ScanTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HESEB_SCANTOOL_H
