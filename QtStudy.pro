#-------------------------------------------------
#
# Project created by QtCreator 2017-07-14T14:22:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtStudy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    customwidget.cpp

HEADERS  += mainwindow.h \
    customwidget.h \
    enumdefine.h


FORMS +=  \
    ui/mainwindow.ui \


include($$PWD/QtWidgetStudy/QtWidgetStudy.pri)
include($$PWD/CustomWidget/CustomWidget.pri)
