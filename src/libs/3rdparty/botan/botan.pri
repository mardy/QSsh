INCLUDEPATH *= $$PWD/..
LIBS *= -L$$IDE_LIBRARY_PATH -l$$qtLibraryName(Botan)
win32:LIBS += -ladvapi32 -luser32
