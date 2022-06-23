/********************************************************************************
** Form generated from reading UI file 'heseb_scantool_pico.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HESEB_SCANTOOL_PICO_H
#define UI_HESEB_SCANTOOL_PICO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "QEFrame.h"
#include "QEPlotter.h"

QT_BEGIN_NAMESPACE

class Ui_HESEB_ScanTool_PICO
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_6;
    QLabel *lblTitle_2;
    QGridLayout *gridLayout_4;
    QLabel *label_13;
    QEPlotter *qeplotter;
    QLabel *label_14;
    QGridLayout *gridLayout;
    QPushButton *Stop;
    QLineEdit *Int_time;
    QLabel *label;
    QPushButton *Start;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *HESEB_ScanTool_PICO)
    {
        if (HESEB_ScanTool_PICO->objectName().isEmpty())
            HESEB_ScanTool_PICO->setObjectName(QStringLiteral("HESEB_ScanTool_PICO"));
        HESEB_ScanTool_PICO->resize(1275, 765);
        centralwidget = new QWidget(HESEB_ScanTool_PICO);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setSizeConstraint(QLayout::SetMinimumSize);
        lblTitle_2 = new QLabel(centralwidget);
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

        gridLayout_6->addWidget(lblTitle_2, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_6, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        QFont font1;
        font1.setFamily(QStringLiteral("Monospace"));
        font1.setPointSize(14);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_13, 1, 1, 1, 1);

        qeplotter = new QEPlotter(centralwidget);
        qeplotter->setObjectName(QStringLiteral("qeplotter"));
        qeplotter->setCursor(QCursor(Qt::CrossCursor));
        qeplotter->setProperty("toolBarIsVisible", QVariant(false));
        qeplotter->setProperty("pvItemsIsVisible", QVariant(false));
        qeplotter->setProperty("statusIsVisible", QVariant(false));
        qeplotter->setColourA(QColor(23, 69, 243));
        qeplotter->setColourB(QColor(255, 0, 0));

        gridLayout_4->addWidget(qeplotter, 0, 1, 1, 1);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);
        label_14->setLayoutDirection(Qt::LeftToRight);
        label_14->setStyleSheet(QLatin1String(".label_14{\n"
"transform: rotate(-90deg);\n"
"}"));
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setWordWrap(false);

        gridLayout_4->addWidget(label_14, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Stop = new QPushButton(centralwidget);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(Stop, 0, 4, 1, 1);

        Int_time = new QLineEdit(centralwidget);
        Int_time->setObjectName(QStringLiteral("Int_time"));
        QFont font2;
        font2.setPointSize(9);
        Int_time->setFont(font2);
        Int_time->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        Int_time->setCursorMoveStyle(Qt::LogicalMoveStyle);
        Int_time->setClearButtonEnabled(false);

        gridLayout->addWidget(Int_time, 0, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        Start = new QPushButton(centralwidget);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(Start, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        HESEB_ScanTool_PICO->setCentralWidget(centralwidget);

        retranslateUi(HESEB_ScanTool_PICO);

        QMetaObject::connectSlotsByName(HESEB_ScanTool_PICO);
    } // setupUi

    void retranslateUi(QMainWindow *HESEB_ScanTool_PICO)
    {
        HESEB_ScanTool_PICO->setWindowTitle(QApplication::translate("HESEB_ScanTool_PICO", "HESEB_ScanTool_PICO", Q_NULLPTR));
        lblTitle_2->setText(QApplication::translate("HESEB_ScanTool_PICO", "<html><head/><body><p>DCA | HESEB | SCAN TOOL | I<span style=\" vertical-align:sub;\">0(A)_ </span>Time<span style=\" vertical-align:sub;\">(s)</span></p></body></html>", Q_NULLPTR));
        label_13->setText(QApplication::translate("HESEB_ScanTool_PICO", "<html><head/><body><p>Time(s)</p></body></html>", Q_NULLPTR));
        qeplotter->setProperty("DataVariableX", QVariant(QApplication::translate("HESEB_ScanTool_PICO", "PLOT:Energy", Q_NULLPTR)));
        qeplotter->setProperty("DataVariableA", QVariant(QApplication::translate("HESEB_ScanTool_PICO", "PLOT:I0", Q_NULLPTR)));
        qeplotter->setProperty("DataVariableB", QVariant(QApplication::translate("HESEB_ScanTool_PICO", "PLOT:It", Q_NULLPTR)));
        qeplotter->setProperty("DataVariableC", QVariant(QString()));
        qeplotter->setProperty("SizeVariableX", QVariant(QApplication::translate("HESEB_ScanTool_PICO", "PLOT:Energy.NORD", Q_NULLPTR)));
        qeplotter->setProperty("SizeVariableA", QVariant(QApplication::translate("HESEB_ScanTool_PICO", "PLOT:I0.NORD", Q_NULLPTR)));
        qeplotter->setProperty("SizeVariableB", QVariant(QApplication::translate("HESEB_ScanTool_PICO", "PLOT:It.NORD", Q_NULLPTR)));
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
        label_14->setText(QApplication::translate("HESEB_ScanTool_PICO", "Current (A)", Q_NULLPTR));
        Stop->setText(QApplication::translate("HESEB_ScanTool_PICO", "Stop", Q_NULLPTR));
        Int_time->setPlaceholderText(QApplication::translate("HESEB_ScanTool_PICO", "Enter Integration Time ... * The allowable values are: {0.25, 0.5, 0.75, 1, 1.25, 1.5, 1.75, 2, 2.25, 2.5, 2.75, 3, 3.25, 3.5, 3.75, 4, 5, 6, 7, 8, 9}", Q_NULLPTR));
        label->setText(QApplication::translate("HESEB_ScanTool_PICO", "Integration Time", Q_NULLPTR));
        Start->setText(QApplication::translate("HESEB_ScanTool_PICO", "Start ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HESEB_ScanTool_PICO: public Ui_HESEB_ScanTool_PICO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HESEB_SCANTOOL_PICO_H
