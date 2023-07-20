#include "mainwindow.h"
#include <QApplication>
#include "ttysend.h"
#include "timebilbord.h"
#include <thread>
#include <chrono>
#include <numeric>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //ttySend k;
    //k.openttk()

    //std::thread ttySendRecv( ...
    //если получится дальше работать с китайским biblord
    // не забыть. в планах. 1 поток - сеть. общение с утройсвом. 2 поток с gui и guievent общий ресурс у них будет очередь
    // ей можно mutex добавить



;

    return a.exec();
}
