#include "AppMainWin.hpp"
#include <QDebug>


QSettings g_setting(QString("HWK"),QString("QtVideoPro"));

AppMainWin* AppMainWin::AppMainWinInstance = nullptr;
//全局变量函数，贯穿整个程序的类
AppMainWin* getAppInstance()
{
    return AppMainWin::getAppMainWinInstance();
    //也可以不用getAppMainWinInstance(),直接return AppMainWin::AppMainWinInstance;但AppMainWinInstance得是公有变量

}

AppMainWin::AppMainWin(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<<"==========start AppMainWin===============";
    AppMainWinInstance = this;
    setWindowTitle(tr("my video project"));

    //测试按钮
    testBtn.setParent(this);
    testBtn.setObjectName("testBtn");
    testBtn.setText("testBtn");
    testBtn.setFixedSize(50,20);
    testBtn.move(100,100);

}

AppMainWin::~AppMainWin()
{
    qDebug()<<"-----------end AppMainWin---------------";
    //清理工作
    AppMainWinInstance = nullptr;
}

AppMainWin *AppMainWin::getAppMainWinInstance()
{
    return AppMainWinInstance;
}


