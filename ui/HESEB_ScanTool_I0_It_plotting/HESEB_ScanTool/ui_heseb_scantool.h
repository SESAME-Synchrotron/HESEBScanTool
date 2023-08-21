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
    QGridLayout *gridLayout_4;
    QEPlotter *qeplotter_2;
    QEPlotter *qeplotter;
    QLabel *label_13;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLabel *logs;
    QGridLayout *gridLayout_2;
    QEPushButton *qepushbutton_3;
    QEPushButton *qepushbutton_2;
    QEPushButton *qepushbutton;
    QPushButton *morevar;
    QGridLayout *gridLayout_7;
    QSimpleShape *qsimpleshape_8;
    QLabel *label_16;
    QLabel *path;
    QPushButton *pushButton;
    QLabel *label_15;
    QLabel *label_17;
    QSimpleShape *qsimpleshape_2;
    QSimpleShape *qsimpleshape;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_6;
    QLabel *lblTitle_2;
    QGridLayout *gridLayout_9;
    QLabel *label_12;
    QELabel *qelabel_12;
    QLabel *label;
    QELabel *qelabel_11;
    QSpacerItem *horizontalSpacer_2;
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

    void setupUi(QMainWindow *HESEB_ScanTool)
    {
        if (HESEB_ScanTool->objectName().isEmpty())
            HESEB_ScanTool->setObjectName(QString::fromUtf8("HESEB_ScanTool"));
        HESEB_ScanTool->resize(1280, 857);
        centralwidget = new QWidget(HESEB_ScanTool);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_8 = new QGridLayout(centralwidget);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        qeplotter_2 = new QEPlotter(centralwidget);
        qeplotter_2->setObjectName(QString::fromUtf8("qeplotter_2"));
        qeplotter_2->setCursor(QCursor(Qt::CrossCursor));
        qeplotter_2->setScaledContents(false);
        qeplotter_2->setProperty("toolBarIsVisible", QVariant(false));
        qeplotter_2->setProperty("pvItemsIsVisible", QVariant(false));
        qeplotter_2->setProperty("statusIsVisible", QVariant(false));
        qeplotter_2->setColourA(QColor(0, 255, 0));

        gridLayout_4->addWidget(qeplotter_2, 1, 0, 1, 1);

        qeplotter = new QEPlotter(centralwidget);
        qeplotter->setObjectName(QString::fromUtf8("qeplotter"));
        qeplotter->setCursor(QCursor(Qt::CrossCursor));
        qeplotter->setProperty("toolBarIsVisible", QVariant(false));
        qeplotter->setProperty("pvItemsIsVisible", QVariant(false));
        qeplotter->setProperty("statusIsVisible", QVariant(false));
        qeplotter->setColourA(QColor(23, 69, 243));
        qeplotter->setColourB(QColor(255, 0, 0));

        gridLayout_4->addWidget(qeplotter, 0, 0, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        font.setPointSize(14);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_13, 2, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_4, 4, 0, 1, 3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMargin(5);

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        logs = new QLabel(centralwidget);
        logs->setObjectName(QString::fromUtf8("logs"));
        logs->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        logs->setFrameShape(QFrame::StyledPanel);
        logs->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        logs->setWordWrap(true);
        logs->setIndent(6);

        gridLayout_3->addWidget(logs, 1, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_3, 1, 1, 3, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        qepushbutton_3 = new QEPushButton(centralwidget);
        qepushbutton_3->setObjectName(QString::fromUtf8("qepushbutton_3"));
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

        qepushbutton_2 = new QEPushButton(centralwidget);
        qepushbutton_2->setObjectName(QString::fromUtf8("qepushbutton_2"));
        qepushbutton_2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(qepushbutton_2, 0, 2, 1, 1);

        qepushbutton = new QEPushButton(centralwidget);
        qepushbutton->setObjectName(QString::fromUtf8("qepushbutton"));
        qepushbutton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(qepushbutton, 0, 1, 1, 1);

        morevar = new QPushButton(centralwidget);
        morevar->setObjectName(QString::fromUtf8("morevar"));

        gridLayout_2->addWidget(morevar, 0, 4, 1, 1);


        gridLayout_8->addLayout(gridLayout_2, 1, 2, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        qsimpleshape_8 = new QSimpleShape(centralwidget);
        qsimpleshape_8->setObjectName(QString::fromUtf8("qsimpleshape_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qsimpleshape_8->sizePolicy().hasHeightForWidth());
        qsimpleshape_8->setSizePolicy(sizePolicy1);
        qsimpleshape_8->setShape(QSimpleShape::roundRectangle);
        qsimpleshape_8->setProperty("colour0", QVariant(QColor(255, 0, 0)));

        gridLayout_7->addWidget(qsimpleshape_8, 3, 2, 1, 1);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
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

        gridLayout_7->addWidget(label_16, 3, 3, 1, 1);

        path = new QLabel(centralwidget);
        path->setObjectName(QString::fromUtf8("path"));
        path->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        path->setFrameShape(QFrame::StyledPanel);
        path->setIndent(6);

        gridLayout_7->addWidget(path, 0, 1, 2, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_7->addWidget(pushButton, 0, 2, 2, 1);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);
        label_15->setFont(font2);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_15, 2, 3, 1, 1);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy4);

        gridLayout_7->addWidget(label_17, 0, 0, 2, 1);

        qsimpleshape_2 = new QSimpleShape(centralwidget);
        qsimpleshape_2->setObjectName(QString::fromUtf8("qsimpleshape_2"));
        sizePolicy1.setHeightForWidth(qsimpleshape_2->sizePolicy().hasHeightForWidth());
        qsimpleshape_2->setSizePolicy(sizePolicy1);
        qsimpleshape_2->setShape(QSimpleShape::roundRectangle);
        qsimpleshape_2->setProperty("colour0", QVariant(QColor(23, 69, 243)));

        gridLayout_7->addWidget(qsimpleshape_2, 2, 2, 1, 1);

        qsimpleshape = new QSimpleShape(centralwidget);
        qsimpleshape->setObjectName(QString::fromUtf8("qsimpleshape"));
        qsimpleshape->setShape(QSimpleShape::roundRectangle);
        qsimpleshape->setProperty("colour0", QVariant(QColor(0, 255, 0)));

        gridLayout_7->addWidget(qsimpleshape, 4, 2, 1, 1);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        QFont font3;
        font3.setPointSize(12);
        label_18->setFont(font3);
        label_18->setMouseTracking(true);
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_18, 4, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 2, 0, 3, 1);


        gridLayout_8->addLayout(gridLayout_7, 3, 2, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setSizeConstraint(QLayout::SetMinimumSize);
        lblTitle_2 = new QLabel(centralwidget);
        lblTitle_2->setObjectName(QString::fromUtf8("lblTitle_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lblTitle_2->sizePolicy().hasHeightForWidth());
        lblTitle_2->setSizePolicy(sizePolicy5);
        QFont font4;
        font4.setPointSize(16);
        lblTitle_2->setFont(font4);
        lblTitle_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
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

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy4.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy4);

        gridLayout_9->addWidget(label_12, 0, 3, 1, 1);

        qelabel_12 = new QELabel(centralwidget);
        qelabel_12->setObjectName(QString::fromUtf8("qelabel_12"));
        qelabel_12->setFrameShape(QFrame::StyledPanel);
        qelabel_12->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(qelabel_12, 0, 4, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        gridLayout_9->addWidget(label, 0, 0, 1, 1);

        qelabel_11 = new QELabel(centralwidget);
        qelabel_11->setObjectName(QString::fromUtf8("qelabel_11"));
        qelabel_11->setFrameShape(QFrame::StyledPanel);
        qelabel_11->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(qelabel_11, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout_9, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 2, 2, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 1, 2, 1, 1);

        qelabel_9 = new QELabel(centralwidget);
        qelabel_9->setObjectName(QString::fromUtf8("qelabel_9"));
        qelabel_9->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_9, 2, 5, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 2, 4, 1, 1);

        qelabel_6 = new QELabel(centralwidget);
        qelabel_6->setObjectName(QString::fromUtf8("qelabel_6"));
        qelabel_6->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_6, 1, 3, 1, 1);

        qelabel_7 = new QELabel(centralwidget);
        qelabel_7->setObjectName(QString::fromUtf8("qelabel_7"));
        qelabel_7->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_7, 0, 5, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        qelabel = new QELabel(centralwidget);
        qelabel->setObjectName(QString::fromUtf8("qelabel"));
        qelabel->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel, 0, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 4, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 0, 2, 1, 1);

        qelabel_4 = new QELabel(centralwidget);
        qelabel_4->setObjectName(QString::fromUtf8("qelabel_4"));
        qelabel_4->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_4, 0, 3, 1, 1);

        qelabel_3 = new QELabel(centralwidget);
        qelabel_3->setObjectName(QString::fromUtf8("qelabel_3"));
        qelabel_3->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_3, 2, 1, 1, 1);

        qelabel_2 = new QELabel(centralwidget);
        qelabel_2->setObjectName(QString::fromUtf8("qelabel_2"));
        qelabel_2->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_2, 1, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 4, 1, 1);

        qelabel_8 = new QELabel(centralwidget);
        qelabel_8->setObjectName(QString::fromUtf8("qelabel_8"));
        qelabel_8->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_8, 1, 5, 1, 1);

        qelabel_5 = new QELabel(centralwidget);
        qelabel_5->setObjectName(QString::fromUtf8("qelabel_5"));
        qelabel_5->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(qelabel_5, 2, 3, 1, 1);


        gridLayout_8->addLayout(gridLayout, 2, 0, 2, 1);

        HESEB_ScanTool->setCentralWidget(centralwidget);

        retranslateUi(HESEB_ScanTool);

        QMetaObject::connectSlotsByName(HESEB_ScanTool);
    } // setupUi

    void retranslateUi(QMainWindow *HESEB_ScanTool)
    {
        HESEB_ScanTool->setWindowTitle(QCoreApplication::translate("HESEB_ScanTool", "HESEB_ScanTool", nullptr));
        qeplotter_2->setProperty("DataVariableX", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:Energy", nullptr)));
        qeplotter_2->setProperty("DataVariableA", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:AbsTr", nullptr)));
        qeplotter_2->setProperty("SizeVariableX", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:Energy.NORD", nullptr)));
        qeplotter_2->setProperty("SizeVariableA", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:AbsTr.NORD", nullptr)));
        qeplotter->setProperty("DataVariableX", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:Energy", nullptr)));
        qeplotter->setProperty("DataVariableA", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:I0", nullptr)));
        qeplotter->setProperty("DataVariableB", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:It", nullptr)));
        qeplotter->setProperty("DataVariableC", QVariant(QString()));
        qeplotter->setProperty("SizeVariableX", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:Energy.NORD", nullptr)));
        qeplotter->setProperty("SizeVariableA", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:I0.NORD", nullptr)));
        qeplotter->setProperty("SizeVariableB", QVariant(QCoreApplication::translate("HESEB_ScanTool", "PLOT:It.NORD", nullptr)));
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
        label_13->setText(QCoreApplication::translate("HESEB_ScanTool", "Energy (eV)", nullptr));
        label_7->setText(QCoreApplication::translate("HESEB_ScanTool", "Scan tool status ", nullptr));
        logs->setText(QString());
        qepushbutton_3->setText(QCoreApplication::translate("HESEB_ScanTool", "Stop!!", nullptr));
        qepushbutton_3->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:STOP", nullptr)));
        qepushbutton_3->setClickText(QCoreApplication::translate("HESEB_ScanTool", "1", nullptr));
        qepushbutton_2->setText(QCoreApplication::translate("HESEB_ScanTool", "Resume", nullptr));
        qepushbutton_2->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:XAFSPause", nullptr)));
        qepushbutton_2->setClickText(QCoreApplication::translate("HESEB_ScanTool", "0", nullptr));
        qepushbutton->setText(QCoreApplication::translate("HESEB_ScanTool", "Pause", nullptr));
        qepushbutton->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:XAFSPause", nullptr)));
        morevar->setText(QCoreApplication::translate("HESEB_ScanTool", "BL Parameters", nullptr));
        label_16->setText(QCoreApplication::translate("HESEB_ScanTool", "<html><head/><body><p>I<span style=\" vertical-align:sub;\">Trans.</span></p></body></html>", nullptr));
        path->setText(QString());
        pushButton->setText(QCoreApplication::translate("HESEB_ScanTool", "...", nullptr));
        label_15->setText(QCoreApplication::translate("HESEB_ScanTool", "<html><head/><body><p>I<span style=\" vertical-align:sub;\">0</span></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("HESEB_ScanTool", "SED Path:", nullptr));
        label_18->setText(QCoreApplication::translate("HESEB_ScanTool", "<html><head/><body><p><span style=\" font-weight:600;\">I</span><span style=\" font-weight:600; vertical-align:sub;\">ref</span></p></body></html>", nullptr));
        lblTitle_2->setText(QCoreApplication::translate("HESEB_ScanTool", "<html><head/><body><p>DCA | HESEB | SCAN TOOL | I<span style=\" vertical-align:sub;\">0(A)_ </span>I<span style=\" vertical-align:sub;\">Trans(A) vs. </span>Energy<span style=\" vertical-align:sub;\">(eV)</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("HESEB_ScanTool", "Elapsed time", nullptr));
        qelabel_12->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:ELAPSE", nullptr)));
        label->setText(QCoreApplication::translate("HESEB_ScanTool", "Start time", nullptr));
        qelabel_11->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:START", nullptr)));
        label_11->setText(QCoreApplication::translate("HESEB_ScanTool", "out of", nullptr));
        label_9->setText(QCoreApplication::translate("HESEB_ScanTool", "out of", nullptr));
        qelabel_9->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "I11OH-PGM:getEnergy", nullptr)));
        label_6->setText(QCoreApplication::translate("HESEB_ScanTool", "Energy (eV)", nullptr));
        qelabel_6->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:Nscans", nullptr)));
        qelabel_7->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "motorSimIOC:FE-M1-STP-TRSX1", nullptr)));
        label_3->setText(QCoreApplication::translate("HESEB_ScanTool", "Intervals", nullptr));
        qelabel->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:CurrentSample", nullptr)));
        label_4->setText(QCoreApplication::translate("HESEB_ScanTool", "Sample X", nullptr));
        label_2->setText(QCoreApplication::translate("HESEB_ScanTool", "Scans", nullptr));
        label_8->setText(QCoreApplication::translate("HESEB_ScanTool", "Sample", nullptr));
        label_10->setText(QCoreApplication::translate("HESEB_ScanTool", "out of", nullptr));
        qelabel_4->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:Nsamples", nullptr)));
        qelabel_3->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:CurrentInterval", nullptr)));
        qelabel_2->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:CurrentScan", nullptr)));
        label_5->setText(QCoreApplication::translate("HESEB_ScanTool", "Sample Y", nullptr));
        qelabel_8->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "motorSimIOC:FE-M1-STP-TRSY1", nullptr)));
        qelabel_5->setProperty("variable", QVariant(QCoreApplication::translate("HESEB_ScanTool", "SCAN:NIntervals", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class HESEB_ScanTool: public Ui_HESEB_ScanTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HESEB_SCANTOOL_H
