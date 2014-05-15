#-------------------------------------------------
#
# Project created by QtCreator 2014-04-02T18:36:35
#
#-------------------------------------------------

QT       += core gui sql svg

TARGET = catalog
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    basemanager.cpp \
    dialog.cpp \
    companydialog.cpp \
    categorymodel.cpp \
    subcategorymodel.cpp \
    companymodel.cpp

HEADERS  += mainwindow.h \
    basemanager.h \
    dialog.h \
    companydialog.h \
    categorymodel.h \
    subcategorymodel.h \
    companymodel.h

FORMS    += mainwindow.ui \
    dialog.ui \
    companydialog.ui

RESOURCES += \
    resource.qrc

TRANSLATIONS += \
        translat_ua.ts

windows:RC_FILE = icons/icon.rc
