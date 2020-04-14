#include "AppMainWin.hpp"
#include "LogMessage.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    #ifndef QT_DEBUG
        qInstallMessageHandler(myMessageOutput);
    #endif
    QApplication a(argc, argv);
    AppMainWin appInstance;
    appInstance.show();
    return a.exec();
}
