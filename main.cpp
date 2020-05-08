#include "AppMainWin.hpp"
#include "LogMessage.hpp"
#include <QApplication>
#include <QTranslator>
#include <QFile>

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

    //加载样式文件
    QFile qssFile(":/resourcesFile/StyleSheet.qss");
    qssFile.open(QFile::ReadOnly);
    qApp->setStyleSheet(qssFile.readAll());
    qssFile.close();

    AppMainWin appInstance;
    appInstance.show();
    return a.exec();
}
