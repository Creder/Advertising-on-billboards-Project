#-------------------------------------------------
#
# Project created by QtCreator 2016-08-06T19:40:11
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Advestering_on_billboards
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    databaseservice.cpp

HEADERS  += mainwindow.h \
    databaseservice.h

FORMS    += mainwindow.ui

