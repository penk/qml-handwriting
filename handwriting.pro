QT += gui quick qml

TEMPLATE = app
TARGET = qml-handwriting
CONFIG += qt


unix {
#    CONFIG += link_pkgconfig
#    PKGCONFIG += zinnia
    LIBS += -L/usr/local/lib/ -lzinnia
}

HEADERS += \
    handwritingengine.h \

SOURCES += \
    handwritingengine.cpp \
    main.cpp

OTHER_FILES += *.qml
