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

#include "graphic_startup.h"
#include "js_ability.h"
#include "js_debugger_config.h"
#include "main_widget.h"
#include "monitor.h"
#include "child_widget.h"

void initUIkit()
{
    OHOS::GraphicStartUp::Init();
    OHOS::Monitor::GetInstance()->InitHal();
    OHOS::Monitor::GetInstance()->InitFontEngine();
    OHOS::Monitor::GetInstance()->InitImageDecodeAbility();
}

void setJSDebuggerConfig(int32_t defaultHeapSize)
{
    const int16_t bytes = 1024;
    OHOS::ACELite::DebuggerConfig jsDebuggerConfig;
    jsDebuggerConfig.startDebuggerServer = false;
    jsDebuggerConfig.snapshotMode = false;
    jsDebuggerConfig.heapSize = defaultHeapSize * bytes;
    OHOS::ACELite::Debugger::GetInstance().ConfigEngineDebugger(jsDebuggerConfig);
}

int main(int argc, char* argv[])
{
    int32_t defaultHeapSize = 64; // kB
    const int16_t minJSHeapSize = 48; // KB
    const int16_t maxJSHeapSize = 1024; // KB
    const int16_t childPageHeight = 100; // Pixle
    const int16_t defaultJSWindowWidth = 960; // pixel
    const int16_t defaultJSWindowHeight = 480; // pixel
    QApplication app(argc, argv);
    initUIkit();
    OHOS::MainWidget mainWidget;
    mainWidget.setWindowTitle("ACE Simulator");
    mainWidget.setFixedSize(defaultJSWindowWidth, defaultJSWindowHeight + childPageHeight);
    QString workingDirectory = QDir::currentPath();
    QString iniFilePath = workingDirectory +"/qt.ini";
    QSettings settings(iniFilePath,QSettings::IniFormat);
    QString jsBundlePath = settings.value("JSBundlePath").toString();
    if(jsBundlePath.isNull() || jsBundlePath.isEmpty()){
        jsBundlePath = "";
    } else {
        QFileInfo *file = new QFileInfo(jsBundlePath);
        if(file->exists() == false){
            jsBundlePath = "";
        }
    }
    QString jsHeapSizeStr = settings.value("JSHeapSize").toString();
    if(!jsHeapSizeStr.isNull() && !jsHeapSizeStr.isEmpty()){
        int tempSize = jsHeapSizeStr.toInt();
        if(tempSize >= minJSHeapSize && tempSize <= maxJSHeapSize) {
            defaultHeapSize = tempSize;
        } else {
            jsHeapSizeStr = "64";
        }
    } else {
        jsHeapSizeStr = "64";
    }
    ChildWidget *childWidget = new ChildWidget(&mainWidget, jsBundlePath, jsHeapSizeStr);
    childWidget->setGeometry(QRect(0, defaultJSWindowHeight, defaultJSWindowWidth, childPageHeight));
    OHOS::ACELite::JSAbility jsAbility;
    setJSDebuggerConfig(defaultHeapSize);
    jsAbility.Launch(jsBundlePath.toStdString().c_str(), "MyApplication", 0);
    jsAbility.Show();
    mainWidget.show();
    return app.exec();
}

