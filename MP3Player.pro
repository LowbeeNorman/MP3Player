QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    home.cpp \
    library.cpp \
    main.cpp \
    mainwindow.cpp \
    menubar.cpp \
    music.cpp \
    playbar.cpp \
    playlistbutton.cpp

HEADERS += \
    bass24/c/bass.h \
    home.h \
    library.h \
    mainwindow.h \
    menubar.h \
    music.h \
    playbar.h \
    playlistbutton.h

FORMS += \
    home.ui \
    library.ui \
    mainwindow.ui \
    menubar.ui \
    playbar.ui \
    playlistbutton.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    defaultPlaylistPicture.qrc




unix|win32: LIBS += -L$$PWD/bass24/c/x64/ -lbass

INCLUDEPATH += $$PWD/bass24/c/x64
DEPENDPATH += $$PWD/bass24/c/x64

DISTFILES += \
    songs/file_example_MP3_1MG.mp3
