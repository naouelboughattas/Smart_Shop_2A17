#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql printsupport widgets network multimedia multimediawidgets serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyProj
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    QrCode.cpp \
    arduino.cpp \
    categorie.cpp \
    depot.cpp \
    evenement.cpp \
    exportexcelobjet.cpp \
    facture.cpp \
        main.cpp \
    connection.cpp \
    mainwindow.cpp \
    produit.cpp \
    qcustomplot.cpp \
    smtp.cpp \
    stock.cpp

HEADERS += \
    QrCode.hpp \
    arduino.h \
    categorie.h \
    depot.h \
    evenement.h \
    exportexcelobjet.h \
    facture.h \
    connection.h \
    mainwindow.h \
    produit.h \
    qcustomplot.h \
    smtp.h \
    stock.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES +=
