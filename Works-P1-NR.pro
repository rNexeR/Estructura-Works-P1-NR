#-------------------------------------------------
#
# Project created by QtCreator 2015-04-25T11:54:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Works-P1-NR
TEMPLATE = app


SOURCES += main.cpp\
        MainMenu.cpp \
    Tarea1/Calle.cpp \
    Tarea1/Semaphore.cpp \
    Tarea2/Duplicates.cpp \
    Tarea3/Arrays.cpp

HEADERS  += MainMenu.h \
    Tarea1/color.h \
    Tarea1/Calle.h \
    Tarea1/Semaphore.h \
    Tarea1/color.h \
    Tarea2/Duplicates.h \
    Tarea3/Arrays.h

FORMS    += MainMenu.ui \
    Tarea1/Semaphore.ui \
    Tarea2/Duplicates.ui \
    Tarea3/Arrays.ui
