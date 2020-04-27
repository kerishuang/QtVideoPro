#include "AppMainWin.hpp"
#include <QDebug>

AppMainWin* AppMainWinInstance = nullptr;
//全局变量函数，贯穿整个程序的类
AppMainWin* getAppInstance()
{
    return AppMainWin::getAppMainWinInstance();
    //也可以不用getAppMainWinInstance(),直接return AppMainWin::AppMainWinInstance;但AppMainWinInstance得是公有变量
}

AppMainWin::AppMainWin(QWidget *parent)
    : QWidget(parent)
{
    AppMainWinInstance = this;
    setWindowTitle(tr("my video project"));
    qDebug()<<"start AppMainWin";
}

AppMainWin::~AppMainWin()
{
    //清理工作
    AppMainWinInstance = nullptr;
}

AppMainWin *AppMainWin::getAppMainWinInstance()
{
    return AppMainWinInstance;
}

