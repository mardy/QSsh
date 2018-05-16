INCLUDEPATH *= $$PWD/..
LIBS *= -L$$IDE_LIBRARY_PATH -l$$qtLibraryName(Botan)
LIBS += -ladvapi32 -luser32
