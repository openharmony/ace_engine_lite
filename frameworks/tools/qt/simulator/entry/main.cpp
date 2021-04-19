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

#include <iostream>


#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QSettings>
#include <Qt>

#include "child_widget.h"
#include "graphic_startup.h"
#include "js_ability.h"
#include "js_debugger_config.h"
#include "main_widget.h"
#include "monitor.h"
#include "simulator_config.h"

namespace  {
    void InitUIkit()
    {
        OHOS::GraphicStartUp::Init();
        OHOS::Monitor::GetInstance()->InitHal();
        OHOS::Monitor::GetInstance()->InitFontEngine();
        OHOS::Monitor::GetInstance()->InitImageDecodeAbility();
    }

    void SetJSDebuggerConfig(int32_t defaultHeapSize)
    {
        const int16_t bytes = 1024;
        OHOS::ACELite::DebuggerConfig jsDebuggerConfig;
        jsDebuggerConfig.startDebuggerServer = false;
        jsDebuggerConfig.snapshotMode = false;
        jsDebuggerConfig.heapSize = defaultHeapSize * bytes;
        OHOS::ACELite::Debugger::GetInstance().ConfigEngineDebugger(jsDebuggerConfig);
    }

    void InitPage(OHOS::MainWidget *mainWidget, int16_t jsWindowHeight, int16_t jsWindowWidth, int16_t childPageHeight)
    {
        int16_t defaultHeapSize = 64; // KB
        const int16_t minJSHeapSize = 48; // KB
        const int16_t maxJSHeapSize = 512; // KB
        QString jsBundlePath = SimulatorConfig::GetInstance().GetConfigValue("JSBundlePath");
        if (jsBundlePath.isNull() || jsBundlePath.isEmpty()) {
            jsBundlePath = "";
        } else {
            QFileInfo *file = new QFileInfo(jsBundlePath);
            if (file->exists() == false) {
                jsBundlePath = "";
            }
        }
        QString jsHeapSize = SimulatorConfig::GetInstance().GetConfigValue("JSHeapSize");
        if (!jsHeapSize.isNull() && !jsHeapSize.isEmpty()) {
            int tempSize = jsHeapSize.toInt();
            if (tempSize >= minJSHeapSize && tempSize <= maxJSHeapSize) {
                defaultHeapSize = tempSize;
            }
        }
        ChildWidget *childWidget = new ChildWidget(mainWidget, jsBundlePath, QString::number(defaultHeapSize));
        childWidget->setGeometry(QRect(0, jsWindowHeight, jsWindowWidth, childPageHeight));
        OHOS::ACELite::JSAbility jsAbility;
        SetJSDebuggerConfig(defaultHeapSize);
        jsAbility.Launch(jsBundlePath.toStdString().c_str(), "MyApplication", 0);
        jsAbility.Show();
    }
}

int main(int argc, char* argv[])
{
    const int16_t childPageHeight = 100; // pixel
    const int16_t defaultJSWindowWidth = 960; // pixel
    const int16_t defaultJSWindowHeight = 480; // pixel
    QApplication app(argc, argv);
    InitUIkit();
    OHOS::MainWidget mainWidget;
    mainWidget.setWindowTitle("ACE Simulator");
    mainWidget.setFixedSize(defaultJSWindowWidth, defaultJSWindowHeight + childPageHeight);
    InitPage(&mainWidget, defaultJSWindowHeight, defaultJSWindowWidth, childPageHeight);
    mainWidget.show();
    return app.exec();
}

