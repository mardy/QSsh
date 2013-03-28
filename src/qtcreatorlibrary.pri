include(../qssh.pri)

win32 {
    DLLDESTDIR = $$IDE_APP_PATH
}

DESTDIR = $$IDE_LIBRARY_PATH

include(rpath.pri)

TARGET = $$qtLibraryName($$TARGET)

TEMPLATE = lib
CONFIG += shared dll

contains(QT_CONFIG, reduce_exports):CONFIG += hide_symbols

!macx {
    win32 {
        dlltarget.path = $$QTC_PREFIX/bin
        INSTALLS += dlltarget
    } else {
        target.path = $$QTC_PREFIX/$$IDE_LIBRARY_BASENAME/qtcreator
        INSTALLS += target
    }
}
