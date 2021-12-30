QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DNetMaster.cpp \
    DSVTask_FunctionApproximation.cpp \
    MainWidget.cpp \
    __dsynapseVisual_global.cpp \
    main.cpp

HEADERS += \
    DNetMaster.h \
    DSVTask_FunctionApproximation.h \
    MainWidget.h \
    __dsynapseVisual_global.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



#=========================================================================== DSynapseLearn:
win32: LIBS += -L$$PWD/../../DothProject/DSynapseLearn/release/ -lDSynapseLearn

INCLUDEPATH += $$PWD/../../DothProject/DSynapseLearn/
DEPENDPATH += $$PWD/../../DothProject/DSynapseLearn/

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DSynapseLearn/release/DSynapseLearn.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DSynapseLearn/release/libDSynapseLearn.a
#=========================================================================== DSynapse:
win32: LIBS += -L$$PWD/../../DothProject/DSynapse/release/ -lDSynapse

INCLUDEPATH += $$PWD/../../DothProject/DSynapse/
DEPENDPATH += $$PWD/../../DothProject/DSynapse/

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DSynapse/release/DSynapse.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DSynapse/release/libDSynapse.a
#=========================================================================== DWidgets:
win32: LIBS += -L$$PWD/../../DothProject/DWidgets/release/ -lDWidgets

INCLUDEPATH += $$PWD/../../DothProject/DWidgets/
DEPENDPATH += $$PWD/../../DothProject/DWidgets/

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DWidgets/release/DWidgets.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DWidgets/release/libDWidgets.a

#=========================================================================== DTL:
win32: LIBS += -L$$PWD/../../DothProject/DTL/release/ -lDothTemplateLibrary

INCLUDEPATH += $$PWD/../../DothProject/DTL/
DEPENDPATH += $$PWD/../../DothProject/DTL/

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DTL/release/DothTemplateLibrary.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DTL/release/libDothTemplateLibrary.a
#=========================================================================== DLogs:
win32: LIBS += -L$$PWD/../../DothProject/DLogs/release/ -lDLogs

INCLUDEPATH += $$PWD/../../DothProject/DLogs/
DEPENDPATH += $$PWD/../../DothProject/DLogs/

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DLogs/release/DLogs.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DLogs/release/libDLogs.a
#=========================================================================== DBalance:
win32: LIBS += -L$$PWD/../../MyProjects2/DBalance/release/ -lDBalance

INCLUDEPATH += $$PWD/../../MyProjects2/DBalance/
DEPENDPATH += $$PWD/../../MyProjects2/DBalance/

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../MyProjects2/DBalance/release/DBalance.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../MyProjects2/DBalance/release/libDBalance.a
#=========================================================================== DBalance:
win32: LIBS += -L$$PWD/../../DothProject/DTcp/release/ -lDTcp

INCLUDEPATH += $$PWD/../../DothProject/DTcp/
DEPENDPATH += $$PWD/../../DothProject/DTcp/

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DTcp/release/DTcp.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../DothProject/DTcp/release/libDTcp.a


LIBS += -lws2_32
