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
#include "localization_module_tdd_test.h"
#ifdef FEATURE_LOCALIZATION_MODULE
#include "ace_log.h"
#include "global.h"
#include "js_app_context.h"
#include "js_app_environment.h"
#include "test_common.h"
namespace OHOS {
namespace ACELite {
void LocalizationModuleTest::SetUp()
{
#ifdef TARGET_SIMULATOR
    constexpr char testAppPath[] = "..\\moduletest\\unittest";
#else
    constexpr char testAppPath[] = "/nfs";
#endif
    JsAppEnvironment *env = JsAppEnvironment::GetInstance();
    if (env == nullptr) {
        return;
    }
    env->InitJsFramework();
    const int defaultToken = 1000;
    JsAppContext::GetInstance()->SetCurrentAbilityInfo(testAppPath, "aaaa", defaultToken);
    const char *content = "new ViewModel({});";
    const jerry_char_t *jScript = reinterpret_cast<const jerry_char_t *>(content);
    viewModel_ = jerry_eval(jScript, strlen(content), JERRY_PARSE_NO_OPTS);
    if (jerry_value_is_error(viewModel_)) {
        HILOG_ERROR(HILOG_MODULE_ACE, "create ViewModel failed");
    } else {
        HILOG_INFO(HILOG_MODULE_ACE, "Pass");
    }
    // get the attribute $t
    localization_ = jerryx_get_property_str(viewModel_, "$t");
}

void LocalizationModuleTest::TearDown()
{
    if (viewModel_ != 0) {
        jerry_release_value(viewModel_);
    }
    if (localization_ != 0) {
        jerry_release_value(localization_);
    }
    JsAppEnvironment *env = JsAppEnvironment::GetInstance();
    if (env == nullptr) {
        return;
    }
    env->Cleanup();
}

char *LocalizationModuleTest::GetLocalizationResult(const jerry_value_t args[], const jerry_size_t argsNum) const
{
    jerry_value_t result = CallJSFunction(localization_, viewModel_, args, argsNum);
    if (jerry_value_is_error(result)) {
        return nullptr;
    }
    char *content = MallocStringOf(result);
    jerry_release_value(result);
    return content;
}

/**
 * @tc.name: TestNullValue009
 * @tc.desc: Test null object value in resource file
 * @tc.require: AR000EUO7G
 */
HWTEST_F(LocalizationModuleTest, TestNullValue009, TestSize.Level1)
{
    TDD_CASE_BEGIN();

    /**
     * @tc.steps:step1.execute js this.$t('localization01.test')
     * @tc.expected: step1.the result of execute js is undefined
     */
    jerry_value_t args[1];
    args[0] = jerry_create_string(reinterpret_cast<const jerry_char_t *>("localization01.test"));
    JSValue result = CallJSFunction(localization_, viewModel_, args, 1);
    EXPECT_TRUE(JSUndefined::Is(result));
    TDD_CASE_END();
}

#ifndef TDD_ASSERTIONS
void LocalizationModuleTest::RunTests()
{
    TestNullValue009();
}
#endif
}
}
#endif