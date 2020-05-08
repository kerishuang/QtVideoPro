#ifndef APPMAINWIN_HPP
#define APPMAINWIN_HPP

#include <QWidget>
#include <QSettings>
#include <QPushButton>

class AppMainWin : public QWidget
{
    Q_OBJECT

public:
    AppMainWin(QWidget *parent = nullptr);
    ~AppMainWin();
    static AppMainWin* getAppMainWinInstance();



private:
    //静态成员变量，用以全局
    static AppMainWin* AppMainWinInstance;

    //测试按钮
    QPushButton testBtn;
};

//添加全局变量
AppMainWin* getAppInstance();
#endif // APPMAINWIN_HPP
