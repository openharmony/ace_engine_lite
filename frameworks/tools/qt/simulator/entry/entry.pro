TEMPLATE = app
CONFIG += console c++11
QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES -= UNICODE
DEFINES += QT_COMPILER
DEFINES += Q_OBJECT
DEFINES += QT_DEPRECATED_WARNINGS

JSDESTDIR = ../libs

LIBS += -L$$JSDESTDIR \
        -ljsfwk \
        -ljerryScript

# Default rules for deployment.
qnx: target.path =/tmp/$${TARGET}/bin
else: unix:!android: target.path =/opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

ROOT_PATH = ../../../../../../../..
FOUNDATION_PATH = ../../../../../../..
ACELITE_PATH = ../../../../..
ACELITE_FRAMEWORK_PATH = ../../../..
UIDESTDIR = $${ROOT_PATH}/foundation/graphic/ui/tools/qt/simulator

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
    $${ACELITE_PATH}/interfaces/innerkits/builtin/async \
    $${ACELITE_PATH}/interfaces/innerkits/builtin/base \
    $${ACELITE_PATH}/interfaces/innerkits/builtin/jsi \
    $${ACELITE_FRAMEWORK_PATH}/include/base \
    $${FOUNDATION_PATH}/graphic/utils/interfaces/innerkits \
    $${FOUNDATION_PATH}/graphic/utils/interfaces/kits \
    $${FOUNDATION_PATH}/../third_party/freetype/include \
    $${FOUNDATION_PATH}/graphic/ui/interfaces/innerkits \
    $${FOUNDATION_PATH}/graphic/ui/frameworks \
    $${FOUNDATION_PATH}/graphic/ui/interfaces/kits \
    $${FOUNDATION_PATH}/graphic/ui/interfaces/innerkits/common \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/uitest \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/display \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/indev \
    $${ACELITE_FRAMEWORK_PATH}/targets/simulator \
    $${ACELITE_FRAMEWORK_PATH}/include/context/

HEADERS += \
    $${FOUNDATION_PATH}/graphic/ui/interfaces/innerkits/font/ui_font_vector.h \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/config.h \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/display/monitor.h \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/display/task_thread.h \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/display/gui_thread.h \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/indev/mouse_input.h \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/indev/mousewheel_input.h \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/uitest/main_widget.h \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/uitest/ui_mainwidget.h \
    $${ACELITE_FRAMEWORK_PATH}/include/context/js_ability.h

SOURCES += \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/display/gui_thread.cpp \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/display/monitor.cpp \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/display/task_thread.cpp \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/indev/mouse_input.cpp \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/drivers/indev/mousewheel_input.cpp \
    $${FOUNDATION_PATH}/graphic/ui/tools/qt/simulator/uitest/main_widget.cpp \
    main.cpp
    
