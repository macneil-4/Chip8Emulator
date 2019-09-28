TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    chip8.c \
    display.c \
    keyboard.c

HEADERS += \
    chip8.h \
    display.h \
    keyboard.h \
    defs.h

DISTFILES += \
    test.txt \
    opcodes.txt

LIBS += -L/usr/lib/x86_64-linux-gnu -lSDL2
INCLUDEPATH += /usr/lib/x86_64-linux-gnu
