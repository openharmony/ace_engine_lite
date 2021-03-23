#include <QApplication>
#include <iostream>
#include "graphic_startup.h"
#include "monitor.h"
#include "js_ability.h"
#include "js_debugger_config.h"
#include "main_widget.h"

int main(int argc, char* argv[])
{
    QApplication uitest(argc, argv);
    OHOS::GraphicStartUp::Init();
    OHOS::Monitor::GetInstance()->InitHal();
    OHOS::Monitor::GetInstance()->InitFontEngine();
    OHOS::Monitor::GetInstance()->InitImageDecodeAbility();
    OHOS::ACELite::JSAbility jsAbility;
    OHOS::ACELite::DebuggerConfig jsDebuggerConfig;
    jsDebuggerConfig.startDebuggerServer = false;
    jsDebuggerConfig.snapshotMode = false;
    jsDebuggerConfig.heapSize = 64*1024;
    OHOS::ACELite::Debugger::GetInstance().ConfigEngineDebugger(jsDebuggerConfig);
    jsAbility.Launch("D:\\app\\default","MyApplication",0);
    OHOS::MainWidget mainWidget;
    mainWidget.resize(OHOS::HORIZONTAL_RESOLUTION, OHOS::VERTICAL_RESOLUTION);
    mainWidget.show();
    return uitest.exec();
}
