QT       += core gui  sql\
         multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fuelitem.cpp \
    gameover.cpp \
    heliitem.cpp \
    highscore.cpp \
    main.cpp \
    mainwindow.cpp \
    newwindow.cpp \
    pillaritem.cpp \
    scene.cpp

HEADERS += \
    fuelitem.h \
    gameover.h \
    heliitem.h \
    highscore.h \
    mainwindow.h \
    newwindow.h \
    pillaritem.h \
    scene.h

FORMS += \
    gameover.ui \
    highscore.ui \
    mainwindow.ui \
    newwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
