# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'detectors.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(675, 294)
        self.buttonBox = QtWidgets.QDialogButtonBox(Dialog)
        self.buttonBox.setGeometry(QtCore.QRect(300, 240, 341, 32))
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.groupBox = QtWidgets.QGroupBox(Dialog)
        self.groupBox.setGeometry(QtCore.QRect(10, 10, 631, 221))
        self.groupBox.setObjectName("groupBox")
        self.label = QtWidgets.QLabel(self.groupBox)
        self.label.setGeometry(QtCore.QRect(10, 30, 141, 20))
        self.label.setObjectName("label")
        self.IC1 = QtWidgets.QCheckBox(self.groupBox)
        self.IC1.setGeometry(QtCore.QRect(10, 50, 41, 26))
        self.IC1.setChecked(True)
        self.IC1.setObjectName("IC1")
        self.IC2 = QtWidgets.QCheckBox(self.groupBox)
        self.IC2.setGeometry(QtCore.QRect(60, 50, 41, 26))
        self.IC2.setChecked(True)
        self.IC2.setObjectName("IC2")
        self.IC3 = QtWidgets.QCheckBox(self.groupBox)
        self.IC3.setGeometry(QtCore.QRect(110, 50, 41, 26))
        self.IC3.setChecked(False)
        self.IC3.setObjectName("IC3")
        self.label_2 = QtWidgets.QLabel(self.groupBox)
        self.label_2.setGeometry(QtCore.QRect(10, 80, 141, 20))
        self.label_2.setObjectName("label_2")
        self.FICUS_ROI1 = QtWidgets.QCheckBox(self.groupBox)
        self.FICUS_ROI1.setGeometry(QtCore.QRect(10, 100, 61, 26))
        self.FICUS_ROI1.setChecked(True)
        self.FICUS_ROI1.setObjectName("FICUS_ROI1")
        self.FICUS_ROI2 = QtWidgets.QCheckBox(self.groupBox)
        self.FICUS_ROI2.setGeometry(QtCore.QRect(65, 100, 61, 26))
        self.FICUS_ROI2.setChecked(False)
        self.FICUS_ROI2.setObjectName("FICUS_ROI2")
        self.FICUS_ROI4 = QtWidgets.QCheckBox(self.groupBox)
        self.FICUS_ROI4.setGeometry(QtCore.QRect(175, 100, 61, 26))
        self.FICUS_ROI4.setChecked(False)
        self.FICUS_ROI4.setObjectName("FICUS_ROI4")
        self.FICUS_ROI3 = QtWidgets.QCheckBox(self.groupBox)
        self.FICUS_ROI3.setGeometry(QtCore.QRect(120, 100, 61, 26))
        self.FICUS_ROI3.setChecked(False)
        self.FICUS_ROI3.setObjectName("FICUS_ROI3")
        self.FICUS_ROI7 = QtWidgets.QCheckBox(self.groupBox)
        self.FICUS_ROI7.setGeometry(QtCore.QRect(340, 100, 61, 26))
        self.FICUS_ROI7.setChecked(False)
        self.FICUS_ROI7.setObjectName("FICUS_ROI7")
        self.FICUS_ROI8 = QtWidgets.QCheckBox(self.groupBox)
        self.FICUS_ROI8.setGeometry(QtCore.QRect(395, 100, 61, 26))
        self.FICUS_ROI8.setChecked(False)
        self.FICUS_ROI8.setObjectName("FICUS_ROI8")
        self.FICUS_ROI6 = QtWidgets.QCheckBox(self.groupBox)
        self.FICUS_ROI6.setGeometry(QtCore.QRect(285, 100, 61, 26))
        self.FICUS_ROI6.setChecked(False)
        self.FICUS_ROI6.setObjectName("FICUS_ROI6")
        self.FICUS_ROI5 = QtWidgets.QCheckBox(self.groupBox)
        self.FICUS_ROI5.setGeometry(QtCore.QRect(230, 100, 61, 26))
        self.FICUS_ROI5.setChecked(False)
        self.FICUS_ROI5.setObjectName("FICUS_ROI5")
        self.label_3 = QtWidgets.QLabel(self.groupBox)
        self.label_3.setGeometry(QtCore.QRect(10, 130, 141, 20))
        self.label_3.setObjectName("label_3")
        self.KETEK_ROI3 = QtWidgets.QCheckBox(self.groupBox)
        self.KETEK_ROI3.setGeometry(QtCore.QRect(120, 150, 61, 26))
        self.KETEK_ROI3.setChecked(False)
        self.KETEK_ROI3.setObjectName("KETEK_ROI3")
        self.KETEK_ROI4 = QtWidgets.QCheckBox(self.groupBox)
        self.KETEK_ROI4.setGeometry(QtCore.QRect(175, 150, 61, 26))
        self.KETEK_ROI4.setChecked(False)
        self.KETEK_ROI4.setObjectName("KETEK_ROI4")
        self.KETEK_ROI6 = QtWidgets.QCheckBox(self.groupBox)
        self.KETEK_ROI6.setGeometry(QtCore.QRect(285, 150, 61, 26))
        self.KETEK_ROI6.setChecked(False)
        self.KETEK_ROI6.setObjectName("KETEK_ROI6")
        self.KETEK_ROI7 = QtWidgets.QCheckBox(self.groupBox)
        self.KETEK_ROI7.setGeometry(QtCore.QRect(340, 150, 61, 26))
        self.KETEK_ROI7.setChecked(False)
        self.KETEK_ROI7.setObjectName("KETEK_ROI7")
        self.KETEK_ROI2 = QtWidgets.QCheckBox(self.groupBox)
        self.KETEK_ROI2.setGeometry(QtCore.QRect(65, 150, 61, 26))
        self.KETEK_ROI2.setChecked(False)
        self.KETEK_ROI2.setObjectName("KETEK_ROI2")
        self.KETEK_ROI8 = QtWidgets.QCheckBox(self.groupBox)
        self.KETEK_ROI8.setGeometry(QtCore.QRect(395, 150, 61, 26))
        self.KETEK_ROI8.setChecked(False)
        self.KETEK_ROI8.setObjectName("KETEK_ROI8")
        self.KETEK_ROI1 = QtWidgets.QCheckBox(self.groupBox)
        self.KETEK_ROI1.setGeometry(QtCore.QRect(10, 150, 61, 26))
        self.KETEK_ROI1.setChecked(False)
        self.KETEK_ROI1.setObjectName("KETEK_ROI1")
        self.KETEK_ROI5 = QtWidgets.QCheckBox(self.groupBox)
        self.KETEK_ROI5.setGeometry(QtCore.QRect(230, 150, 61, 26))
        self.KETEK_ROI5.setChecked(False)
        self.KETEK_ROI5.setObjectName("KETEK_ROI5")
        self.FICUS_SPECMODE = QtWidgets.QCheckBox(self.groupBox)
        self.FICUS_SPECMODE.setGeometry(QtCore.QRect(460, 100, 131, 26))
        self.FICUS_SPECMODE.setChecked(False)
        self.FICUS_SPECMODE.setObjectName("FICUS_SPECMODE")
        self.KETEK_SPECMODE = QtWidgets.QCheckBox(self.groupBox)
        self.KETEK_SPECMODE.setGeometry(QtCore.QRect(460, 150, 131, 26))
        self.KETEK_SPECMODE.setChecked(False)
        self.KETEK_SPECMODE.setObjectName("KETEK_SPECMODE")

        self.retranslateUi(Dialog)
        self.buttonBox.accepted.connect(Dialog.accept)
        self.buttonBox.rejected.connect(Dialog.reject)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
        self.groupBox.setTitle(_translate("Dialog", "Detectors confguration"))
        self.label.setText(_translate("Dialog", "Ionization chambers"))
        self.IC1.setText(_translate("Dialog", "IC1"))
        self.IC2.setText(_translate("Dialog", "IC2"))
        self.IC3.setText(_translate("Dialog", "IC3"))
        self.label_2.setText(_translate("Dialog", "FICUS"))
        self.FICUS_ROI1.setText(_translate("Dialog", "ROI1"))
        self.FICUS_ROI2.setText(_translate("Dialog", "ROI2"))
        self.FICUS_ROI4.setText(_translate("Dialog", "ROI4"))
        self.FICUS_ROI3.setText(_translate("Dialog", "ROI3"))
        self.FICUS_ROI7.setText(_translate("Dialog", "ROI7"))
        self.FICUS_ROI8.setText(_translate("Dialog", "ROI8"))
        self.FICUS_ROI6.setText(_translate("Dialog", "ROI6"))
        self.FICUS_ROI5.setText(_translate("Dialog", "ROI5"))
        self.label_3.setText(_translate("Dialog", "KETEK"))
        self.KETEK_ROI3.setText(_translate("Dialog", "ROI3"))
        self.KETEK_ROI4.setText(_translate("Dialog", "ROI4"))
        self.KETEK_ROI6.setText(_translate("Dialog", "ROI6"))
        self.KETEK_ROI7.setText(_translate("Dialog", "ROI7"))
        self.KETEK_ROI2.setText(_translate("Dialog", "ROI2"))
        self.KETEK_ROI8.setText(_translate("Dialog", "ROI8"))
        self.KETEK_ROI1.setText(_translate("Dialog", "ROI1"))
        self.KETEK_ROI5.setText(_translate("Dialog", "ROI5"))
        self.FICUS_SPECMODE.setText(_translate("Dialog", "Spectrum Mode"))
        self.KETEK_SPECMODE.setText(_translate("Dialog", "Spectrum Mode"))
