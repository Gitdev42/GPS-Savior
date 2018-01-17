QT += core
QT -= gui

CONFIG += c++11

TARGET = GPSSaviour
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    src/NeedyClient.cpp \
    src/GPSAgent.cpp \
    src/GPSData.cpp \
    src/GSMAgent.cpp \

HEADERS += \
    include/catch.hpp \
    include/GPSData.h \
    include/NeedyClient.h \
    include/GPSAgent.h \
    include/GSMAgent.h \
