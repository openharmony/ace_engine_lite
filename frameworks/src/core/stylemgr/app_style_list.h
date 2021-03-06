/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
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
#ifndef OHOS_ACELITE_APP_STYLE_LIST_H
#define OHOS_ACELITE_APP_STYLE_LIST_H

#include "non_copyable.h"
#include "stylemgr/app_style.h"
#include "stylemgr/app_style_item.h"

namespace OHOS {
namespace ACELite {
class AppStyleList final : public MemoryHeap {
public:
    ACE_DISALLOW_COPY_AND_MOVE(AppStyleList);
    AppStyleList() : firstStyle_(nullptr), lastStyle_(nullptr) {}

    ~AppStyleList()
    {
        Reset();
    }

    const AppStyle* GetFirst() const
    {
        return firstStyle_;
    }

    void Reset();
    void AddStyle(AppStyle* newStyle);
    bool IsStyleExist(const AppStyle &newStyle);
    AppStyle *GetExistStyle(const char *name) const;

private:
    AppStyle* firstStyle_;
    AppStyle* lastStyle_;
};
} // namespace ACELite
} // namespace OHOS
#endif // OHOS_ACELITE_STYLE_LIST_H
