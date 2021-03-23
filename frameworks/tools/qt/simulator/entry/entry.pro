TEMPLATE = app
CONFIG += console c++11
QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES  -= UNICODE
DEFINES  += QT_COMPILER
DEFINES  += Q_OBJECT
DEFINES += QT_DEPRECATED_WARNINGS

JSDESTDIR = ../libs

LIBS += -L$$JSDESTDIR \
        -ljsfwk \
        #-lcjson \
        -ljerryScript

# Default rules for deployment.
qnx: target.path =/tmp/$${TARGET}/bin
else: unix:!android: target.path =/opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

UIDESTDIR = ../../../../../../../../foundation/graphic/ui/tools/qt/simulator

LIBS += -L$$UIDESTDIR/libs \
        -llibui \
        -lfreetype \
        -lharfbuzz \
        -licu \
        -llibpng \
        -lzlib \
        -llibjpeg \
        -lqrcodegen

INCLUDEPATH += \
    ../../../../../interfaces/innerkits/builtin/async \
    ../../../../../interfaces/innerkits/builtin/base \
    ../../../../../interfaces/innerkits/builtin/jsi \
    ../../../../include/base \
    ../../../../../../../graphic/utils/interfaces/innerkits \
    ../../../../../../../graphic/utils/interfaces/kits \
    ../../../../../../../../third_party/freetype/include \
    ../../../../../../../graphic/ui/interfaces/innerkits \
    ../../../../../../../graphic/ui/frameworks \
    ../../../../../../../graphic/ui/interfaces/kits \
    ../../../../../../../graphic/ui/interfaces/innerkits/common \
    ../../../../../../../graphic/ui/tools/qt/simulator/drivers \
    ../../../../../../../graphic/ui/tools/qt/simulator/uitest \
    ../../../../../../../graphic/ui/tools/qt/simulator/drivers/display \
    ../../../../../../../graphic/ui/tools/qt/simulator/drivers/indev \
    ../../../../targets/simulator \
    ../../../../include/context/

HEADERS += \
    ../../../../../../../graphic/ui/interfaces/innerkits/font/ui_font_vector.h \
          ../../../../../../../graphic/ui/tools/qt/simulator/drivers/config.h \
          ../../../../../../../graphic/ui/tools/qt/simulator/drivers/display/gui_thread.h \
          ../../../../../../../graphic/ui/tools/qt/simulator/drivers/display/monitor.h \
          ../../../../../../../graphic/ui/tools/qt/simulator/drivers/display/task_thread.h \
          ../../../../../../../graphic/ui/tools/qt/simulator/drivers/indev/mouse_input.h \
          ../../../../../../../graphic/ui/tools/qt/simulator/drivers/indev/mousewheel_input.h \
    ../../../../../../../graphic/ui/tools/qt/simulator/uitest/main_widget.h \
    ../../../../../../../graphic/ui/tools/qt/simulator/uitest/ui_mainwidget.h \
           ../../../../include/context/js_ability.h

SOURCES += \
    ../../../../../../../graphic/ui/tools/qt/simulator/drivers/display/gui_thread.cpp \
    ../../../../../../../graphic/ui/tools/qt/simulator/drivers/display/monitor.cpp \
    ../../../../../../../graphic/ui/tools/qt/simulator/drivers/display/task_thread.cpp \
    ../../../../../../../graphic/ui/tools/qt/simulator/drivers/indev/mouse_input.cpp \
    ../../../../../../../graphic/ui/tools/qt/simulator/drivers/indev/mousewheel_input.cpp \
    main.cpp \
    ../../../../../../../graphic/ui/tools/qt/simulator/uitest/main_widget.cpp
