/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "graphic_startup.h"
#include <iostream>
#include "js_ability.h"
#include "js_debugger_config.h"
#include "main_widget.h"
#include "monitor.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    OHOS::GraphicStartUp::Init();
    OHOS::Monitor::GetInstance()->InitHal();
    OHOS::Monitor::GetInstance()->InitFontEngine();
    OHOS::Monitor::GetInstance()->InitImageDecodeAbility();
    OHOS::ACELite::JSAbility jsAbility;
    OHOS::ACELite::DebuggerConfig jsDebuggerConfig;
    jsDebuggerConfig.startDebuggerServer = false;
    jsDebuggerConfig.snapshotMode = false;
    jsDebuggerConfig.heapSize = 65536; //64*1024,64kB
    OHOS::ACELite::Debugger::GetInstance().ConfigEngineDebugger(jsDebuggerConfig);
    jsAbility.Launch("D:\\app\\div", "MyApplication", 0);
    jsAbility.Show();
    OHOS::MainWidget mainWidget;
    mainWidget.resize(OHOS::HORIZONTAL_RESOLUTION, OHOS::VERTICAL_RESOLUTION);
    mainWidget.show();
    return app.exec();
}
