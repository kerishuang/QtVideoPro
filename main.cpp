#include "AppMainWin.hpp"
#include "LogMessage.hpp"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    #ifndef QT_DEBUG
        qInstallMessageHandler(myMessageOutput);
    #endif

    QApplication a(argc, argv);

    QTranslator translator;
    //翻译文件是放在工程目录下，也可以用资源的方式来操作
    translator.load("../QtVideoPro/QtVideoPro_zh_CN.qm");
    a.installTranslator(&translator);

    AppMainWin appInstance;
    appInstance.show();
    return a.exec();
}
