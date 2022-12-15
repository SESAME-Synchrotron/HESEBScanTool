/********************************************************************************
** Form generated from reading UI file 'heseb_other_pvs_readout.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HESEB_OTHER_PVS_READOUT_H
#define UI_HESEB_OTHER_PVS_READOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "QELineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *lblTitle_4;
    QLabel *label_9;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QELineEdit *qelineedit_15;
    QELineEdit *qelineedit_12;
    QLabel *label_30;
    QLabel *label_23;
    QELineEdit *qelineedit_11;
    QLabel *label_33;
    QLabel *label_26;
    QELineEdit *qelineedit_14;
    QLabel *label_24;
    QLabel *label_22;
    QLabel *label_21;
    QELineEdit *qelineedit_10;
    QLabel *label_32;
    QLabel *label_25;
    QELineEdit *qelineedit_13;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_27;
    QLabel *label_34;
    QLabel *label_35;
    QELineEdit *qelineedit_16;
    QLabel *label_31;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_4;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_39;
    QELineEdit *qelineedit_18;
    QELineEdit *qelineedit_17;
    QELineEdit *qelineedit_19;
    QLabel *label_46;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_6;
    QLabel *label_58;
    QELineEdit *qelineedit_28;
    QLabel *label_59;
    QLabel *label_64;
    QLabel *label_88;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_8;
    QLabel *label_80;
    QELineEdit *qelineedit_45;
    QELineEdit *qelineedit_27;
    QELineEdit *qelineedit_40;
    QLabel *label_62;
    QELineEdit *qelineedit_37;
    QELineEdit *qelineedit_43;
    QELineEdit *qelineedit_34;
    QLabel *label_77;
    QLabel *label_83;
    QELineEdit *qelineedit_47;
    QELineEdit *qelineedit_35;
    QLabel *label_81;
    QELineEdit *qelineedit_42;
    QLabel *label_68;
    QELineEdit *qelineedit_39;
    QLabel *label_73;
    QELineEdit *qelineedit_46;
    QLabel *label_86;
    QLabel *label_85;
    QELineEdit *qelineedit_38;
    QLabel *label_84;
    QLabel *label_79;
    QLabel *label_78;
    QELineEdit *qelineedit_36;
    QLabel *label_74;
    QLabel *label_87;
    QELineEdit *qelineedit_41;
    QELineEdit *qelineedit_49;
    QLabel *label_76;
    QELineEdit *qelineedit_48;
    QLabel *label_82;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_6;
    QELineEdit *qelineedit;
    QLabel *label_3;
    QLabel *label_5;
    QELineEdit *qelineedit_2;
    QLabel *label_2;
    QLabel *label_7;
    QELineEdit *qelineedit_3;
    QLabel *label_4;
    QLabel *label_8;
    QELineEdit *qelineedit_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(530, 510);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(450, 450, 61, 51));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);
        lblTitle_4 = new QLabel(Dialog);
        lblTitle_4->setObjectName(QStringLiteral("lblTitle_4"));
        lblTitle_4->setGeometry(QRect(10, 0, 511, 62));
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
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 350, 151, 20));
        QFont font1;
        font1.setPointSize(12);
        label_9->setFont(font1);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 110, 171, 199));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        qelineedit_15 = new QELineEdit(layoutWidget);
        qelineedit_15->setObjectName(QStringLiteral("qelineedit_15"));
        qelineedit_15->setEnabled(true);
        qelineedit_15->setAutoFillBackground(false);

        gridLayout_3->addWidget(qelineedit_15, 5, 2, 1, 1);

        qelineedit_12 = new QELineEdit(layoutWidget);
        qelineedit_12->setObjectName(QStringLiteral("qelineedit_12"));
        qelineedit_12->setEnabled(true);
        qelineedit_12->setAutoFillBackground(false);

        gridLayout_3->addWidget(qelineedit_12, 2, 2, 1, 1);

        label_30 = new QLabel(layoutWidget);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_3->addWidget(label_30, 4, 1, 1, 1);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_3->addWidget(label_23, 1, 0, 1, 1);

        qelineedit_11 = new QELineEdit(layoutWidget);
        qelineedit_11->setObjectName(QStringLiteral("qelineedit_11"));
        qelineedit_11->setEnabled(true);
        qelineedit_11->setAutoFillBackground(false);

        gridLayout_3->addWidget(qelineedit_11, 1, 2, 1, 1);

        label_33 = new QLabel(layoutWidget);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_3->addWidget(label_33, 5, 1, 1, 1);

        label_26 = new QLabel(layoutWidget);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_3->addWidget(label_26, 2, 1, 1, 1);

        qelineedit_14 = new QELineEdit(layoutWidget);
        qelineedit_14->setObjectName(QStringLiteral("qelineedit_14"));
        qelineedit_14->setEnabled(true);
        qelineedit_14->setAutoFillBackground(false);

        gridLayout_3->addWidget(qelineedit_14, 4, 2, 1, 1);

        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_3->addWidget(label_24, 1, 1, 1, 1);

        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_3->addWidget(label_22, 0, 1, 1, 1);

        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_3->addWidget(label_21, 0, 0, 1, 1);

        qelineedit_10 = new QELineEdit(layoutWidget);
        qelineedit_10->setObjectName(QStringLiteral("qelineedit_10"));
        qelineedit_10->setEnabled(true);
        qelineedit_10->setAutoFillBackground(false);

        gridLayout_3->addWidget(qelineedit_10, 0, 2, 1, 1);

        label_32 = new QLabel(layoutWidget);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_3->addWidget(label_32, 5, 0, 1, 1);

        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_3->addWidget(label_25, 2, 0, 1, 1);

        qelineedit_13 = new QELineEdit(layoutWidget);
        qelineedit_13->setObjectName(QStringLiteral("qelineedit_13"));
        qelineedit_13->setEnabled(true);
        qelineedit_13->setAutoFillBackground(false);

        gridLayout_3->addWidget(qelineedit_13, 3, 2, 1, 1);

        label_28 = new QLabel(layoutWidget);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_3->addWidget(label_28, 3, 1, 1, 1);

        label_29 = new QLabel(layoutWidget);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_3->addWidget(label_29, 4, 0, 1, 1);

        label_27 = new QLabel(layoutWidget);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_3->addWidget(label_27, 3, 0, 1, 1);

        label_34 = new QLabel(layoutWidget);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_3->addWidget(label_34, 6, 0, 1, 1);

        label_35 = new QLabel(layoutWidget);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout_3->addWidget(label_35, 6, 1, 1, 1);

        qelineedit_16 = new QELineEdit(layoutWidget);
        qelineedit_16->setObjectName(QStringLiteral("qelineedit_16"));
        qelineedit_16->setEnabled(true);
        qelineedit_16->setAutoFillBackground(false);

        gridLayout_3->addWidget(qelineedit_16, 6, 2, 1, 1);

        label_31 = new QLabel(Dialog);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(9, 79, 151, 20));
        label_31->setFont(font1);
        layoutWidget_2 = new QWidget(Dialog);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(190, 370, 161, 83));
        gridLayout_4 = new QGridLayout(layoutWidget_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_36 = new QLabel(layoutWidget_2);
        label_36->setObjectName(QStringLiteral("label_36"));

        gridLayout_4->addWidget(label_36, 0, 0, 1, 1);

        label_37 = new QLabel(layoutWidget_2);
        label_37->setObjectName(QStringLiteral("label_37"));

        gridLayout_4->addWidget(label_37, 0, 1, 1, 1);

        label_38 = new QLabel(layoutWidget_2);
        label_38->setObjectName(QStringLiteral("label_38"));

        gridLayout_4->addWidget(label_38, 1, 0, 1, 1);

        label_40 = new QLabel(layoutWidget_2);
        label_40->setObjectName(QStringLiteral("label_40"));

        gridLayout_4->addWidget(label_40, 2, 0, 1, 1);

        label_41 = new QLabel(layoutWidget_2);
        label_41->setObjectName(QStringLiteral("label_41"));

        gridLayout_4->addWidget(label_41, 2, 1, 1, 1);

        label_39 = new QLabel(layoutWidget_2);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_4->addWidget(label_39, 1, 1, 1, 1);

        qelineedit_18 = new QELineEdit(layoutWidget_2);
        qelineedit_18->setObjectName(QStringLiteral("qelineedit_18"));
        qelineedit_18->setEnabled(true);
        qelineedit_18->setAutoFillBackground(false);

        gridLayout_4->addWidget(qelineedit_18, 1, 2, 1, 1);

        qelineedit_17 = new QELineEdit(layoutWidget_2);
        qelineedit_17->setObjectName(QStringLiteral("qelineedit_17"));
        qelineedit_17->setEnabled(true);
        qelineedit_17->setAutoFillBackground(false);

        gridLayout_4->addWidget(qelineedit_17, 0, 2, 1, 1);

        qelineedit_19 = new QELineEdit(layoutWidget_2);
        qelineedit_19->setObjectName(QStringLiteral("qelineedit_19"));
        qelineedit_19->setEnabled(false);
        qelineedit_19->setAutoFillBackground(false);

        gridLayout_4->addWidget(qelineedit_19, 2, 2, 1, 1);

        label_46 = new QLabel(Dialog);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(190, 350, 151, 20));
        label_46->setFont(font1);
        layoutWidget_4 = new QWidget(Dialog);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(360, 370, 151, 31));
        gridLayout_6 = new QGridLayout(layoutWidget_4);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_58 = new QLabel(layoutWidget_4);
        label_58->setObjectName(QStringLiteral("label_58"));

        gridLayout_6->addWidget(label_58, 0, 0, 1, 1);

        qelineedit_28 = new QELineEdit(layoutWidget_4);
        qelineedit_28->setObjectName(QStringLiteral("qelineedit_28"));
        qelineedit_28->setEnabled(true);
        qelineedit_28->setAutoFillBackground(false);

        gridLayout_6->addWidget(qelineedit_28, 0, 2, 1, 1);

        label_59 = new QLabel(layoutWidget_4);
        label_59->setObjectName(QStringLiteral("label_59"));

        gridLayout_6->addWidget(label_59, 0, 1, 1, 1);

        label_64 = new QLabel(Dialog);
        label_64->setObjectName(QStringLiteral("label_64"));
        label_64->setGeometry(QRect(360, 349, 151, 20));
        label_64->setFont(font1);
        label_88 = new QLabel(Dialog);
        label_88->setObjectName(QStringLiteral("label_88"));
        label_88->setGeometry(QRect(190, 90, 151, 20));
        label_88->setFont(font1);
        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(190, 110, 321, 201));
        gridLayout_8 = new QGridLayout(layoutWidget1);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        label_80 = new QLabel(layoutWidget1);
        label_80->setObjectName(QStringLiteral("label_80"));

        gridLayout_8->addWidget(label_80, 5, 0, 1, 1);

        qelineedit_45 = new QELineEdit(layoutWidget1);
        qelineedit_45->setObjectName(QStringLiteral("qelineedit_45"));
        qelineedit_45->setEnabled(true);
        qelineedit_45->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_45, 1, 4, 1, 1);

        qelineedit_27 = new QELineEdit(layoutWidget1);
        qelineedit_27->setObjectName(QStringLiteral("qelineedit_27"));
        qelineedit_27->setEnabled(true);
        qelineedit_27->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_27, 1, 2, 1, 1);

        qelineedit_40 = new QELineEdit(layoutWidget1);
        qelineedit_40->setObjectName(QStringLiteral("qelineedit_40"));
        qelineedit_40->setEnabled(true);
        qelineedit_40->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_40, 4, 3, 1, 1);

        label_62 = new QLabel(layoutWidget1);
        label_62->setObjectName(QStringLiteral("label_62"));

        gridLayout_8->addWidget(label_62, 1, 0, 1, 1);

        qelineedit_37 = new QELineEdit(layoutWidget1);
        qelineedit_37->setObjectName(QStringLiteral("qelineedit_37"));
        qelineedit_37->setEnabled(true);
        qelineedit_37->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_37, 5, 2, 1, 1);

        qelineedit_43 = new QELineEdit(layoutWidget1);
        qelineedit_43->setObjectName(QStringLiteral("qelineedit_43"));
        qelineedit_43->setEnabled(true);
        qelineedit_43->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_43, 1, 3, 1, 1);

        qelineedit_34 = new QELineEdit(layoutWidget1);
        qelineedit_34->setObjectName(QStringLiteral("qelineedit_34"));
        qelineedit_34->setEnabled(true);
        qelineedit_34->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_34, 2, 2, 1, 1);

        label_77 = new QLabel(layoutWidget1);
        label_77->setObjectName(QStringLiteral("label_77"));

        gridLayout_8->addWidget(label_77, 3, 1, 1, 1);

        label_83 = new QLabel(layoutWidget1);
        label_83->setObjectName(QStringLiteral("label_83"));

        gridLayout_8->addWidget(label_83, 0, 1, 1, 1);

        qelineedit_47 = new QELineEdit(layoutWidget1);
        qelineedit_47->setObjectName(QStringLiteral("qelineedit_47"));
        qelineedit_47->setEnabled(true);
        qelineedit_47->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_47, 5, 4, 1, 1);

        qelineedit_35 = new QELineEdit(layoutWidget1);
        qelineedit_35->setObjectName(QStringLiteral("qelineedit_35"));
        qelineedit_35->setEnabled(true);
        qelineedit_35->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_35, 3, 2, 1, 1);

        label_81 = new QLabel(layoutWidget1);
        label_81->setObjectName(QStringLiteral("label_81"));

        gridLayout_8->addWidget(label_81, 5, 1, 1, 1);

        qelineedit_42 = new QELineEdit(layoutWidget1);
        qelineedit_42->setObjectName(QStringLiteral("qelineedit_42"));
        qelineedit_42->setEnabled(true);
        qelineedit_42->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_42, 5, 3, 1, 1);

        label_68 = new QLabel(layoutWidget1);
        label_68->setObjectName(QStringLiteral("label_68"));

        gridLayout_8->addWidget(label_68, 1, 1, 1, 1);

        qelineedit_39 = new QELineEdit(layoutWidget1);
        qelineedit_39->setObjectName(QStringLiteral("qelineedit_39"));
        qelineedit_39->setEnabled(true);
        qelineedit_39->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_39, 3, 3, 1, 1);

        label_73 = new QLabel(layoutWidget1);
        label_73->setObjectName(QStringLiteral("label_73"));

        gridLayout_8->addWidget(label_73, 2, 0, 1, 1);

        qelineedit_46 = new QELineEdit(layoutWidget1);
        qelineedit_46->setObjectName(QStringLiteral("qelineedit_46"));
        qelineedit_46->setEnabled(true);
        qelineedit_46->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_46, 2, 4, 1, 1);

        label_86 = new QLabel(layoutWidget1);
        label_86->setObjectName(QStringLiteral("label_86"));

        gridLayout_8->addWidget(label_86, 0, 4, 1, 1);

        label_85 = new QLabel(layoutWidget1);
        label_85->setObjectName(QStringLiteral("label_85"));

        gridLayout_8->addWidget(label_85, 0, 3, 1, 1);

        qelineedit_38 = new QELineEdit(layoutWidget1);
        qelineedit_38->setObjectName(QStringLiteral("qelineedit_38"));
        qelineedit_38->setEnabled(true);
        qelineedit_38->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_38, 6, 3, 1, 1);

        label_84 = new QLabel(layoutWidget1);
        label_84->setObjectName(QStringLiteral("label_84"));

        gridLayout_8->addWidget(label_84, 0, 2, 1, 1);

        label_79 = new QLabel(layoutWidget1);
        label_79->setObjectName(QStringLiteral("label_79"));

        gridLayout_8->addWidget(label_79, 4, 1, 1, 1);

        label_78 = new QLabel(layoutWidget1);
        label_78->setObjectName(QStringLiteral("label_78"));

        gridLayout_8->addWidget(label_78, 4, 0, 1, 1);

        qelineedit_36 = new QELineEdit(layoutWidget1);
        qelineedit_36->setObjectName(QStringLiteral("qelineedit_36"));
        qelineedit_36->setEnabled(true);
        qelineedit_36->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_36, 4, 2, 1, 1);

        label_74 = new QLabel(layoutWidget1);
        label_74->setObjectName(QStringLiteral("label_74"));

        gridLayout_8->addWidget(label_74, 2, 1, 1, 1);

        label_87 = new QLabel(layoutWidget1);
        label_87->setObjectName(QStringLiteral("label_87"));

        gridLayout_8->addWidget(label_87, 6, 0, 1, 1);

        qelineedit_41 = new QELineEdit(layoutWidget1);
        qelineedit_41->setObjectName(QStringLiteral("qelineedit_41"));
        qelineedit_41->setEnabled(true);
        qelineedit_41->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_41, 2, 3, 1, 1);

        qelineedit_49 = new QELineEdit(layoutWidget1);
        qelineedit_49->setObjectName(QStringLiteral("qelineedit_49"));
        qelineedit_49->setEnabled(true);
        qelineedit_49->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_49, 3, 4, 1, 1);

        label_76 = new QLabel(layoutWidget1);
        label_76->setObjectName(QStringLiteral("label_76"));

        gridLayout_8->addWidget(label_76, 3, 0, 1, 1);

        qelineedit_48 = new QELineEdit(layoutWidget1);
        qelineedit_48->setObjectName(QStringLiteral("qelineedit_48"));
        qelineedit_48->setEnabled(true);
        qelineedit_48->setAutoFillBackground(false);

        gridLayout_8->addWidget(qelineedit_48, 4, 4, 1, 1);

        label_82 = new QLabel(layoutWidget1);
        label_82->setObjectName(QStringLiteral("label_82"));

        gridLayout_8->addWidget(label_82, 6, 1, 1, 1);

        layoutWidget2 = new QWidget(Dialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(12, 372, 171, 131));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 1, 1, 1);

        qelineedit = new QELineEdit(layoutWidget2);
        qelineedit->setObjectName(QStringLiteral("qelineedit"));
        qelineedit->setEnabled(true);
        qelineedit->setAutoFillBackground(false);

        gridLayout_2->addWidget(qelineedit, 0, 2, 1, 1);

        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 2, 1);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 1, 2, 2);

        qelineedit_2 = new QELineEdit(layoutWidget2);
        qelineedit_2->setObjectName(QStringLiteral("qelineedit_2"));
        qelineedit_2->setEnabled(true);
        qelineedit_2->setAutoFillBackground(false);

        gridLayout_2->addWidget(qelineedit_2, 2, 2, 1, 1);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 3, 0, 2, 1);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 3, 1, 2, 2);

        qelineedit_3 = new QELineEdit(layoutWidget2);
        qelineedit_3->setObjectName(QStringLiteral("qelineedit_3"));
        qelineedit_3->setEnabled(true);
        qelineedit_3->setAutoFillBackground(false);

        gridLayout_2->addWidget(qelineedit_3, 4, 2, 1, 1);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 5, 0, 2, 1);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 5, 1, 2, 2);

        qelineedit_4 = new QELineEdit(layoutWidget2);
        qelineedit_4->setObjectName(QStringLiteral("qelineedit_4"));
        qelineedit_4->setEnabled(true);
        qelineedit_4->setAutoFillBackground(false);

        gridLayout_2->addWidget(qelineedit_4, 6, 2, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        lblTitle_4->setText(QApplication::translate("Dialog", "<html><head/><body><p>DCA | HESEB | SCAN TOOL | Other PVs readout</p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("Dialog", "Movable Masks:", Q_NULLPTR));
        qelineedit_15->setProperty("variable", QVariant(QApplication::translate("Dialog", "SR-DI-LBR9-bpm1:getSlowAcquisitionXScale", Q_NULLPTR)));
        qelineedit_12->setProperty("variable", QVariant(QApplication::translate("Dialog", "ID11:getShift", Q_NULLPTR)));
        label_30->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label_23->setText(QApplication::translate("Dialog", "U.G. (mm)", Q_NULLPTR));
        qelineedit_11->setProperty("variable", QVariant(QApplication::translate("Dialog", "ID11:getGap", Q_NULLPTR)));
        label_33->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label_26->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        qelineedit_14->setProperty("variable", QVariant(QApplication::translate("Dialog", "SR-DI-LBR8-bpm4:getSlowAcquisitionYScale", Q_NULLPTR)));
        label_24->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label_22->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label_21->setText(QApplication::translate("Dialog", "C (mA)", Q_NULLPTR));
        qelineedit_10->setProperty("variable", QVariant(QApplication::translate("Dialog", "SRC01-DI-DCCT1:getDcctCurrent", Q_NULLPTR)));
        label_32->setText(QApplication::translate("Dialog", "DWSX (mm)", Q_NULLPTR));
        label_25->setText(QApplication::translate("Dialog", "U.S. (mm)", Q_NULLPTR));
        qelineedit_13->setProperty("variable", QVariant(QApplication::translate("Dialog", "SR-DI-LBR8-bpm4:getSlowAcquisitionXScale", Q_NULLPTR)));
        label_28->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label_29->setText(QApplication::translate("Dialog", "UPSY (mm)", Q_NULLPTR));
        label_27->setText(QApplication::translate("Dialog", "UPSX (mm)", Q_NULLPTR));
        label_34->setText(QApplication::translate("Dialog", "DWSY (mm)", Q_NULLPTR));
        label_35->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        qelineedit_16->setProperty("variable", QVariant(QApplication::translate("Dialog", "SR-DI-LBR9-bpm1:getSlowAcquisitionYScale", Q_NULLPTR)));
        label_31->setText(QApplication::translate("Dialog", "Source", Q_NULLPTR));
        label_36->setText(QApplication::translate("Dialog", "C", Q_NULLPTR));
        label_37->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label_38->setText(QApplication::translate("Dialog", "K", Q_NULLPTR));
        label_40->setText(QApplication::translate("Dialog", "G (Line/mm)", Q_NULLPTR));
        label_41->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label_39->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        qelineedit_18->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-PGM:DiffractionOrder", Q_NULLPTR)));
        qelineedit_17->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-PGM:getMagnificationMagnitude", Q_NULLPTR)));
        qelineedit_19->setProperty("variable", QVariant(QString()));
        label_46->setText(QApplication::translate("Dialog", "Scan Parameters", Q_NULLPTR));
        label_58->setText(QApplication::translate("Dialog", "V. S. (mm)", Q_NULLPTR));
        qelineedit_28->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-PGM:M3:getSlitSize", Q_NULLPTR)));
        label_59->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label_64->setText(QApplication::translate("Dialog", "Vertical Slit", Q_NULLPTR));
        label_88->setText(QApplication::translate("Dialog", "Mirros", Q_NULLPTR));
        label_80->setText(QApplication::translate("Dialog", "V.T. (mm)", Q_NULLPTR));
        qelineedit_45->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-M4:getRoll", Q_NULLPTR)));
        qelineedit_27->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11FE-M1:getRoll", Q_NULLPTR)));
        qelineedit_40->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-M3:getHorizontal", Q_NULLPTR)));
        label_62->setText(QApplication::translate("Dialog", "R (mrad)", Q_NULLPTR));
        qelineedit_37->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11FE-M1:getVertical", Q_NULLPTR)));
        qelineedit_43->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-M3:getRoll", Q_NULLPTR)));
        qelineedit_34->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11FE-M1:getPitch", Q_NULLPTR)));
        label_77->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label_83->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        qelineedit_47->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-M4:getVertical", Q_NULLPTR)));
        qelineedit_35->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11FE-M1:getYaw", Q_NULLPTR)));
        label_81->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        qelineedit_42->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-M3:getVertical", Q_NULLPTR)));
        label_68->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        qelineedit_39->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-M3:getYaw", Q_NULLPTR)));
        label_73->setText(QApplication::translate("Dialog", "P (mrad)", Q_NULLPTR));
        qelineedit_46->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-M4:getPitch", Q_NULLPTR)));
        label_86->setText(QApplication::translate("Dialog", "Mirror 4a", Q_NULLPTR));
        label_85->setText(QApplication::translate("Dialog", "Mirror 3", Q_NULLPTR));
        qelineedit_38->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11R1-MO-MC3:OH-M3-STP-SWX.RBV", Q_NULLPTR)));
        label_84->setText(QApplication::translate("Dialog", "Mirror 1", Q_NULLPTR));
        label_79->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label_78->setText(QApplication::translate("Dialog", "H.T. (mm)", Q_NULLPTR));
        qelineedit_36->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11FE-M1:getHorizontal", Q_NULLPTR)));
        label_74->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label_87->setText(QApplication::translate("Dialog", "C.P. (mm)", Q_NULLPTR));
        qelineedit_41->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-M3:getPitch", Q_NULLPTR)));
        qelineedit_49->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-M4:getYaw", Q_NULLPTR)));
        label_76->setText(QApplication::translate("Dialog", "Y (mrad)", Q_NULLPTR));
        qelineedit_48->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11OH-M4:getHorizontal", Q_NULLPTR)));
        label_82->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "H.G. (mm)", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        qelineedit->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11FE-MM:getXGap", Q_NULLPTR)));
        label_3->setText(QApplication::translate("Dialog", "V.G. (mm)", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        qelineedit_2->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11FE-MM:getYGap", Q_NULLPTR)));
        label_2->setText(QApplication::translate("Dialog", "H.C. (mm)", Q_NULLPTR));
        label_7->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        qelineedit_3->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11FE-MM:getXCenter", Q_NULLPTR)));
        label_4->setText(QApplication::translate("Dialog", "V.C. (mm)", Q_NULLPTR));
        label_8->setText(QApplication::translate("Dialog", ":", Q_NULLPTR));
        qelineedit_4->setProperty("variable", QVariant(QApplication::translate("Dialog", "I11FE-MM:getYCenter", Q_NULLPTR)));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HESEB_OTHER_PVS_READOUT_H
