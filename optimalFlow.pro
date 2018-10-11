TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    foundfeasible.cpp

HEADERS += \
    vector.h \
    foundfeasible.h

unix:!macx: LIBS += -lblas -llapack
