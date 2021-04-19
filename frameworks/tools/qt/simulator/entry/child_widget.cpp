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

#include <child_widget.h>

#include <QApplication>
#include <QDir>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QFileInfo>
#include <QLabel>
#include <QLineEdit>
#include <QProcess>
#include <QPushButton>
#include <QSettings>
#include <QString>
#include <Qt>

#include "simulator_config.h"

ChildWidget::ChildWidget(QWidget *parent, QString jsBundlePath, QString jsHeapSize): QWidget(parent)
{
    InitPage(jsBundlePath, jsHeapSize);
    InitSignalSlots();
}

void ChildWidget::InitPage(QString jsBundlePath, QString jsHeapSize)
{
    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->setAlignment(Qt::AlignTop);
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    hLayout1->setAlignment(Qt::AlignLeft);
    QLabel *jsBundleLabel = new QLabel();
    jsBundleLabel->setFixedSize(110, 25);
    jsBundleLabel->setText("JS Bundle:");
    hLayout1->addWidget(jsBundleLabel);
    jsBundleText.setFixedSize(300, 25);
    jsBundleText.setText(jsBundlePath);
    hLayout1->addWidget(&jsBundleText);
    selectFolderBtn.setFixedSize(70, 25);
    selectFolderBtn.setText("...");
    hLayout1->addWidget(&selectFolderBtn);
    vLayout->addLayout(hLayout1);
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    hLayout2->setAlignment(Qt::AlignLeft);
    QLabel *jsHeapLabel = new QLabel();
    jsHeapLabel->setFixedSize(110, 25);
    jsHeapLabel->setText("Heap Size:");
    hLayout2->addWidget(jsHeapLabel);
    jsHeapText.setFixedSize(100, 25);
    jsHeapText.setText(jsHeapSize);
    hLayout2->addWidget(&jsHeapText);
    QLabel *heapSizeLable = new QLabel();
    heapSizeLable->setFixedSize(190, 25);
    heapSizeLable->setText("Range：48~512 KB");
    hLayout2->addWidget(heapSizeLable);
    configBtn.setFixedSize(70, 25);
    configBtn.setText("Start");
    hLayout2->addWidget(&configBtn);
    vLayout->addLayout(hLayout2);
}

void ChildWidget::InitSignalSlots() const
{
    connect(&selectFolderBtn, SIGNAL(clicked()), this, SLOT(OpenFolderDialog()));
    connect(&configBtn, SIGNAL(clicked()), this, SLOT(RestartApp()));
}

void ChildWidget::OpenFolderDialog()
{
    QString dirpath = QFileDialog::getExistingDirectory(nullptr, "Select Folder", "./", QFileDialog::ShowDirsOnly);
    if (!dirpath.isNull() && !dirpath.isEmpty()) {
        jsBundleText.setText(dirpath);
    }
}

void ChildWidget::RestartApp() const
{
    SimulatorConfig::GetInstance().SetConfigValue("JSBundlePath", jsBundleText.text());
    SimulatorConfig::GetInstance().SetConfigValue("JSHeapSize", jsHeapText.text());
    QString program = QApplication::applicationFilePath();
    QStringList arguments = QApplication::arguments();
    QProcess::startDetached(program, arguments, QDir::currentPath());
    QApplication::exit();
}
