INCLUDEPATH *= $$PWD/..
LIBS *= -L$$IDE_LIBRARY_PATH -l$$qtLibraryName(Botan)
win32 {
    DEFINES += BOTAN_DLL=""
    LIBS += -ladvapi32 -luser32
}
