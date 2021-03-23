TEMPLATE = lib
CONFIG += staticlib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../libs

HEADERS = ../../../../../../../../third_party/cJSON/cJSON.h
SOURCES += \
        ../../../../../../../../third_party/cJSON/cJSON.c
