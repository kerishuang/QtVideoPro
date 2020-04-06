#include "appMainWin.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    appMainWin w;
    w.show();
    return a.exec();
}
