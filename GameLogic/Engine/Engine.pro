#-------------------------------------------------
#
# Project created by QtCreator 2018-07-12T13:57:43
#
#-------------------------------------------------

QT       -= gui

TARGET = Engine
TEMPLATE = lib
CONFIG += staticlib c++14

SOURCES += \
    gameexception.cpp \
    formatexception.cpp \
    illegalmoveexception.cpp \
    ioexception.cpp \
    actorfactory.cpp \
    piecefactory.cpp \
    gameengine.cpp \
    initialize.cpp \
    hex.cpp \
    pawn.cpp \
    actor.cpp \
    vehicle.cpp

HEADERS += \
    gameexception.hh \
    formatexception.hh \
    illegalmoveexception.hh \
    ioexception.hh \
    actorfactory.hh \
    piecefactory.hh \
    cubecoordinate.hh \
    gameengine.hh \
    initialize.hh \
    hex.hh \
    pawn.hh \
    igameboard.hh \
    igamerunner.hh \
    igamestate.hh \
    iplayer.hh \
    actor.hh \
    vehicle.hh

unix {
    target.path = /usr/lib
    INSTALLS += target
}
