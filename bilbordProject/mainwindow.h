#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QTextEdit>

#include "queue"
#include <string.h>
#include <iostream>
#include "qstring.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    static char textBuffer[255];
    static QString textLineBuffer;

    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void ListReport(std::string mess, int num);
    void addQueueList(int a);

    QAction *actionnew_point;
    QAction *actionexit;
    QAction *actionFAQ;
    QWidget *centralwidget;
    //QWidget *horizontalLayoutWidget;
    QWidget *verticalLayoutWidget;
    QHBoxLayout *horizontalLayout_1;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_1;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QListWidget *listView;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menumenu;
    QTextEdit *textEdit;




private:
    void setupUi(QMainWindow *MainWindow);
    void retranslateUi(QMainWindow *MainWindow);




private slots:

    void ttyevent0();
    void ttyevent1();
    void ttyevent2();
    void ttyevent3();
    void ttyevent4();
    void ttyevent5();
    void ttyevent6();
    void ttyevent7();
    void ttyevent8();
    void ttyevent9();
    void ttyeventMessegeEnter();

};




int getQueueList();
bool isEmptyQueueList();
static std::queue<int> MessegeList;
#endif // MAINWINDOW_H
