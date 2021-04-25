QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       += core gui printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    depot.cpp \
    main.cpp \
    stock.cpp \
    zeinebwindow.cpp

HEADERS += \
    connexion.h \
    depot.h \
    stock.h \
    zeinebwindow.h

FORMS += \
    zeinebwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MyResources.qrc
