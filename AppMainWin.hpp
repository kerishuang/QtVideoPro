#ifndef APPMAINWIN_HPP
#define APPMAINWIN_HPP

#include <QWidget>
#include <QSettings>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class AppMainWin : public QWidget
{
    Q_OBJECT

public:
    AppMainWin(QWidget *parent = nullptr);
    ~AppMainWin();
    static AppMainWin* getAppMainWinInstance();

public slots:

protected:

private slots:
    void openFileAndPlaySlot();


private:
    void InitWin();
    void InitButton();

private:
    //静态成员变量，用以全局
    static AppMainWin* AppMainWinInstance;

    //最大的布局
    QVBoxLayout*        _layout = nullptr;

    //第一行的水平布局
    QHBoxLayout*        _firstHBoxlayout = nullptr;


    //********************按钮*************************
    //测试按钮
    QPushButton testBtn;
    //打开本地视频文件并播放按钮
    QPushButton openFileAndPlay;
    //********************按钮*************************

};

//添加全局变量
AppMainWin* getAppInstance();
#endif // APPMAINWIN_HPP
