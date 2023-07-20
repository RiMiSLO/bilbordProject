#include "mainwindow.h"
#include "ttysend.h"
#include "timebilbord.h"
#include <qstring.h>
#include <qabstractitemview.h>

static int clickCount;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setupUi(this);

}

MainWindow::~MainWindow()
{

}

void MainWindow::setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        //MainWindow->resize(1027, 860);
        MainWindow->setMaximumSize(1010,860);
        MainWindow->setMinimumSize(1010, 860);

        actionnew_point = new QAction(MainWindow);
        actionnew_point->setObjectName(QStringLiteral("actionnew_point"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        actionFAQ = new QAction(MainWindow);
        actionFAQ->setObjectName(QStringLiteral("actionFAQ"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 1001, 571));
        verticalLayout_1 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_1->setObjectName(QStringLiteral("verticalLayout_1"));
        verticalLayout_1->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_1 = new QHBoxLayout(verticalLayoutWidget);
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));
        horizontalLayout_1->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(ttyevent0()));

        verticalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QObject::connect(pushButton_2, SIGNAL(clicked()), this, SLOT(ttyevent1()));

        verticalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QObject::connect(pushButton_3, SIGNAL(clicked()), this, SLOT(ttyevent2()));

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QObject::connect(pushButton_4, SIGNAL(clicked()), this, SLOT(ttyevent3()));

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        QObject::connect(pushButton_5, SIGNAL(clicked()), this, SLOT(ttyevent4()));

        verticalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        QObject::connect(pushButton_6, SIGNAL(clicked()), this, SLOT(ttyevent5()));

        verticalLayout_3->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(verticalLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        QObject::connect(pushButton_7, SIGNAL(clicked()), this, SLOT(ttyevent6()));

        verticalLayout_3->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(verticalLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        QObject::connect(pushButton_8, SIGNAL(clicked()), this, SLOT(ttyevent7()));

        verticalLayout_3->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(verticalLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        QObject::connect(pushButton_9, SIGNAL(clicked()), this, SLOT(ttyevent8()));

        verticalLayout_3->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(verticalLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        QObject::connect(pushButton_10, SIGNAL(clicked()), this, SLOT(ttyevent9()));

        verticalLayout_3->addWidget(pushButton_10);
        horizontalLayout_1->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
//        pushButton_14 = new QPushButton(verticalLayoutWidget);
//        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

//        verticalLayout_2->addWidget(pushButton_14);

//        pushButton_18 = new QPushButton(verticalLayoutWidget);
//        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));

//        verticalLayout_2->addWidget(pushButton_18);

//        pushButton_17 = new QPushButton(verticalLayoutWidget);
//        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

//        verticalLayout_2->addWidget(pushButton_17);

//        pushButton_12 = new QPushButton(verticalLayoutWidget);
//        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

//        verticalLayout_2->addWidget(pushButton_12);

//        pushButton_11 = new QPushButton(verticalLayoutWidget);
//        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

//        verticalLayout_2->addWidget(pushButton_11);

//        pushButton_19 = new QPushButton(verticalLayoutWidget);
//        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));

//        verticalLayout_2->addWidget(pushButton_19);

//        pushButton_16 = new QPushButton(verticalLayoutWidget);
//        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

//        verticalLayout_2->addWidget(pushButton_16);

//        pushButton_15 = new QPushButton(verticalLayoutWidget);
//        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

//        verticalLayout_2->addWidget(pushButton_15);

//        pushButton_13 = new QPushButton(verticalLayoutWidget);
//        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

//        verticalLayout_2->addWidget(pushButton_13);

//        pushButton_20 = new QPushButton(verticalLayoutWidget);
//        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));

//        verticalLayout_2->addWidget(pushButton_20);

        horizontalLayout_1->addLayout(verticalLayout_2);
        verticalLayout_1->addLayout(horizontalLayout_1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(textEdit);

        pushButton_21 = new QPushButton(verticalLayoutWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_21->sizePolicy().hasHeightForWidth());
        pushButton_21->setSizePolicy(sizePolicy1);
        QObject::connect(pushButton_21, SIGNAL(clicked()), this, SLOT(ttyeventMessegeEnter()));

        horizontalLayout_4->addWidget(pushButton_21);
        verticalLayout_1->addLayout(horizontalLayout_4);

        listView = new QListWidget(centralwidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, 600, 1011, 192));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1027, 30));
        menumenu = new QMenu(menubar);
        menumenu->setObjectName(QStringLiteral("menumenu"));
        MainWindow->setMenuBar(menubar);

        //menubar->addAction(menumenu->menuAction());
        //menumenu->addSeparator();
        //menumenu->addAction(actionnew_point);
        //menumenu->addAction(actionexit);
        //menumenu->addAction(actionFAQ);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

  void MainWindow::retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Bilbord", Q_NULLPTR));
        actionnew_point->setText(QApplication::translate("MainWindow", "new point", Q_NULLPTR));
        actionexit->setText(QApplication::translate("MainWindow", "exit", Q_NULLPTR));
        actionFAQ->setText(QApplication::translate("MainWindow", "FAQ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
//        pushButton_14->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
//        pushButton_18->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
//        pushButton_17->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
//        pushButton_12->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
//        pushButton_11->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
//        pushButton_19->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
//        pushButton_16->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
//        pushButton_15->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
//        pushButton_13->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
//        pushButton_20->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("MainWindow", "Submit", Q_NULLPTR));
        menumenu->setTitle(QApplication::translate("MainWindow", "me&nu", Q_NULLPTR));
    } // retranslateUi

  void MainWindow::ttyevent0(){
        //ttySend k;
        //        if(k.openttk(1)<0){
        //            ListReport(getTime()+" !--Error--! ", 1);
        //            return;
        //        }
        //std::cout << "Current Time and Date: " << getTime()<< std::endl;
        addQueueList(1);
        ListReport(getTime(), 1);
        return;
  }

  void MainWindow::ttyevent1(){

//        ttySend k;
//        if(k.openttk(2)<0){
//            ListReport(getTime()+" !--Error--! ", 2);
//            return;
//        }
        addQueueList(2);
        ListReport(getTime(), 2);
        return;
  }

  void MainWindow::ttyevent2(){
//        ttySend k;
//        if(k.openttk(3)<0){
//            ListReport(getTime()+" !--Error--! ", 3);
//            return;
//        }
        addQueueList(3);
        ListReport(getTime(), 3);
        return;
  }

  void MainWindow::ttyevent3(){
//      ttySend k;
//      if(k.openttk(4)<0){
//          ListReport(getTime()+" !--Error--! ", 4);
//          return;
//      }
      addQueueList(4);
      ListReport(getTime(), 4);
      return;
  }

  void MainWindow::ttyevent4(){
//        ttySend k;
//        if(k.openttk(5)<0){
//            ListReport(getTime()+" !--Error--! ", 5);
//            return;
//        }
        addQueueList(5);
        ListReport(getTime(), 5);
        return;
  }

  void MainWindow::ttyevent5(){
//      ttySend k;
//      if(k.openttk(6)<0){
//          ListReport(getTime()+" !--Error--! ", 6);
//          return;
//      }
      addQueueList(6);
      ListReport(getTime(), 6);
        return;
  }

  void MainWindow::ttyevent6(){
//      ttySend k;
//      if(k.openttk(7)<0){
//          ListReport(getTime()+" !--Error--! ", 7);
//          return;
//      }
      addQueueList(7);
      ListReport(getTime(), 7);
        return;
  }

  void MainWindow::ttyevent7(){
//      ttySend k;
//      if(k.openttk(8)<0){
//          ListReport(getTime()+" !--Error--! ", 8);
//          return;
//      }
      addQueueList(8);
      ListReport(getTime(), 8);
        return;
  }

  void MainWindow::ttyevent8(){
//      ttySend k;
//      if(k.openttk(9)<0){
//          ListReport(getTime()+" !--Error--! ", 9);
//          return;
//      }
      addQueueList(9);
      ListReport(getTime(), 9);
      return;
  }

  void MainWindow::ttyevent9(){
//      ttySend k;
//      if(k.openttk(10)<0){
//          ListReport(getTime()+" !--Error--! ", 10);
//          return;
//      }
      addQueueList(10);
      ListReport(getTime(), 10);
        return;
  }

  void MainWindow::ttyeventMessegeEnter(){
      textLineBuffer = textEdit->toPlainText();
      ListReport(getTime()+textLineBuffer.toStdString(), 10);
      textEdit->clear();
      return;
  }

  void MainWindow::addQueueList(int a){
      MessegeList.push(a);
      return;
  }

  int getQueueList(){
      int a;
      a=MessegeList.front();
      MessegeList.pop();
      return a;
  }

  bool isEmptyQueueList(){ // если true - пустая очередь
      return MessegeList.empty();
  }

  void MainWindow::ListReport(std::string mess, int num){
      //QString tempA = " pic: "+ num + tempB;
      QString tempA = QString::fromLatin1("Picter number : %1, Time: ").arg(num);
      QString tempB = QString::fromStdString(mess)+QString::fromLatin1("[ %1 ]").arg(clickCount);
      tempA +=tempB;
      clickCount++;
      listView->addItem(tempA);
      listView->scrollToItem(listView->item(listView->count()-1));
      if((listView->count())>=255){
              listView->clear();
      }
      return;

  }
