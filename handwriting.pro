TEMPLATE = app
TARGET = qml-handwriting
CONFIG += qt
QT += declarative
SOURCES += handwriting.cpp


unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += zinnia
}
