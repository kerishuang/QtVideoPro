QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_MESSAGELOGCONTEXT

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#将编译生成的moc,obj,ui，以及资源文件提取出来，作为一个文件夹，放在生成目录的文件夹下，而不是一起混在debug/release文件夹中
MOC_DIR = $${OUT_PWD}/moc
OBJECTS_DIR = $${OUT_PWD}/obj
UI_DIR = $${OUT_PWD}/ui
RCC_DIR = $${OUT_PWD}/rc


SOURCES += \
    main.cpp \
    AppMainWin.cpp

HEADERS += \
    LogMessage.hpp \
    AppMainWin.hpp


#国际化工作，每一个ts文件代表一种国际化语言，文件名可以随便取，不过规范是以某种语言的简写为末尾，作为文件名
#翻译文件放在工程目录下，当然也可以用资源的方式进行加载，来调用
TRANSLATIONS = QtVideoPro_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
