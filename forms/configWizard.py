# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui/configWizard.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Wizard(object):
    def setupUi(self, Wizard):
        Wizard.setObjectName("Wizard")
        Wizard.resize(460, 718)
        self.ExpType = QtWidgets.QWizardPage()
        self.ExpType.setObjectName("ExpType")
        self.groupBox = QtWidgets.QGroupBox(self.ExpType)
        self.groupBox.setGeometry(QtCore.QRect(10, 10, 371, 101))
        self.groupBox.setObjectName("groupBox")
        self.UsersExp = QtWidgets.QRadioButton(self.groupBox)
        self.UsersExp.setGeometry(QtCore.QRect(10, 40, 141, 26))
        self.UsersExp.setChecked(True)
        self.UsersExp.setObjectName("UsersExp")
        self.LocalExp = QtWidgets.QRadioButton(self.groupBox)
        self.LocalExp.setGeometry(QtCore.QRect(10, 70, 141, 26))
        self.LocalExp.setObjectName("LocalExp")
        Wizard.addPage(self.ExpType)
        self.SED = QtWidgets.QWizardPage()
        self.SED.setObjectName("SED")
        self.groupBox_2 = QtWidgets.QGroupBox(self.SED)
        self.groupBox_2.setGeometry(QtCore.QRect(20, 20, 351, 81))
        self.groupBox_2.setObjectName("groupBox_2")
        self.PropsalID = QtWidgets.QLineEdit(self.groupBox_2)
        self.PropsalID.setGeometry(QtCore.QRect(10, 40, 331, 28))
        self.PropsalID.setText("")
        self.PropsalID.setObjectName("PropsalID")
        Wizard.addPage(self.SED)
        self.CfgFile = QtWidgets.QWizardPage()
        self.CfgFile.setObjectName("CfgFile")
        self.groupBox_3 = QtWidgets.QGroupBox(self.CfgFile)
        self.groupBox_3.setGeometry(QtCore.QRect(10, 10, 411, 101))
        self.groupBox_3.setObjectName("groupBox_3")
        self.Create = QtWidgets.QRadioButton(self.groupBox_3)
        self.Create.setGeometry(QtCore.QRect(10, 40, 181, 26))
        self.Create.setChecked(True)
        self.Create.setObjectName("Create")
        self.Load = QtWidgets.QRadioButton(self.groupBox_3)
        self.Load.setGeometry(QtCore.QRect(10, 70, 181, 26))
        self.Load.setObjectName("Load")
        Wizard.addPage(self.CfgFile)
        self.CfgPath = QtWidgets.QWizardPage()
        self.CfgPath.setObjectName("CfgPath")
        self.filePath = QtWidgets.QLineEdit(self.CfgPath)
        self.filePath.setEnabled(False)
        self.filePath.setGeometry(QtCore.QRect(100, 75, 261, 28))
        self.filePath.setObjectName("filePath")
        self.label = QtWidgets.QLabel(self.CfgPath)
        self.label.setGeometry(QtCore.QRect(0, 79, 101, 21))
        self.label.setObjectName("label")
        self.Browse = QtWidgets.QToolButton(self.CfgPath)
        self.Browse.setGeometry(QtCore.QRect(370, 75, 28, 27))
        self.Browse.setObjectName("Browse")
        Wizard.addPage(self.CfgPath)
        self.scan_params = QtWidgets.QWizardPage()
        self.scan_params.setObjectName("scan_params")
        self.groupBox_4 = QtWidgets.QGroupBox(self.scan_params)
        self.groupBox_4.setGeometry(QtCore.QRect(10, 10, 421, 231))
        self.groupBox_4.setObjectName("groupBox_4")
        self.layoutWidget = QtWidgets.QWidget(self.groupBox_4)
        self.layoutWidget.setGeometry(QtCore.QRect(21, 30, 393, 198))
        self.layoutWidget.setObjectName("layoutWidget")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.layoutWidget)
        self.gridLayout_2.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.label_36 = QtWidgets.QLabel(self.layoutWidget)
        self.label_36.setObjectName("label_36")
        self.gridLayout_2.addWidget(self.label_36, 0, 0, 1, 1)
        self.setNumofIterv = QtWidgets.QLineEdit(self.layoutWidget)
        self.setNumofIterv.setAlignment(QtCore.Qt.AlignCenter)
        self.setNumofIterv.setObjectName("setNumofIterv")
        self.gridLayout_2.addWidget(self.setNumofIterv, 0, 1, 1, 2)
        self.editIntrv = QtWidgets.QPushButton(self.layoutWidget)
        self.editIntrv.setObjectName("editIntrv")
        self.gridLayout_2.addWidget(self.editIntrv, 0, 3, 1, 1)
        self.label_33 = QtWidgets.QLabel(self.layoutWidget)
        self.label_33.setObjectName("label_33")
        self.gridLayout_2.addWidget(self.label_33, 1, 0, 1, 1)
        self.setNumofSamples = QtWidgets.QLineEdit(self.layoutWidget)
        self.setNumofSamples.setAlignment(QtCore.Qt.AlignCenter)
        self.setNumofSamples.setObjectName("setNumofSamples")
        self.gridLayout_2.addWidget(self.setNumofSamples, 1, 1, 1, 2)
        self.editSample = QtWidgets.QPushButton(self.layoutWidget)
        self.editSample.setObjectName("editSample")
        self.gridLayout_2.addWidget(self.editSample, 1, 3, 1, 1)
        self.label_34 = QtWidgets.QLabel(self.layoutWidget)
        self.label_34.setObjectName("label_34")
        self.gridLayout_2.addWidget(self.label_34, 2, 0, 1, 1)
        self.setNumofScans = QtWidgets.QLineEdit(self.layoutWidget)
        self.setNumofScans.setAlignment(QtCore.Qt.AlignCenter)
        self.setNumofScans.setObjectName("setNumofScans")
        self.gridLayout_2.addWidget(self.setNumofScans, 2, 1, 1, 2)
        self.label_37 = QtWidgets.QLabel(self.layoutWidget)
        self.label_37.setObjectName("label_37")
        self.gridLayout_2.addWidget(self.label_37, 3, 0, 1, 1)
        self.configureDetectors = QtWidgets.QPushButton(self.layoutWidget)
        self.configureDetectors.setObjectName("configureDetectors")
        self.gridLayout_2.addWidget(self.configureDetectors, 3, 1, 1, 2)
        self.label_35 = QtWidgets.QLabel(self.layoutWidget)
        self.label_35.setObjectName("label_35")
        self.gridLayout_2.addWidget(self.label_35, 4, 0, 1, 1)
        self.setDataFileName = QtWidgets.QLineEdit(self.layoutWidget)
        self.setDataFileName.setObjectName("setDataFileName")
        self.gridLayout_2.addWidget(self.setDataFileName, 4, 1, 1, 2)
        self.label_11 = QtWidgets.QLabel(self.layoutWidget)
        self.label_11.setObjectName("label_11")
        self.gridLayout_2.addWidget(self.label_11, 5, 0, 1, 1)
        self.settlingTime = QtWidgets.QLineEdit(self.layoutWidget)
        self.settlingTime.setAlignment(QtCore.Qt.AlignCenter)
        self.settlingTime.setObjectName("settlingTime")
        self.gridLayout_2.addWidget(self.settlingTime, 5, 1, 1, 1)
        self.label_12 = QtWidgets.QLabel(self.layoutWidget)
        self.label_12.setObjectName("label_12")
        self.gridLayout_2.addWidget(self.label_12, 5, 2, 1, 1)
        self.metadataGroupBox = QtWidgets.QGroupBox(self.scan_params)
        self.metadataGroupBox.setGeometry(QtCore.QRect(9, 260, 421, 371))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(3)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.metadataGroupBox.sizePolicy().hasHeightForWidth())
        self.metadataGroupBox.setSizePolicy(sizePolicy)
        self.metadataGroupBox.setObjectName("metadataGroupBox")
        self.groupBox_5 = QtWidgets.QGroupBox(self.metadataGroupBox)
        self.groupBox_5.setGeometry(QtCore.QRect(10, 180, 206, 71))
        self.groupBox_5.setObjectName("groupBox_5")
        self.layoutWidget1 = QtWidgets.QWidget(self.groupBox_5)
        self.layoutWidget1.setGeometry(QtCore.QRect(10, 30, 193, 32))
        self.layoutWidget1.setObjectName("layoutWidget1")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout(self.layoutWidget1)
        self.horizontalLayout_3.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_6 = QtWidgets.QLabel(self.layoutWidget1)
        self.label_6.setObjectName("label_6")
        self.horizontalLayout_3.addWidget(self.label_6)
        self.vcm = QtWidgets.QComboBox(self.layoutWidget1)
        self.vcm.setFrame(False)
        self.vcm.setObjectName("vcm")
        self.vcm.addItem("")
        self.vcm.setItemText(0, "")
        self.vcm.addItem("")
        self.vcm.addItem("")
        self.horizontalLayout_3.addWidget(self.vcm)
        self.label_7 = QtWidgets.QLabel(self.layoutWidget1)
        self.label_7.setObjectName("label_7")
        self.horizontalLayout_3.addWidget(self.label_7)
        self.vfm = QtWidgets.QComboBox(self.layoutWidget1)
        self.vfm.setFrame(False)
        self.vfm.setObjectName("vfm")
        self.vfm.addItem("")
        self.vfm.setItemText(0, "")
        self.vfm.addItem("")
        self.vfm.addItem("")
        self.horizontalLayout_3.addWidget(self.vfm)
        self.ExpCommentsGroupBox = QtWidgets.QGroupBox(self.metadataGroupBox)
        self.ExpCommentsGroupBox.setGeometry(QtCore.QRect(10, 260, 401, 91))
        self.ExpCommentsGroupBox.setObjectName("ExpCommentsGroupBox")
        self.layoutWidget2 = QtWidgets.QWidget(self.ExpCommentsGroupBox)
        self.layoutWidget2.setGeometry(QtCore.QRect(12, 30, 371, 54))
        self.layoutWidget2.setObjectName("layoutWidget2")
        self.gridLayout = QtWidgets.QGridLayout(self.layoutWidget2)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.UserComments = QtWidgets.QLabel(self.layoutWidget2)
        self.UserComments.setObjectName("UserComments")
        self.gridLayout.addWidget(self.UserComments, 0, 0, 1, 1)
        self.ExpComments = QtWidgets.QLabel(self.layoutWidget2)
        self.ExpComments.setObjectName("ExpComments")
        self.gridLayout.addWidget(self.ExpComments, 1, 0, 1, 1)
        self.expCom = QtWidgets.QLineEdit(self.layoutWidget2)
        self.expCom.setText("")
        self.expCom.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.expCom.setObjectName("expCom")
        self.gridLayout.addWidget(self.expCom, 1, 1, 1, 1)
        self.userCom = QtWidgets.QLineEdit(self.layoutWidget2)
        self.userCom.setText("")
        self.userCom.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.userCom.setObjectName("userCom")
        self.gridLayout.addWidget(self.userCom, 0, 1, 1, 1)
        self.groupBox_6 = QtWidgets.QGroupBox(self.metadataGroupBox)
        self.groupBox_6.setGeometry(QtCore.QRect(10, 30, 401, 141))
        self.groupBox_6.setObjectName("groupBox_6")
        self.layoutWidget3 = QtWidgets.QWidget(self.groupBox_6)
        self.layoutWidget3.setGeometry(QtCore.QRect(10, 30, 371, 32))
        self.layoutWidget3.setObjectName("layoutWidget3")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.layoutWidget3)
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.edge = QtWidgets.QComboBox(self.layoutWidget3)
        self.edge.setFrame(False)
        self.edge.setObjectName("edge")
        self.edge.addItem("")
        self.edge.setItemText(0, "")
        self.edge.addItem("")
        self.edge.addItem("")
        self.edge.addItem("")
        self.edge.addItem("")
        self.horizontalLayout.addWidget(self.edge)
        self.label_3 = QtWidgets.QLabel(self.layoutWidget3)
        self.label_3.setObjectName("label_3")
        self.horizontalLayout.addWidget(self.label_3)
        self.sampleName = QtWidgets.QLineEdit(self.layoutWidget3)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.sampleName.sizePolicy().hasHeightForWidth())
        self.sampleName.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.sampleName.setFont(font)
        self.sampleName.setText("")
        self.sampleName.setMaxLength(2)
        self.sampleName.setFrame(False)
        self.sampleName.setAlignment(QtCore.Qt.AlignCenter)
        self.sampleName.setObjectName("sampleName")
        self.horizontalLayout.addWidget(self.sampleName)
        self.label_4 = QtWidgets.QLabel(self.layoutWidget3)
        self.label_4.setObjectName("label_4")
        self.horizontalLayout.addWidget(self.label_4)
        self.energy = QtWidgets.QLineEdit(self.layoutWidget3)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.energy.setFont(font)
        self.energy.setText("")
        self.energy.setMaxLength(50)
        self.energy.setFrame(False)
        self.energy.setAlignment(QtCore.Qt.AlignCenter)
        self.energy.setObjectName("energy")
        self.horizontalLayout.addWidget(self.energy)
        self.label_5 = QtWidgets.QLabel(self.layoutWidget3)
        self.label_5.setObjectName("label_5")
        self.horizontalLayout.addWidget(self.label_5)
        self.layoutWidget4 = QtWidgets.QWidget(self.groupBox_6)
        self.layoutWidget4.setGeometry(QtCore.QRect(13, 101, 371, 23))
        self.layoutWidget4.setObjectName("layoutWidget4")
        self.formLayout = QtWidgets.QFormLayout(self.layoutWidget4)
        self.formLayout.setContentsMargins(0, 0, 0, 0)
        self.formLayout.setObjectName("formLayout")
        self.label_samplePrep = QtWidgets.QLabel(self.layoutWidget4)
        self.label_samplePrep.setObjectName("label_samplePrep")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.label_samplePrep)
        self.samplePrep = QtWidgets.QLineEdit(self.layoutWidget4)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.samplePrep.sizePolicy().hasHeightForWidth())
        self.samplePrep.setSizePolicy(sizePolicy)
        self.samplePrep.setText("")
        self.samplePrep.setMaxLength(500)
        self.samplePrep.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.samplePrep.setObjectName("samplePrep")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.samplePrep)
        self.layoutWidget5 = QtWidgets.QWidget(self.groupBox_6)
        self.layoutWidget5.setGeometry(QtCore.QRect(11, 70, 224, 23))
        self.layoutWidget5.setObjectName("layoutWidget5")
        self.formLayout_2 = QtWidgets.QFormLayout(self.layoutWidget5)
        self.formLayout_2.setContentsMargins(0, 0, 0, 0)
        self.formLayout_2.setObjectName("formLayout_2")
        self.stoichiometry_l = QtWidgets.QLabel(self.layoutWidget5)
        self.stoichiometry_l.setObjectName("stoichiometry_l")
        self.formLayout_2.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.stoichiometry_l)
        self.stoichiometry = QtWidgets.QLineEdit(self.layoutWidget5)
        self.stoichiometry.setText("")
        self.stoichiometry.setAlignment(QtCore.Qt.AlignCenter)
        self.stoichiometry.setObjectName("stoichiometry")
        self.formLayout_2.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.stoichiometry)
        self.groupBox_7 = QtWidgets.QGroupBox(self.metadataGroupBox)
        self.groupBox_7.setGeometry(QtCore.QRect(220, 180, 191, 71))
        self.groupBox_7.setObjectName("groupBox_7")
        self.layoutWidget6 = QtWidgets.QWidget(self.groupBox_7)
        self.layoutWidget6.setGeometry(QtCore.QRect(30, 30, 129, 32))
        self.layoutWidget6.setObjectName("layoutWidget6")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.layoutWidget6)
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label_9 = QtWidgets.QLabel(self.layoutWidget6)
        self.label_9.setObjectName("label_9")
        self.horizontalLayout_2.addWidget(self.label_9)
        self.Mono = QtWidgets.QComboBox(self.layoutWidget6)
        self.Mono.setObjectName("Mono")
        self.Mono.addItem("")
        self.Mono.setItemText(0, "")
        self.Mono.addItem("")
        self.Mono.addItem("")
        self.horizontalLayout_2.addWidget(self.Mono)
        Wizard.addPage(self.scan_params)
        self.startscan = QtWidgets.QWizardPage()
        self.startscan.setObjectName("startscan")
        self.label_2 = QtWidgets.QLabel(self.startscan)
        self.label_2.setGeometry(QtCore.QRect(10, 10, 501, 20))
        self.label_2.setObjectName("label_2")
        Wizard.addPage(self.startscan)

        self.retranslateUi(Wizard)
        QtCore.QMetaObject.connectSlotsByName(Wizard)
        Wizard.setTabOrder(self.UsersExp, self.LocalExp)
        Wizard.setTabOrder(self.LocalExp, self.PropsalID)
        Wizard.setTabOrder(self.PropsalID, self.Create)
        Wizard.setTabOrder(self.Create, self.Load)
        Wizard.setTabOrder(self.Load, self.Browse)
        Wizard.setTabOrder(self.Browse, self.setNumofIterv)
        Wizard.setTabOrder(self.setNumofIterv, self.editIntrv)
        Wizard.setTabOrder(self.editIntrv, self.setNumofSamples)
        Wizard.setTabOrder(self.setNumofSamples, self.editSample)
        Wizard.setTabOrder(self.editSample, self.setNumofScans)
        Wizard.setTabOrder(self.setNumofScans, self.configureDetectors)
        Wizard.setTabOrder(self.configureDetectors, self.setDataFileName)
        Wizard.setTabOrder(self.setDataFileName, self.settlingTime)
        Wizard.setTabOrder(self.settlingTime, self.edge)
        Wizard.setTabOrder(self.edge, self.sampleName)
        Wizard.setTabOrder(self.sampleName, self.energy)
        Wizard.setTabOrder(self.energy, self.stoichiometry)
        Wizard.setTabOrder(self.stoichiometry, self.samplePrep)
        Wizard.setTabOrder(self.samplePrep, self.vcm)
        Wizard.setTabOrder(self.vcm, self.vfm)
        Wizard.setTabOrder(self.vfm, self.Mono)
        Wizard.setTabOrder(self.Mono, self.userCom)
        Wizard.setTabOrder(self.userCom, self.expCom)
        Wizard.setTabOrder(self.expCom, self.filePath)

    def retranslateUi(self, Wizard):
        _translate = QtCore.QCoreApplication.translate
        Wizard.setWindowTitle(_translate("Wizard", "SED | HESEB Scanning Tool"))
        self.groupBox.setTitle(_translate("Wizard", "Please choose your experiment type"))
        self.UsersExp.setText(_translate("Wizard", "Users Experiment"))
        self.LocalExp.setText(_translate("Wizard", "Local Experiment"))
        self.groupBox_2.setTitle(_translate("Wizard", "Please enter your propsal ID"))
        self.groupBox_3.setTitle(_translate("Wizard", "You can create a new configuration file or load existing one"))
        self.Create.setText(_translate("Wizard", "Create configuration file"))
        self.Load.setText(_translate("Wizard", "Load configuration file"))
        self.label.setText(_translate("Wizard", "Exp. config file:"))
        self.Browse.setText(_translate("Wizard", "..."))
        self.groupBox_4.setTitle(_translate("Wizard", "Experiment setup parameters"))
        self.label_36.setText(_translate("Wizard", "Number of intervals"))
        self.editIntrv.setText(_translate("Wizard", "Intervals"))
        self.label_33.setText(_translate("Wizard", "Number of samples"))
        self.editSample.setText(_translate("Wizard", "Samples"))
        self.label_34.setText(_translate("Wizard", "Number of scans"))
        self.label_37.setText(_translate("Wizard", "Detectors"))
        self.configureDetectors.setText(_translate("Wizard", "Choose"))
        self.label_35.setText(_translate("Wizard", "Exp.  file name"))
        self.label_11.setText(_translate("Wizard", "Settling time"))
        self.label_12.setText(_translate("Wizard", "sec"))
        self.metadataGroupBox.setTitle(_translate("Wizard", "Experiment metadata:"))
        self.groupBox_5.setTitle(_translate("Wizard", "Mirror coating:"))
        self.label_6.setText(_translate("Wizard", "VCM:"))
        self.vcm.setItemText(1, _translate("Wizard", "Si"))
        self.vcm.setItemText(2, _translate("Wizard", "Pt"))
        self.label_7.setText(_translate("Wizard", "VFM:"))
        self.vfm.setItemText(1, _translate("Wizard", "Si"))
        self.vfm.setItemText(2, _translate("Wizard", "Pt"))
        self.ExpCommentsGroupBox.setTitle(_translate("Wizard", "Comments: "))
        self.UserComments.setText(_translate("Wizard", "User comments:"))
        self.ExpComments.setText(_translate("Wizard", "Exp. comments:"))
        self.groupBox_6.setTitle(_translate("Wizard", "Sample"))
        self.edge.setItemText(1, _translate("Wizard", "K"))
        self.edge.setItemText(2, _translate("Wizard", "L1"))
        self.edge.setItemText(3, _translate("Wizard", "L2"))
        self.edge.setItemText(4, _translate("Wizard", "L3"))
        self.label_3.setText(_translate("Wizard", "edge of element:"))
        self.label_4.setText(_translate("Wizard", "at energy:"))
        self.label_5.setText(_translate("Wizard", "eV"))
        self.label_samplePrep.setText(_translate("Wizard", "Sample preparation:"))
        self.stoichiometry_l.setText(_translate("Wizard", "Stoichiometry:"))
        self.groupBox_7.setTitle(_translate("Wizard", "Monochromator:"))
        self.label_9.setText(_translate("Wizard", "Crystal:"))
        self.Mono.setItemText(1, _translate("Wizard", "Si 111"))
        self.Mono.setItemText(2, _translate("Wizard", "Si 311"))
        self.label_2.setText(_translate("Wizard", "Press Finish to start scan"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Wizard = QtWidgets.QWizard()
    ui = Ui_Wizard()
    ui.setupUi(Wizard)
    Wizard.show()
    sys.exit(app.exec_())
