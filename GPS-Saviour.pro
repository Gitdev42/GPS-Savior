QT += core
QT -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = GPSSaviour
CONFIG += console
CONFIG -= app_bundle

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

TEMPLATE = app

INCLUDEPATH += GPS-Saviour/include/
INCLUDEPATH += GPS-Saviour/test/

HEADERS += \
    GPS-Saviour/include/catch.hpp \
    GPS-Saviour/include/GeoData.h \
    GPS-Saviour/include/GPSAgent.h \
    GPS-Saviour/include/GSMAgent.h \
    GPS-Saviour/include/GSMPackage.h \
    GPS-Saviour/include/NeedyClient.h \
    GPS-Saviour/include/SaviourClient.h \
    GPS-Saviour/include/Types.h \
    GPS-Saviour/test/TestBuffer.h \
    GPS-Saviour/include/Timer.h

SOURCES += \
    GPS-Saviour/src/GeoData.cpp \
    GPS-Saviour/src/GPSAgent.cpp \
    GPS-Saviour/src/GSMAgent.cpp \
    GPS-Saviour/src/GSMPackage.cpp \
    GPS-Saviour/src/NeedyClient.cpp \
    GPS-Saviour/src/SaviourClient.cpp \
    GPS-Saviour/test/GPSAgentTest.cpp \
    GPS-Saviour/test/GSMAgentTest.cpp \
    GPS-Saviour/test/NeedyClientTest.cpp \
    GPS-Saviour/test/SaviourClientTest.cpp \
    GPS-Saviour/test/TestBuffer.cpp \
    GPS-Saviour/main.cpp \
    GPS-Saviour/src/Timer.cpp \
    GPS-Saviour/test/TimerTest.cpp


