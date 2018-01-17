QT += core
QT -= gui

CONFIG += c++11

TARGET = GPSSaviour
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += include/
INCLUDEPATH += test/

SOURCES += main.cpp \
    src/GeoData.cpp

HEADERS += \
    include/catch.hpp \
    include/GeoData.h

DISTFILES += \
    GPSSaviour.pro.user.18 \
    docs/CPP_Styleguide.md
