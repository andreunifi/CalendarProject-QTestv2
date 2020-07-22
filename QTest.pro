QT += testlib
QT -= gui
INCLUDEPATH += D:\Qt\QtCreatorDocuments\QTest

HEADERS += Date.h
HEADERS += Activity.h
HEADERS += Registro.h
SOURCES += Activity.cpp
SOURCES += Registro.cpp
SOURCES += Date.cpp

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
TEMPLATE = app
SOURCES +=  tst_calendartests.cpp
