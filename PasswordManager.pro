QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = Icon.ico

SOURCES += \
    addobject.cpp \
    editobject.cpp \
    filemanager.cpp \
    main.cpp \
    mainwindow.cpp \
    passwordentry.cpp \
    passwordgenerator.cpp \
    passwordmanager.cpp

HEADERS += \
    addobject.h \
    editobject.h \
    filemanager.h \
    mainwindow.h \
    passwordentry.h \
    passwordgenerator.h \
    passwordmanager.h

FORMS += \
    addobject.ui \
    editobject.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
