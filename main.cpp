#include "AppMainWin.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppMainWin appInstance;
    appInstance.show();
    return a.exec();
}
