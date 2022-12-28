QT       += core gui
QT       += sql
QT       += network
QT       += core gui printsupport
QT       += charts
QT       += multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT_CHARTS_USE_NAMESPACE
TARGET      = BasePlatformFrame
TEMPLATE    = app
MOC_DIR     = temp/moc
RCC_DIR     = temp/rcc
UI_DIR      = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR     = $$PWD/../bin

SOURCES     += main.cpp \
    creditsql.cpp \
    dlg_add.cpp \
    dlg_add_user.cpp \
    rtsql.cpp \
    sonsql.cpp \
    user-win-dialog.cpp
SOURCES     += iconhelper.cpp
SOURCES     += appinit.cpp
SOURCES     += UIBasePlatformFrame.cpp

HEADERS     += iconhelper.h \
    creditsql.h \
    dlg_add.h \
    dlg_add_user.h \
    rtsql.h \
    sonsql.h \
    user-win-dialog.h
HEADERS     += appinit.h
HEADERS     += UIBasePlatformFrame.h

FORMS       += UIBasePlatformFrame.ui \
    dlg_add.ui \
    dlg_add_user.ui \
    user-win-dialog.ui

RESOURCES   += main.qrc
RESOURCES   += qss.qrc
CONFIG      += qt warn_off
INCLUDEPATH += $$PWD
