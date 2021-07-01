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

#ifndef OHOS_ACELITE_JS_HEAP_STATS_DUMPER_H
#define OHOS_ACELITE_JS_HEAP_STATS_DUMPER_H

#include "jsi.h"
#include "js_heap_stats_writer.h"

namespace OHOS {
namespace ACELite {
class JSHeapStatsDumper {
public:
    JSHeapStatsDumper();
    ~JSHeapStatsDumper();

    void Dump();

private:
    bool HasChanged(JSHeapStatus &stats) const;
    void HandleChange(JSHeapStatus &stats);
    void UpdateStats(JSHeapStatus &stats);
    void LogStats(JSHeapStatus &stats) const;
    void SaveStats(JSHeapStatus &stats);

    JSHeapStatus stats_;
    JSHeapStatsWriter writer_;
};
} // namespace ACELite
} // namespace OHOS

#endif
