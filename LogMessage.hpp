#ifndef LOGMESSAGE_HPP
#define LOGMESSAGE_HPP
#include <QMessageLogContext>
#include <QString>
#include <QMutex>
#include <QtGlobal>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QApplication>


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 加锁
    static QMutex mutex;
    mutex.lock();

    QByteArray localMsg = msg.toLocal8Bit();

    QString strMsg("");
    switch(type)
    {
    case QtDebugMsg:
        strMsg = QString("Debug:");
        break;
    case QtWarningMsg:
        strMsg = QString("Warning:");
        break;
    case QtInfoMsg:
        strMsg = QString("Info:");
        break;
    case QtCriticalMsg:
        strMsg = QString("Critical:");
        break;
    case QtFatalMsg:
        strMsg = QString("Fatal:");
        break;
    default:
        strMsg = QString("Unknown:");
        break;
    }

    // 设置输出信息格式
    QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");

    QString strMessage = QString("Message:%1 File:%2  Line:%3  Function:%4  DateTime:%5")
            .arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function).arg(strDateTime);

    // 输出信息至文件中（读写、追加形式）
    QString FILE_NAME = QCoreApplication::applicationDirPath() + QString("/log.txt");
    QFile logFile(FILE_NAME);

    if(logFile.size() > 100 * 1024) {
        QFile::remove(FILE_NAME);
    }

    logFile.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&logFile);
    stream << strMessage << "\r\n";
    logFile.flush();
    logFile.close();

    // 解锁
    mutex.unlock();
}


#endif // LOGMESSAGE_HPP
