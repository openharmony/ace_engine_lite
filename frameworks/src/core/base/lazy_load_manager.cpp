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

#include "lazy_load_manager.h"
#include "ace_log.h"
#include "component.h"
#include "component_utils.h"
#include "lazy_load_watcher.h"

namespace OHOS {
namespace ACELite {
LazyLoadManager::LazyLoadManager() : firstWatcher_(nullptr), lastWatcher_(nullptr), state_(LazyLoadState::INIT)
{
}

LazyLoadManager::~LazyLoadManager()
{
    ResetWatchers();
}

void LazyLoadManager::ResetWatchers()
{
    LazyLoadWatcher *next = nullptr;
    while (firstWatcher_ != nullptr) {
        next = const_cast<LazyLoadWatcher *>(firstWatcher_->GetNext());
        delete firstWatcher_;
        firstWatcher_ = next;
    }

    lastWatcher_ = nullptr;
    state_ = LazyLoadState::INIT;
}

void LazyLoadManager::RenderLazyLoadWatcher()
{
    LazyLoadWatcher *next = nullptr;
    while (firstWatcher_ != nullptr) {
        jerry_value_t attrName = firstWatcher_->GetAttrName();
        jerry_value_t attrGetter = firstWatcher_->GetAttrGetter();
        uint16_t attrKeyID = firstWatcher_->GetKeyId();
        Component *component = ComponentUtils::GetComponentFromBindingObject(firstWatcher_->GetNativeElement());
        jerry_value_t latestValue =
            (component == nullptr) ? UNDEFINED : component->AddWatcherItem(attrName, attrGetter, true);
        if (attrKeyID == K_UNKNOWN) {
            // try to parse from attr name directly
            attrKeyID = ParseKeyIdFromJSString(attrName);
        }
        if ((!IS_UNDEFINED(latestValue)) && (attrKeyID != K_UNKNOWN)) {
            // need to update the view with the latest value, in case the value is already changed
            if (component->UpdateView(attrKeyID, latestValue)) {
                component->Invalidate();
            }
            // the new value has been calculated out by ParseExpression, need to be released
            jerry_release_value(latestValue);
        }
        next = const_cast<LazyLoadWatcher *>(firstWatcher_->GetNext());
        delete firstWatcher_;
        firstWatcher_ = next;
    }
    lastWatcher_ = nullptr;
    state_ = LazyLoadState::DONE;
}

void LazyLoadManager::AddLazyLoadWatcher(jerry_value_t nativeElement,
                                         jerry_value_t attrName,
                                         jerry_value_t getter)
{
    // pass key ID as UNKNOWN, and will be calculated out from attrName when using
    AddLazyLoadWatcher(nativeElement, attrName, getter, K_UNKNOWN);
}

void LazyLoadManager::AddLazyLoadWatcher(jerry_value_t nativeElement,
                                         jerry_value_t attrName,
                                         jerry_value_t getter,
                                         uint16_t keyId)
{
    if (nativeElement == UNDEFINED || attrName == UNDEFINED || getter == UNDEFINED) {
        return;
    }

    LazyLoadWatcher *watcher = new LazyLoadWatcher(nativeElement, attrName, getter, keyId);
    if (watcher == nullptr) {
        HILOG_ERROR(HILOG_MODULE_ACE, "create watcher errpr");
        return;
    }
    if (firstWatcher_ == nullptr) {
        firstWatcher_ = watcher;
        lastWatcher_ = watcher;
    } else {
        lastWatcher_->SetNext(*watcher);
        lastWatcher_ = watcher;
    }
    // The state must be ready if any watcher lazy loading request was added, otherwise, in some cases,
    // the js_ability may not be able to know there are watchers need to be loaded.
    state_ = LazyLoadState::READY;
}
} // namespace ACELite
} // namespace OHOS
