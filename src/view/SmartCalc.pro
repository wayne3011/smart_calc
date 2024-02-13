QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../data_structure/stack.c \
    ../model/polish_notation.c \
    ../data_structure/stack_double.c \
    ../controller/controller.c \
    main.cpp \
    qcustomplot.cpp \
    smart_calc_ui.cpp

HEADERS += \
    ../data_structure/stack.h \
    ../data_structure/stack_double.h \
    qcustomplot.h \
    smart_calc_ui.h

FORMS += \
    smart_calc.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
