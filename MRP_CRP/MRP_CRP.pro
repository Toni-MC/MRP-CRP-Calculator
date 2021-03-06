QT       += core gui
QMAKE_LFLAGS += -static
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    crp.cpp \
    dp.cpp \
    global.cpp \
    lpplp.cpp \
    main.cpp \
    mrp.cpp \
    nb.cpp \
    nnp.cpp \
    outputcsv.cpp \
    rpp.cpp \
    rpplp.cpp

HEADERS += \
    crp.h \
    dp.h \
    global.h \
    lpplp.h \
    mrp.h \
    nb.h \
    nnp.h \
    outputcsv.h \
    rpp.h \
    rpplp.h

FORMS += \
    crp.ui \
    mrp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icono.qrc
