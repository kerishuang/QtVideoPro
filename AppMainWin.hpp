#ifndef APPMAINWIN_HPP
#define APPMAINWIN_HPP

#include <QWidget>

class AppMainWin : public QWidget
{
    Q_OBJECT

public:
    AppMainWin(QWidget *parent = nullptr);
    ~AppMainWin();
};
#endif // APPMAINWIN_HPP
