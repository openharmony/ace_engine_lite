/*
 * Copyright (c) 2022-2022 Huawei Device Co., Ltd.
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
#ifndef OHOS_ACELITE_SYSCAP_MODULE_H
#define OHOS_ACELITE_SYSCAP_MODULE_H

#include "acelite_config.h"
#if (FEATURE_SYSCAP_MODULE == 1)
#include "presets/preset_module.h"

namespace OHOS {
namespace ACELite {
class SyscapModule final : PresetModule {
public:
    ACE_DISALLOW_COPY_AND_MOVE(SyscapModule);
    static SyscapModule *GetInstance()
    {
        static SyscapModule instance;
        return &instance;
    }
    void Init() override;

private:
    /**
     * @fn SyscapModule::SyscapModule()
     * @brief Constructor
     */
    SyscapModule() : PresetModule(nullptr)
    {
    }

    /**
     * @fn SyscapModule::~SyscapModule()
     *
     */
    ~SyscapModule() = default;

    /**
     * @brief get the syscap.
     */
    static jerry_value_t CanIUse(const jerry_value_t func,
                                 const jerry_value_t context,
                                 const jerry_value_t *args,
                                 const jerry_length_t argsNum)
    {
        return CheckSyscap(func, context, args, argsNum, false);
    }

    /**
     * @brief get the syscap whether exist.
     * @return the boolean of syscap
     */
    static jerry_value_t CheckSyscap(const jerry_value_t func,
                                     const jerry_value_t context,
                                     const jerry_value_t *args,
                                     const jerry_length_t argsNum,
                                     bool repeated);
};
} // namespace ACELite
} // namespace OHOS
#endif // FEATURE_SYSCAP_MODULE == 1

namespace OHOS {
namespace ACELite {
class SyscapsModule final {
public:
    ACE_DISALLOW_COPY_AND_MOVE(SyscapsModule);
    SyscapsModule() = default;
    ~SyscapsModule() = default;
    static void Load()
    {
#if (FEATURE_SYSCAP_MODULE == 1)
        SyscapModule *syscapModule = const_cast<SyscapModule *>(SyscapModule::GetInstance());
        syscapModule->Init();
#endif
    }
};
} // namespace ACELite
} // namespace OHOS
#endif // OHOS_ACELITE_SYSCAP_MODULE_H
