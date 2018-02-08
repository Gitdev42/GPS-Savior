QT += core
QT -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = GPSSaviour
CONFIG += console
CONFIG -= app_bundle

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

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
    test/NeedyClientTest.cpp \
    src/GSMPackage.cpp \
    test/TestBuffer.cpp \
    test/GSMAgentTest.cpp

HEADERS += \
    include/catch.hpp \
    include/GeoData.h \
    include/NeedyClient.h \
    include/GPSAgent.h \
    include/GSMAgent.h \
    include/GSMPackage.h \
    include/Types.h \
    test/TestBuffer.h

