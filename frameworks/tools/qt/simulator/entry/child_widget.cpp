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
    jsBundleText = new QLineEdit();
    jsBundleText->setFixedSize(300, 25);
    jsBundleText->setText(jsBundlePath);
    hLayout1->addWidget(jsBundleText);
    selectFolderBtn = new QPushButton();
    selectFolderBtn->setFixedSize(70, 25);
    selectFolderBtn->setText("...");
    hLayout1->addWidget(selectFolderBtn);
    vLayout->addLayout(hLayout1);
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    hLayout2->setAlignment(Qt::AlignLeft);
    QLabel *jsHeapLabel = new QLabel();
    jsHeapLabel->setFixedSize(110, 25);
    jsHeapLabel->setText("Heap Size:");
    hLayout2->addWidget(jsHeapLabel);
    jsHeapText = new QLineEdit();
    jsHeapText->setFixedSize(100, 25);
    jsHeapText->setText(jsHeapSize);
    hLayout2->addWidget(jsHeapText);
    QLabel *heapSizeLable = new QLabel();
    heapSizeLable->setFixedSize(190, 25);
    heapSizeLable->setText("设置范围：48~512 KB");
    hLayout2->addWidget(heapSizeLable);
    configBtn = new QPushButton();
    configBtn->setFixedSize(70, 25);
    configBtn->setText("启动");
    hLayout2->addWidget(configBtn);
    vLayout->addLayout(hLayout2);
}

void ChildWidget::InitSignalSlots() const
{
    connect(selectFolderBtn, SIGNAL(clicked()), this, SLOT(OpenFolderDialog()));
    connect(configBtn, SIGNAL(clicked()), this, SLOT(RestartApp()));
}

void ChildWidget::OpenFolderDialog() const
{
    QString dirpath = QFileDialog::getExistingDirectory(nullptr, "选择目录", "./", QFileDialog::ShowDirsOnly);
    if (!dirpath.isNull() && !dirpath.isEmpty()) {
        jsBundleText->setText(dirpath);
    }
}

void ChildWidget::RestartApp() const
{
    QString workingDirectory = QDir::currentPath();
    QString iniFilePath = workingDirectory + "/qt.ini";
    QSettings settings(iniFilePath, QSettings::IniFormat);
    settings.setValue("JSBundlePath", jsBundleText->text());
    settings.setValue("JSHeapSize", jsHeapText->text());
    QString program = QApplication::applicationFilePath();
    QStringList arguments = QApplication::arguments();
    QProcess::startDetached(program, arguments, workingDirectory);
    QApplication::exit();
}
