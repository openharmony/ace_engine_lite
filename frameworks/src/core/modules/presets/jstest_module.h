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
#ifndef OHOS_ACELITE_JSTEST_MODULE_H
#define OHOS_ACELITE_JSTEST_MODULE_H

#include "acelite_config.h"
#include "non_copyable.h"
#if ((JSFWK_TEST == 1) && (OHOS_ACELITE_PRODUCT_WATCH == 1))
#include "presets/preset_module.h"
namespace OHOS {
namespace ACELite {
class JSTestModule final : public PresetModule {
public:
    /**
     * @fn JSTestModule::JSTestModule()
     *
     * @brief Constructor.
     */
    JSTestModule() : PresetModule(nullptr) {}

    /**
     * @fn JSTestModule::~JSTestModule()
     *
     * @brief Constructor.
     */
    ~JSTestModule() = default;

    void Init() override;

private:
    static jerry_value_t JSTestPrint(const jerry_value_t func,
                                     const jerry_value_t context,
                                     const jerry_value_t *args,
                                     const jerry_length_t argsNum);
};
} // namespace ACELite
} // namespace OHOS
#endif
namespace OHOS {
namespace ACELite {
class JsTestModule final {
public:
    ACE_DISALLOW_COPY_AND_MOVE(JsTestModule);
    JsTestModule() = default;
    ~JsTestModule() = default;
    static void Load()
    {
#if ((JSFWK_TEST == 1) && (OHOS_ACELITE_PRODUCT_WATCH == 1))
        JSTestModule jsTestModule;
        jsTestModule.Init();
#endif
    }
};
} // namespace ACELite
} // namespace OHOS
#endif // OHOS_ACELITE_JSTEST_MODULE_H
