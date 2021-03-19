# This Python file uses the following encoding: utf-8
import sys
# import os


from PySide2.QtWidgets import QApplication, QWidget, QHeaderView, QTableView, QAbstractItemView, QTableWidgetItem, QTextBrowser
# import PySide2.QtCore
# import PySide2.QtUiTools
from PySide2.QtGui import QIcon
from ui_form import Ui_main

import traceback
import requests
from threading import Thread


from PySide2.QtCore import Signal, QObject


# 自定义信号源对象类型，一定要继承自 QObject
class MySignals(QObject):
    # 定义一种信号，两个参数 类型分别是： QTextBrowser 和 字符串
    # 调用 emit方法 发信号时，传入参数 必须是这里指定的 参数类型
    text_print = Signal(QTextBrowser, str)
    # 还可以定义其他种类的信号
    # prepared_print = Signal(str)


# 实例化
global_ms = MySignals()


class main(QWidget):
    def __init__(self):
        super(main, self).__init__()
        # use pyside2-uic
        self.ui = Ui_main()
        self.ui.setupUi(self)
        type = ["GET", "POST", "PUT", "DELETE"]
        self.ui.comboBox_type.addItems(type)
        self.ui.headerstable.horizontalHeader().setStretchLastSection(True)
        self.ui.headerstable.setColumnWidth(0, 100)
        # 一些参数见 https://blog.csdn.net/qq_37289115/article/details/107321710
        self.ui.lineEdit.setText("http://localhost:3000/student")
        self.ui.textEdit.setText('''{
            "name": "Xu Hua",
            "gender": "male",
            "age": "22",
            "TelNum": "17734368"
            }''')
        # items=[['JONES','Beijing','23',2300]]
        # item = (str(items[i][j]))
        self.addOneHeader()
        self.ui.headerstable.setItem(0, 0, QTableWidgetItem("Content-Type"))
        self.ui.headerstable.setItem(0, 1, QTableWidgetItem("application/json"))

        self.ui.pushButton_Send.clicked.connect(self.sendRequest)
        self.ui.pushButton_Add_head.clicked.connect(self.addOneHeader)
        self.ui.pushButton_Delete_head.clicked.connect(self.delOneHeader)
        self.ui.pushButton_Clear.clicked.connect(
            lambda:
                self.ui.textBrowser_info.clear()
            )
        # 自定义信号的处理函数
        global_ms.text_print.connect(self.printToGui)
        # global_ms.prepared_print.connect(self.printToGui)

    def printToGui(self, fb, text):
        fb.append(str(text))
        fb.ensureCursorVisible()

    def addOneHeader(self):
        addRowNumber = self.ui.headerstable.currentRow()+1
        self.ui.headerstable.insertRow(addRowNumber)

    def delOneHeader(self):
        self.ui.headerstable.removeRow(
             self.ui.headerstable.currentRow()
        )

    def sendRequest(self):
        method = self.ui.comboBox_type.currentText()
        url = self.ui.lineEdit.text()
        payload = self.ui.textEdit.toPlainText()
        # print(method, url, payload)
        headers = {}
        ht = self.ui.headerstable
        for row in range(ht.rowCount()):
            k = ht.item(row, 0).text()
            v = ht.item(row, 1).text()
            if k.strip() == '':
                continue
            headers[k] = v

        req = requests.Request(method, url, headers=headers, data=payload)
        prepared = req.prepare()
        self.pretty_print_request(prepared)
        s = requests.Session()
        thread = Thread(target=self.newThreadFunc, args=(s, prepared))
        thread.start()

    def newThreadFunc(self, s, perpared):
        try:
            r = s.send(perpared)
            self.pretty_print_response(r)
        except:
            self.ui.textBrowser_info.append(traceback.format_exc())

    def pretty_print_request(self, prepared):
        print(prepared.headers, prepared.body)
        global_ms.text_print.emit(self.ui.textBrowser_info,
                 '发送\n' + str(prepared.headers) +'\n' + str(prepared.body))
        # self.ui.textBrowser_info.append(prepared)

    def pretty_print_response(self, r):
        # self.ui.textBrowser_info.append("------- 发送完成：-------\n")
        global_ms.text_print.emit(self.ui.textBrowser_info, '返回\n' + str(r.json()))
        print(r.json())


if __name__ == "__main__":
    app = QApplication([])
    app.setWindowIcon(QIcon('logo.png'))
    widget = main()
    widget.show()
    sys.exit(app.exec_())
