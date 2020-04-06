#ifndef APPMAINWIN_HPP
#define APPMAINWIN_HPP

#include <QWidget>

class appMainWin : public QWidget
{
    Q_OBJECT

public:
    appMainWin(QWidget *parent = nullptr);
    ~appMainWin();
};
#endif // APPMAINWIN_HPP
