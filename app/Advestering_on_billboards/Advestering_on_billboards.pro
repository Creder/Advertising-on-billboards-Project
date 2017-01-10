#-------------------------------------------------
#
# Project created by QtCreator 2016-08-06T19:40:11
#
#-------------------------------------------------

QT       += core gui xml sql webenginewidgets webchannel

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Advestering_on_billboards
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    databaseservice.cpp \
    image_view.cpp \
    mapview.cpp

HEADERS  += mainwindow.h \
    databaseservice.h \
    image_view.h \
    mapview.h

FORMS    += mainwindow.ui \
    image_view.ui

DISTFILES += \
    map.html

