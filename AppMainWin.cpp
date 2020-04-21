#include "AppMainWin.hpp"
#include <QDebug>

AppMainWin::AppMainWin(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("my video project"));
    qDebug()<<"start AppMainWin";
}

AppMainWin::~AppMainWin()
{
}

