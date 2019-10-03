QT += concurrent widgets
CONFIG += console

SOURCES += main.cpp

#target.path = $$[QT_INSTALL_EXAMPLES]/qtconcurrent/progressdialog
#INSTALLS += target

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
