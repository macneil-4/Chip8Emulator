TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    chip8.c \
    display.c

HEADERS += \
    chip8.h \
    display.h

DISTFILES += \
    test.txt \
    opcodes.txt

LIBS += -lSDL2main -lSDL2
