TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    chip8.c

HEADERS += \
    chip8.h

DISTFILES += \
    test.txt
