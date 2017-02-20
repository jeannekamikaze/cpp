TEMPLATE = lib
CONFIG += shared plugin
CONFIG -= qt

CONFIG(release, debug|release) {
    DESTDIR=$$(SRC)/build/release
    OBJECTS_DIR=$$(SRC)/.obj/release/$$TARGET
}
else {
    DESTDIR=$$(SRC)/build/debug
    OBJECTS_DIR=$$(SRC)/.obj/debug/$$TARGET
}

QMAKE_CXXFLAGS_DEBUG += -DDEBUG
unix: {
    QMAKE_CXXFLAGS += --std=c++11
}
win32: {
    QMAKE_CXXFLAGS += -DNOMINMAX
    QMAKE_CXXFLAGS_DEBUG += /Zi
    QMAKE_LFLAGS_DEBUG += /DEBUG
}

INCLUDEPATH = include $$(SRC)/include
DEPENDPATH = include $$(SRC)/include

HEADERS += \
    include/cpp/debug.h \
    include/cpp/Exception.h \
    include/cpp/NonCopyable.h \
    include/cpp/NonMovable.h \
    include/cpp/types.h \
    include/cpp/unique.h

SOURCES += src/Exception.cc
