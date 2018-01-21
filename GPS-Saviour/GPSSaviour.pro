QT += core
QT -= gui

CONFIG += c++11

TARGET = GPSSaviour
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += include/
INCLUDEPATH += test/

SOURCES += \
    main.cpp \
    src/NeedyClient.cpp \
    src/GPSAgent.cpp \
    src/GeoData.cpp \
    src/GSMAgent.cpp \
    test/GPSAgentTest.cpp \
    test/NeedyClientTest.cpp

HEADERS += \
    include/catch.hpp \
    include/GeoData.h \
    include/NeedyClient.h \
    include/GPSAgent.h \
    include/GSMAgent.h \

