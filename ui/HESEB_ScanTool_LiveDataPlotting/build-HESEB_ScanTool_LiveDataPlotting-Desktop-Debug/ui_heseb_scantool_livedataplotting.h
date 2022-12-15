/********************************************************************************
** Form generated from reading UI file 'heseb_scantool_livedataplotting.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HESEB_SCANTOOL_LIVEDATAPLOTTING_H
#define UI_HESEB_SCANTOOL_LIVEDATAPLOTTING_H

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

QT_BEGIN_NAMESPACE

class Ui_HESEB_ScanTool_LiveDataPlotting
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *lblTitle_2;
    QGridLayout *gridLayout_2;
    QPushButton *I0_It;
    QSpacerItem *horizontalSpacer;
    QPushButton *It;
    QPushButton *I0;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_3;
    QLabel *I0_sts;
    QLabel *both_sts;
    QLabel *It_sts;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *help;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *HESEB_ScanTool_LiveDataPlotting)
    {
        if (HESEB_ScanTool_LiveDataPlotting->objectName().isEmpty())
            HESEB_ScanTool_LiveDataPlotting->setObjectName(QStringLiteral("HESEB_ScanTool_LiveDataPlotting"));
        HESEB_ScanTool_LiveDataPlotting->resize(515, 243);
        centralwidget = new QWidget(HESEB_ScanTool_LiveDataPlotting);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblTitle_2 = new QLabel(centralwidget);
        lblTitle_2->setObjectName(QStringLiteral("lblTitle_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblTitle_2->sizePolicy().hasHeightForWidth());
        lblTitle_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        lblTitle_2->setFont(font);
        lblTitle_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-radius: 5px;\n"
"margin-top: 0.5em;\n"
"subcontrol-origin: margin;\n"
"left: 10px;\n"
"padding: 0 3px 0 3px;"));
        lblTitle_2->setAlignment(Qt::AlignCenter);
        lblTitle_2->setMargin(10);
        lblTitle_2->setIndent(0);

        gridLayout->addWidget(lblTitle_2, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        I0_It = new QPushButton(centralwidget);
        I0_It->setObjectName(QStringLiteral("I0_It"));
        I0_It->setStyleSheet(QLatin1String("border-color: rgb(239, 239, 239);\n"
"background-color: rgb(239, 239, 239);"));
        I0_It->setFlat(true);

        gridLayout_2->addWidget(I0_It, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 3, 1);

        It = new QPushButton(centralwidget);
        It->setObjectName(QStringLiteral("It"));

        gridLayout_2->addWidget(It, 1, 1, 1, 1);

        I0 = new QPushButton(centralwidget);
        I0->setObjectName(QStringLiteral("I0"));

        gridLayout_2->addWidget(I0, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 3, 1);


        gridLayout_5->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        I0_sts = new QLabel(centralwidget);
        I0_sts->setObjectName(QStringLiteral("I0_sts"));
        I0_sts->setFrameShape(QFrame::StyledPanel);
        I0_sts->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(I0_sts, 0, 0, 1, 1);

        both_sts = new QLabel(centralwidget);
        both_sts->setObjectName(QStringLiteral("both_sts"));
        both_sts->setFrameShape(QFrame::NoFrame);
        both_sts->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(both_sts, 2, 0, 1, 1);

        It_sts = new QLabel(centralwidget);
        It_sts->setObjectName(QStringLiteral("It_sts"));
        It_sts->setFrameShape(QFrame::StyledPanel);
        It_sts->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(It_sts, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 1, 3, 1);


        gridLayout_5->addLayout(gridLayout_3, 1, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(400, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        help = new QPushButton(centralwidget);
        help->setObjectName(QStringLiteral("help"));

        gridLayout_4->addWidget(help, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 2, 0, 1, 2);

        HESEB_ScanTool_LiveDataPlotting->setCentralWidget(centralwidget);

        retranslateUi(HESEB_ScanTool_LiveDataPlotting);

        QMetaObject::connectSlotsByName(HESEB_ScanTool_LiveDataPlotting);
    } // setupUi

    void retranslateUi(QMainWindow *HESEB_ScanTool_LiveDataPlotting)
    {
        HESEB_ScanTool_LiveDataPlotting->setWindowTitle(QApplication::translate("HESEB_ScanTool_LiveDataPlotting", "HESEB_ScanTool_LiveDataPlotting", Q_NULLPTR));
        lblTitle_2->setText(QApplication::translate("HESEB_ScanTool_LiveDataPlotting", "<html><head/><body><p>DCA | HESEB | SCAN TOOL | LIVE DATA PLOTTING</p></body></html>", Q_NULLPTR));
        I0_It->setText(QString());
        It->setText(QApplication::translate("HESEB_ScanTool_LiveDataPlotting", "Itrans", Q_NULLPTR));
        I0->setText(QApplication::translate("HESEB_ScanTool_LiveDataPlotting", "I0", Q_NULLPTR));
        I0_sts->setText(QString());
        both_sts->setText(QString());
        It_sts->setText(QString());
        help->setText(QApplication::translate("HESEB_ScanTool_LiveDataPlotting", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HESEB_ScanTool_LiveDataPlotting: public Ui_HESEB_ScanTool_LiveDataPlotting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HESEB_SCANTOOL_LIVEDATAPLOTTING_H
