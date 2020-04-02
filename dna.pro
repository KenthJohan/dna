TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

VPATH +=
SOURCES += dna.c

INCLUDEPATH += $$PWD/csc
INCLUDEPATH += $$PWD/iup-3.28_Win64_mingw6_lib/include
INCLUDEPATH += $$PWD/cd-5.12_Win64_mingw6_lib/include
HEADERS += $$PWD/iup-3.28_Win64_mingw6_lib/include/iup.h
HEADERS += $$PWD/iup-3.28_Win64_mingw6_lib/include/cd.h
LIBS += -L$$PWD/iup-3.28_Win64_mingw6_lib
LIBS += -L$$PWD/cd-5.12_Win64_mingw6_lib
LIBS += -liup -liupcontrols -liupcd -lcd -lcdim -lcdgl -liupimglib -lfreetype6 -lz -lkernel32 -luser32 -lgdi32 -lwinspool -lcomdlg32 -ladvapi32 -lshell32 -lole32 -loleaut32 -luuid -lcomctl32

