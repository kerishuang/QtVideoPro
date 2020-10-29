#include "AppMainWin.hpp"
#include <QDebug>

//也可放在main函数前，都是全局的配置文件变量
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
    setFixedSize(720,500);
    //变量逻辑
    _layout = new QVBoxLayout;
    _firstHBoxlayout = new QHBoxLayout;

    InitButton();
    InitWin();

    //connect logic
    connect(&openFileAndPlay,&QPushButton::clicked,this,&AppMainWin::openFileAndPlaySlot);

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

void AppMainWin::openFileAndPlaySlot()
{
    qDebug()<<"come in openFileAndPlaySlot";
}

void AppMainWin::InitWin()
{
    _firstHBoxlayout->addWidget(&testBtn);
    _firstHBoxlayout->addWidget(&openFileAndPlay);

    _layout->addLayout(_firstHBoxlayout);
    setLayout(_layout);
}

void AppMainWin::InitButton()
{
    //测试按钮
    //testBtn.setParent(this);
    testBtn.setObjectName("testBtn");
    testBtn.setText("testBtn");
    //testBtn.setFixedSize(50,20);
    //testBtn.move(100,100);
    //打开本地视频文件并播放按钮
    openFileAndPlay.setObjectName("openFileAndPlayBtn");
    openFileAndPlay.setText(tr("openFileAndPlayBtn"));


}


