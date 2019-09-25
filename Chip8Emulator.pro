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

LIBS += -L/usr/lib/x86_64-linux-gnu -lSDL2
INCLUDEPATH += /usr/lib/x86_64-linux-gnu
