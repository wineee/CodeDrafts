# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'form.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *


class Ui_main(object):
    def setupUi(self, main):
        if not main.objectName():
            main.setObjectName(u"main")
        main.resize(760, 617)
        main.setStyleSheet(u"QPushButton:hover { \n"
"    color: red ;\n"
"	font: italic 16pt \"Noto Sans\";\n"
"}")
        self.verticalLayout_3 = QVBoxLayout(main)
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.horizontalLayout = QHBoxLayout()
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.comboBox_type = QComboBox(main)
        self.comboBox_type.setObjectName(u"comboBox_type")

        self.horizontalLayout.addWidget(self.comboBox_type)

        self.lineEdit = QLineEdit(main)
        self.lineEdit.setObjectName(u"lineEdit")

        self.horizontalLayout.addWidget(self.lineEdit)

        self.pushButton_Send = QPushButton(main)
        self.pushButton_Send.setObjectName(u"pushButton_Send")

        self.horizontalLayout.addWidget(self.pushButton_Send)


        self.verticalLayout_3.addLayout(self.horizontalLayout)

        self.line = QFrame(main)
        self.line.setObjectName(u"line")
        self.line.setFrameShape(QFrame.HLine)
        self.line.setFrameShadow(QFrame.Sunken)

        self.verticalLayout_3.addWidget(self.line)

        self.horizontalLayout_3 = QHBoxLayout()
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.verticalLayout = QVBoxLayout()
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.horizontalLayout_2 = QHBoxLayout()
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.label = QLabel(main)
        self.label.setObjectName(u"label")
        sizePolicy = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(2)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label.sizePolicy().hasHeightForWidth())
        self.label.setSizePolicy(sizePolicy)
        self.label.setAlignment(Qt.AlignCenter)

        self.horizontalLayout_2.addWidget(self.label)

        self.pushButton_Add_head = QPushButton(main)
        self.pushButton_Add_head.setObjectName(u"pushButton_Add_head")
        sizePolicy1 = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Fixed)
        sizePolicy1.setHorizontalStretch(1)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.pushButton_Add_head.sizePolicy().hasHeightForWidth())
        self.pushButton_Add_head.setSizePolicy(sizePolicy1)

        self.horizontalLayout_2.addWidget(self.pushButton_Add_head)

        self.horizontalSpacer = QSpacerItem(20, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.horizontalLayout_2.addItem(self.horizontalSpacer)

        self.pushButton_Delete_head = QPushButton(main)
        self.pushButton_Delete_head.setObjectName(u"pushButton_Delete_head")
        sizePolicy1.setHeightForWidth(self.pushButton_Delete_head.sizePolicy().hasHeightForWidth())
        self.pushButton_Delete_head.setSizePolicy(sizePolicy1)

        self.horizontalLayout_2.addWidget(self.pushButton_Delete_head)


        self.verticalLayout.addLayout(self.horizontalLayout_2)

        self.headerstable = QTableWidget(main)
        if (self.headerstable.columnCount() < 2):
            self.headerstable.setColumnCount(2)
        self.headerstable.setObjectName(u"headerstable")
        self.headerstable.setRowCount(0)
        self.headerstable.setColumnCount(2)

        self.verticalLayout.addWidget(self.headerstable)


        self.horizontalLayout_3.addLayout(self.verticalLayout)

        self.line_2 = QFrame(main)
        self.line_2.setObjectName(u"line_2")
        self.line_2.setFrameShape(QFrame.VLine)
        self.line_2.setFrameShadow(QFrame.Sunken)

        self.horizontalLayout_3.addWidget(self.line_2)

        self.verticalLayout_2 = QVBoxLayout()
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.horizontalLayout_5 = QHBoxLayout()
        self.horizontalLayout_5.setObjectName(u"horizontalLayout_5")
        self.horizontalLayout_5.setSizeConstraint(QLayout.SetDefaultConstraint)
        self.horizontalLayout_5.setContentsMargins(-1, 5, 0, 5)
        self.label_2 = QLabel(main)
        self.label_2.setObjectName(u"label_2")
        sizePolicy2 = QSizePolicy(QSizePolicy.Fixed, QSizePolicy.Preferred)
        sizePolicy2.setHorizontalStretch(0)
        sizePolicy2.setVerticalStretch(0)
        sizePolicy2.setHeightForWidth(self.label_2.sizePolicy().hasHeightForWidth())
        self.label_2.setSizePolicy(sizePolicy2)

        self.horizontalLayout_5.addWidget(self.label_2)


        self.verticalLayout_2.addLayout(self.horizontalLayout_5)

        self.textEdit = QTextEdit(main)
        self.textEdit.setObjectName(u"textEdit")

        self.verticalLayout_2.addWidget(self.textEdit)


        self.horizontalLayout_3.addLayout(self.verticalLayout_2)


        self.verticalLayout_3.addLayout(self.horizontalLayout_3)

        self.line_3 = QFrame(main)
        self.line_3.setObjectName(u"line_3")
        self.line_3.setFrameShape(QFrame.HLine)
        self.line_3.setFrameShadow(QFrame.Sunken)

        self.verticalLayout_3.addWidget(self.line_3)

        self.textBrowser_info = QTextBrowser(main)
        self.textBrowser_info.setObjectName(u"textBrowser_info")
        self.textBrowser_info.setLayoutDirection(Qt.LeftToRight)

        self.verticalLayout_3.addWidget(self.textBrowser_info)

        self.horizontalLayout_4 = QHBoxLayout()
        self.horizontalLayout_4.setObjectName(u"horizontalLayout_4")
        self.pushButton_Clear = QPushButton(main)
        self.pushButton_Clear.setObjectName(u"pushButton_Clear")
        sizePolicy3 = QSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        sizePolicy3.setHorizontalStretch(0)
        sizePolicy3.setVerticalStretch(0)
        sizePolicy3.setHeightForWidth(self.pushButton_Clear.sizePolicy().hasHeightForWidth())
        self.pushButton_Clear.setSizePolicy(sizePolicy3)

        self.horizontalLayout_4.addWidget(self.pushButton_Clear)


        self.verticalLayout_3.addLayout(self.horizontalLayout_4)


        self.retranslateUi(main)

        QMetaObject.connectSlotsByName(main)
    # setupUi

    def retranslateUi(self, main):
        main.setWindowTitle(QCoreApplication.translate("main", u"HTTP \u63a5\u53e3\u6d4b\u8bd5", None))
        self.comboBox_type.setCurrentText("")
        self.pushButton_Send.setText(QCoreApplication.translate("main", u"\u53d1\u9001", None))
        self.label.setText(QCoreApplication.translate("main", u"\u6d88\u606f\u5934", None))
        self.pushButton_Add_head.setText(QCoreApplication.translate("main", u"+", None))
        self.pushButton_Delete_head.setText(QCoreApplication.translate("main", u"-", None))
        self.label_2.setText(QCoreApplication.translate("main", u"\u6d88\u606f\u4f53", None))
        self.pushButton_Clear.setText(QCoreApplication.translate("main", u"\u6e05\u9664", None))
    # retranslateUi

