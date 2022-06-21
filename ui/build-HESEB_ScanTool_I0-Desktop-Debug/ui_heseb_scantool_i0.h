/********************************************************************************
** Form generated from reading UI file 'heseb_scantool_i0.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HESEB_SCANTOOL_I0_H
#define UI_HESEB_SCANTOOL_I0_H

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

class Ui_HESEB_ScanTool_I0
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_19;
    QGridLayout *gridLayout_13;
    QLabel *lblTitle_4;
    QGridLayout *gridLayout_14;
    QELabel *qelabel_21;
    QLabel *label_30;
    QELabel *qelabel_22;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QELabel *qelabel_23;
    QELabel *qelabel_24;
    QLabel *label_34;
    QELabel *qelabel_25;
    QELabel *qelabel_26;
    QELabel *qelabel_27;
    QELabel *qelabel_28;
    QLabel *label_35;
    QLabel *label_36;
    QELabel *qelabel_29;
    QLabel *label_37;
    QLabel *label_38;
    QGridLayout *gridLayout_15;
    QELabel *qelabel_30;
    QLabel *label_39;
    QGridLayout *gridLayout_16;
    QEPushButton *qepushbutton_7;
    QPushButton *pushButton_3;
    QEPushButton *qepushbutton_8;
    QEPushButton *qepushbutton_9;
    QGridLayout *gridLayout_17;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_41;
    QSimpleShape *qsimpleshape_4;
    QSimpleShape *qsimpleshape_10;
    QGridLayout *gridLayout_18;
    QLabel *label_42;
    QEPlotter *qeplotter_3;
    QLabel *label_43;

    void setupUi(QMainWindow *HESEB_ScanTool_I0)
    {
        if (HESEB_ScanTool_I0->objectName().isEmpty())
            HESEB_ScanTool_I0->setObjectName(QStringLiteral("HESEB_ScanTool_I0"));
        HESEB_ScanTool_I0->resize(1261, 686);
        centralwidget = new QWidget(HESEB_ScanTool_I0);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_19 = new QGridLayout(centralwidget);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setSizeConstraint(QLayout::SetMinimumSize);
        lblTitle_4 = new QLabel(centralwidget);
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

        gridLayout_13->addWidget(lblTitle_4, 0, 0, 1, 1);


        gridLayout_19->addLayout(gridLayout_13, 0, 0, 1, 3);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setSpacing(0);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        qelabel_21 = new QELabel(centralwidget);
        qelabel_21->setObjectName(QStringLiteral("qelabel_21"));
        qelabel_21->setFrameShape(QFrame::StyledPanel);

        gridLayout_14->addWidget(qelabel_21, 0, 3, 1, 1);

        label_30 = new QLabel(centralwidget);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_30, 2, 4, 1, 1);

        qelabel_22 = new QELabel(centralwidget);
        qelabel_22->setObjectName(QStringLiteral("qelabel_22"));
        qelabel_22->setFrameShape(QFrame::StyledPanel);

        gridLayout_14->addWidget(qelabel_22, 0, 1, 1, 1);

        label_31 = new QLabel(centralwidget);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_31, 1, 4, 1, 1);

        label_32 = new QLabel(centralwidget);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_14->addWidget(label_32, 1, 0, 1, 1);

        label_33 = new QLabel(centralwidget);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_33, 0, 4, 1, 1);

        qelabel_23 = new QELabel(centralwidget);
        qelabel_23->setObjectName(QStringLiteral("qelabel_23"));
        qelabel_23->setFrameShape(QFrame::StyledPanel);

        gridLayout_14->addWidget(qelabel_23, 2, 1, 1, 1);

        qelabel_24 = new QELabel(centralwidget);
        qelabel_24->setObjectName(QStringLiteral("qelabel_24"));
        qelabel_24->setFrameShape(QFrame::StyledPanel);

        gridLayout_14->addWidget(qelabel_24, 1, 1, 1, 1);

        label_34 = new QLabel(centralwidget);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_34, 1, 2, 1, 1);

        qelabel_25 = new QELabel(centralwidget);
        qelabel_25->setObjectName(QStringLiteral("qelabel_25"));
        qelabel_25->setFrameShape(QFrame::StyledPanel);

        gridLayout_14->addWidget(qelabel_25, 0, 5, 1, 1);

        qelabel_26 = new QELabel(centralwidget);
        qelabel_26->setObjectName(QStringLiteral("qelabel_26"));
        qelabel_26->setFrameShape(QFrame::StyledPanel);

        gridLayout_14->addWidget(qelabel_26, 2, 3, 1, 1);

        qelabel_27 = new QELabel(centralwidget);
        qelabel_27->setObjectName(QStringLiteral("qelabel_27"));
        qelabel_27->setFrameShape(QFrame::StyledPanel);

        gridLayout_14->addWidget(qelabel_27, 1, 5, 1, 1);

        qelabel_28 = new QELabel(centralwidget);
        qelabel_28->setObjectName(QStringLiteral("qelabel_28"));
        qelabel_28->setFrameShape(QFrame::StyledPanel);

        gridLayout_14->addWidget(qelabel_28, 1, 3, 1, 1);

        label_35 = new QLabel(centralwidget);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_35, 0, 2, 1, 1);

        label_36 = new QLabel(centralwidget);
        label_36->setObjectName(QStringLiteral("label_36"));

        gridLayout_14->addWidget(label_36, 2, 0, 1, 1);

        qelabel_29 = new QELabel(centralwidget);
        qelabel_29->setObjectName(QStringLiteral("qelabel_29"));
        qelabel_29->setFrameShape(QFrame::StyledPanel);

        gridLayout_14->addWidget(qelabel_29, 2, 5, 1, 1);

        label_37 = new QLabel(centralwidget);
        label_37->setObjectName(QStringLiteral("label_37"));

        gridLayout_14->addWidget(label_37, 0, 0, 1, 1);

        label_38 = new QLabel(centralwidget);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(label_38, 2, 2, 1, 1);


        gridLayout_19->addLayout(gridLayout_14, 1, 0, 2, 1);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        qelabel_30 = new QELabel(centralwidget);
        qelabel_30->setObjectName(QStringLiteral("qelabel_30"));

        gridLayout_15->addWidget(qelabel_30, 2, 0, 1, 1);

        label_39 = new QLabel(centralwidget);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_15->addWidget(label_39, 0, 0, 1, 1);


        gridLayout_19->addLayout(gridLayout_15, 1, 1, 2, 1);

        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        qepushbutton_7 = new QEPushButton(centralwidget);
        qepushbutton_7->setObjectName(QStringLiteral("qepushbutton_7"));
        qepushbutton_7->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_16->addWidget(qepushbutton_7, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_16->addWidget(pushButton_3, 0, 0, 1, 1);

        qepushbutton_8 = new QEPushButton(centralwidget);
        qepushbutton_8->setObjectName(QStringLiteral("qepushbutton_8"));
        qepushbutton_8->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_16->addWidget(qepushbutton_8, 0, 2, 1, 1);

        qepushbutton_9 = new QEPushButton(centralwidget);
        qepushbutton_9->setObjectName(QStringLiteral("qepushbutton_9"));
        QPalette palette;
        QBrush brush(QColor(239, 41, 41, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        qepushbutton_9->setPalette(palette);
        QFont font1;
        font1.setUnderline(false);
        font1.setKerning(false);
        qepushbutton_9->setFont(font1);
        qepushbutton_9->setCursor(QCursor(Qt::PointingHandCursor));
        qepushbutton_9->setAutoFillBackground(true);

        gridLayout_16->addWidget(qepushbutton_9, 0, 3, 1, 1);


        gridLayout_19->addLayout(gridLayout_16, 1, 2, 1, 1);

        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        horizontalSpacer_3 = new QSpacerItem(360, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_17->addItem(horizontalSpacer_3, 0, 0, 2, 1);

        label_41 = new QLabel(centralwidget);
        label_41->setObjectName(QStringLiteral("label_41"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_41->sizePolicy().hasHeightForWidth());
        label_41->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(15);
        label_41->setFont(font2);
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(label_41, 0, 2, 1, 1);

        qsimpleshape_4 = new QSimpleShape(centralwidget);
        qsimpleshape_4->setObjectName(QStringLiteral("qsimpleshape_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(qsimpleshape_4->sizePolicy().hasHeightForWidth());
        qsimpleshape_4->setSizePolicy(sizePolicy2);
        qsimpleshape_4->setShape(QSimpleShape::roundRectangle);
        qsimpleshape_4->setProperty("colour0", QVariant(QColor(23, 69, 243)));

        gridLayout_17->addWidget(qsimpleshape_4, 0, 1, 1, 1);

        qsimpleshape_10 = new QSimpleShape(centralwidget);
        qsimpleshape_10->setObjectName(QStringLiteral("qsimpleshape_10"));
        sizePolicy2.setHeightForWidth(qsimpleshape_10->sizePolicy().hasHeightForWidth());
        qsimpleshape_10->setSizePolicy(sizePolicy2);
        qsimpleshape_10->setShape(QSimpleShape::roundRectangle);
        qsimpleshape_10->setProperty("colour0", QVariant(QColor(255, 0, 0)));

        gridLayout_17->addWidget(qsimpleshape_10, 1, 1, 1, 1);


        gridLayout_19->addLayout(gridLayout_17, 2, 2, 1, 1);

        gridLayout_18 = new QGridLayout();
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        label_42 = new QLabel(centralwidget);
        label_42->setObjectName(QStringLiteral("label_42"));
        QFont font3;
        font3.setFamily(QStringLiteral("Monospace"));
        font3.setPointSize(14);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        font3.setKerning(true);
        font3.setStyleStrategy(QFont::PreferDefault);
        label_42->setFont(font3);
        label_42->setLayoutDirection(Qt::LeftToRight);
        label_42->setStyleSheet(QLatin1String(".label_14{\n"
"transform: rotate(-90deg);\n"
"}"));
        label_42->setAlignment(Qt::AlignCenter);
        label_42->setWordWrap(false);

        gridLayout_18->addWidget(label_42, 0, 0, 1, 1);

        qeplotter_3 = new QEPlotter(centralwidget);
        qeplotter_3->setObjectName(QStringLiteral("qeplotter_3"));
        qeplotter_3->setCursor(QCursor(Qt::CrossCursor));
        qeplotter_3->setProperty("toolBarIsVisible", QVariant(false));
        qeplotter_3->setProperty("pvItemsIsVisible", QVariant(false));
        qeplotter_3->setProperty("statusIsVisible", QVariant(false));
        qeplotter_3->setColourA(QColor(23, 69, 243));
        qeplotter_3->setColourB(QColor(255, 0, 0));

        gridLayout_18->addWidget(qeplotter_3, 0, 1, 1, 1);

        label_43 = new QLabel(centralwidget);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setFont(font3);
        label_43->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_43, 1, 1, 1, 1);


        gridLayout_19->addLayout(gridLayout_18, 3, 0, 1, 3);

        HESEB_ScanTool_I0->setCentralWidget(centralwidget);

        retranslateUi(HESEB_ScanTool_I0);

        QMetaObject::connectSlotsByName(HESEB_ScanTool_I0);
    } // setupUi

    void retranslateUi(QMainWindow *HESEB_ScanTool_I0)
    {
        HESEB_ScanTool_I0->setWindowTitle(QApplication::translate("HESEB_ScanTool_I0", "HESEB_ScanTool_I0", Q_NULLPTR));
        lblTitle_4->setText(QApplication::translate("HESEB_ScanTool_I0", "<html><head/><body><p>DCA | HESEB | SCAN TOOL | I<span style=\" vertical-align:sub;\">0(A) vs. </span>Energy<span style=\" vertical-align:sub;\">(eV)</span></p></body></html>", Q_NULLPTR));
        qelabel_21->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "SCAN:Nsamples", Q_NULLPTR)));
        label_30->setText(QApplication::translate("HESEB_ScanTool_I0", "Energy (eV)", Q_NULLPTR));
        qelabel_22->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "SCAN:CurrentSample", Q_NULLPTR)));
        label_31->setText(QApplication::translate("HESEB_ScanTool_I0", "Sample Y", Q_NULLPTR));
        label_32->setText(QApplication::translate("HESEB_ScanTool_I0", "Scans", Q_NULLPTR));
        label_33->setText(QApplication::translate("HESEB_ScanTool_I0", "Sample X", Q_NULLPTR));
        qelabel_23->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "SCAN:CurrentInterval", Q_NULLPTR)));
        qelabel_24->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "SCAN:CurrentScan", Q_NULLPTR)));
        label_34->setText(QApplication::translate("HESEB_ScanTool_I0", "out of", Q_NULLPTR));
        qelabel_25->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "motorSimIOC:FE-M1-STP-TRSX1", Q_NULLPTR)));
        qelabel_26->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "SCAN:NIntervals", Q_NULLPTR)));
        qelabel_27->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "motorSimIOC:FE-M1-STP-TRSY1", Q_NULLPTR)));
        qelabel_28->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "SCAN:Nscans", Q_NULLPTR)));
        label_35->setText(QApplication::translate("HESEB_ScanTool_I0", "out of", Q_NULLPTR));
        label_36->setText(QApplication::translate("HESEB_ScanTool_I0", "Intervals", Q_NULLPTR));
        qelabel_29->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "I11OH-PGM:getEnergy", Q_NULLPTR)));
        label_37->setText(QApplication::translate("HESEB_ScanTool_I0", "Sample", Q_NULLPTR));
        label_38->setText(QApplication::translate("HESEB_ScanTool_I0", "out of", Q_NULLPTR));
        qelabel_30->setProperty("variable", QVariant(QString()));
        label_39->setText(QApplication::translate("HESEB_ScanTool_I0", "Scan tool status ", Q_NULLPTR));
        qepushbutton_7->setText(QApplication::translate("HESEB_ScanTool_I0", "Pause", Q_NULLPTR));
        qepushbutton_7->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "SCAN:XAFSPause", Q_NULLPTR)));
        pushButton_3->setText(QApplication::translate("HESEB_ScanTool_I0", "...", Q_NULLPTR));
        qepushbutton_8->setText(QApplication::translate("HESEB_ScanTool_I0", "Resume", Q_NULLPTR));
        qepushbutton_8->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "SCAN:XAFSPause", Q_NULLPTR)));
        qepushbutton_8->setClickText(QApplication::translate("HESEB_ScanTool_I0", "0", Q_NULLPTR));
        qepushbutton_9->setText(QApplication::translate("HESEB_ScanTool_I0", "Stop!!", Q_NULLPTR));
        qepushbutton_9->setProperty("variable", QVariant(QApplication::translate("HESEB_ScanTool_I0", "SCAN:XAFSPause", Q_NULLPTR)));
        qepushbutton_9->setClickText(QApplication::translate("HESEB_ScanTool_I0", "0", Q_NULLPTR));
        label_41->setText(QApplication::translate("HESEB_ScanTool_I0", "<html><head/><body><p>I<span style=\" vertical-align:sub;\">0</span></p></body></html>", Q_NULLPTR));
        label_42->setText(QApplication::translate("HESEB_ScanTool_I0", "Current (A)", Q_NULLPTR));
        qeplotter_3->setProperty("DataVariableX", QVariant(QApplication::translate("HESEB_ScanTool_I0", "PLOT:Energy", Q_NULLPTR)));
        qeplotter_3->setProperty("DataVariableA", QVariant(QApplication::translate("HESEB_ScanTool_I0", "PLOT:I0", Q_NULLPTR)));
        qeplotter_3->setProperty("DataVariableB", QVariant(QString()));
        qeplotter_3->setProperty("DataVariableC", QVariant(QString()));
        qeplotter_3->setProperty("SizeVariableX", QVariant(QApplication::translate("HESEB_ScanTool_I0", "PLOT:Energy.NORD", Q_NULLPTR)));
        qeplotter_3->setProperty("SizeVariableA", QVariant(QApplication::translate("HESEB_ScanTool_I0", "PLOT:I0.NORD", Q_NULLPTR)));
        qeplotter_3->setProperty("SizeVariableB", QVariant(QString()));
        qeplotter_3->setProperty("SizeVariableC", QVariant(QString()));
        qeplotter_3->setProperty("AliasNameX", QVariant(QString()));
        qeplotter_3->setProperty("AliasNameA", QVariant(QString()));
        qeplotter_3->setProperty("aliasNames", QVariant(QStringList()
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
        label_43->setText(QApplication::translate("HESEB_ScanTool_I0", "Energy (eV)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HESEB_ScanTool_I0: public Ui_HESEB_ScanTool_I0 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HESEB_SCANTOOL_I0_H
