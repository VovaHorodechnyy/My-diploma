#-------------------------------------------------
#
# Project created by QtCreator 2018-12-22T13:16:58
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = My_exam
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
        main.cpp \
        mainwindow.cpp \
    curlbuilder.cpp \
    itemselected.cpp \
    cbigad.cpp \
    favorites.cpp \
    mylistwidget.cpp \
    chistory.cpp \
    cloadingscreen.cpp

HEADERS += \
        mainwindow.h \
    kp_tree.h \
    parse.h \
    cadhome.h \
    cparser.h \
    my_trim.h \
    curlbuilder.h \
    itemselected.h \
    cbigad.h \
    cfavoritead.h \
    favorites.h \
    mylistwidget.h \
    chistory.h \
    cloadingscreen.h

FORMS += \
        mainwindow.ui \
    itemselected.ui \
    favorites.ui \
    chistory.ui \
    cloadingscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
