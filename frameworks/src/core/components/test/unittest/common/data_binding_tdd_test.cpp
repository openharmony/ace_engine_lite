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
#include "data_binding_tdd_test.h"
#include "ui_label.h"

namespace OHOS {
namespace ACELite {
constexpr char *BUNDLE_OF_ATTR_BINDING =
    "(function(){\n"
    "  return new ViewModel({\n"
    "    render: function(vm) {\n"
    "	  var _vm = vm || this;\n"
    "	  return _c('div', { staticClass: ['container'] }, [\n"
    "	    _c('text', {\n"
    "		  staticClass: ['title'],\n"
    "		  attrs: {\n"
    "		    ref: 'text',\n"
    "		    value: function() {\n"
    "			  return _vm.count;\n"
    "			}\n"
    "		  }\n"
    "		}),\n"
    "		_c('input', {\n"
    "		  staticClass: ['button'],\n"
    "		  attrs: {\n"
    "           ref: 'increaseBtn',\n"
    "		    type: 'button',\n"
    "			vlaue: 'INCREASE'\n"
    "		  },\n"
    "		  catchBubbleEvents: {\n"
    "		    click: _vm.increase\n"
    "		  }\n"
    "		}),\n"
    "		_c('input', {\n"
    "		  staticClass: ['button'],\n"
    "		  attrs: {\n"
    "           ref: 'decreaseBtn',\n"
    "		    type: 'button',\n"
    "			vlaue: 'DECREASE'\n"
    "		  },\n"
    "		  catchBubbleEvents: {\n"
    "		    click: _vm.decrease\n"
    "		  }\n"
    "		})\n"
    "	  ]);\n"
    "	},\n"
    "	styleSheet: {\n"
    "	  classSelectors: {\n"
    "	    container: {\n"
    "		  flexDirection: 'column',\n"
    "		  justifyContent: 'center',\n"
    "		  alignItems: 'center',\n"
    "		  height: '100%',\n"
    "		  width: '100%'\n"
    "		},\n"
    "		title: {\n"
    "		  textAlign: 'center',\n"
    "		  height: 50,\n"
    "		  width: '80%'\n"
    "		},\n"
    "		button: {\n"
    "		  borderRadius: 0,\n"
    "		  height: 50,\n"
    "		  width: '80%'\n"
    "		}\n"
    "	  }\n"
    "	},\n"
    "	data: {\n"
    "	  count: 0\n"
    "	},\n"
    "	increase: function() {\n"
    "	  this.count++;\n"
    "	},\n"
    "	decrease: function() {\n"
    "	  this.count--;\n"
    "	}\n"
    "  });\n"
    "}());\n";

const char *BUNDLE_OF_STYLE_BINDING =
    "(function () {\n"
    "  return new ViewModel({\n"
    "    render: function (vm) {\n"
    "      var _vm = vm || this;\n"
    "      return _c('div', { staticClass: ['container'] }, [\n"
    "        _c('text', {\n"
    "          staticClass: 'title',\n"
    "          attrs: {\n"
    "            ref: 'text',\n"
    "            value: 'Hi OpenHarmonyOS!'\n"
    "          },\n"
    "          dynamicStyle: {\n"
    "            backgroundColor: function() {\n"
    "              return _vm.bgColor;\n"
    "            }\n"
    "          }\n"
    "        }),\n"
    "        _c('input', {\n"
    "		  staticClass: ['button'],\n"
    "		  attrs: {\n"
    "           ref: 'redBgColorBtn',\n"
    "		    type: 'button',\n"
    "			vlaue: 'LEFT'\n"
    "		  },\n"
    "		  catchBubbleEvents: {\n"
    "		    click: _vm.redBgColor\n"
    "		  }\n"
    "		}),\n"
    "        _c('input', {\n"
    "		  staticClass: ['button'],\n"
    "		  attrs: {\n"
    "           ref: 'greenBgColorBtn',\n"
    "		    type: 'button',\n"
    "			vlaue: 'CENTER'\n"
    "		  },\n"
    "		  catchBubbleEvents: {\n"
    "		    click: _vm.greenBgColor\n"
    "		  }\n"
    "		}),\n"
    "        _c('input', {\n"
    "		  staticClass: ['button'],\n"
    "		  attrs: {\n"
    "           ref: 'blueBgColorBtn',\n"
    "		    type: 'button',\n"
    "			vlaue: 'RIGHT'\n"
    "		  },\n"
    "		  catchBubbleEvents: {\n"
    "		    click: _vm.blueBgColor\n"
    "		  }\n"
    "		})\n"
    "      ]);\n"
    "    },\n"
    "    styleSheet: {\n"
    "      classSelectors: {\n"
    "        container: {\n"
    "          flexDirection: 'column',\n"
    "          justifyContent: 'center',\n"
    "          alignItems: 'center',\n"
    "          height: '100%',\n"
    "          width: '100%'\n"
    "        },\n"
    "		title: {\n"
    "		  backgroundColor: '#000',\n"
    "		  color: '#fff',\n"
    "		  textAlign: 'center',\n"
    "		  height: 50,\n"
    "		  width: '80%'\n"
    "		},\n"
    "		button: {\n"
    "		  borderRadius: 0,\n"
    "		  height: 50,\n"
    "		  width: '80%'\n"
    "		}\n"
    "      }\n"
    "    },\n"
    "    data: {\n"
    "      bgColor: 'center'\n"
    "    },\n"
    "    redBgColor: function() {\n"
    "      this.bgColor = '#f00';\n"
    "    },\n"
    "    greenBgColor: function() {\n"
    "      this.bgColor = '#0f0';\n"
    "    },\n"
    "    blueBgColor: function() {\n"
    "      this.bgColor = '#00f';\n"
    "    }\n"
    "  });\n"
    "}())\n";

void DataBindingTddTest::RunTests()
{
    AttrBindingTest001();
    StyleBindingTest002();
}

/**
 * @tc.name: AttrBindingTest001
 * @tc.desc: test the attribute data binding
 */
HWTEST_F(DataBindingTddTest, AttrBindingTest001, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    JSValue page = CreatePage(BUNDLE_OF_ATTR_BINDING, strlen(BUNDLE_OF_ATTR_BINDING));
    UILabel *label = reinterpret_cast<UILabel *>(GetViewByRef(page, "text"));
    EXPECT_TRUE(label != nullptr);
    EXPECT_STREQ(label->GetText(), "0");
    ClickByRef(page, "increaseBtn");
    EXPECT_STREQ(label->GetText(), "1");
    ClickByRef(page, "decreaseBtn");
    EXPECT_STREQ(label->GetText(), "0");
    DestroyPage(page);
    TDD_CASE_END();
}

/**
 * @tc.name: StyleBindingTest002
 * @tc.desc: test the style data binding
 */
HWTEST_F(DataBindingTddTest, StyleBindingTest002, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    JSValue page = CreatePage(BUNDLE_OF_STYLE_BINDING, strlen(BUNDLE_OF_STYLE_BINDING));
    UILabel *label = reinterpret_cast<UILabel *>(GetViewByRef(page, "text"));
    EXPECT_TRUE(label != nullptr);
    constexpr int64_t COLOR_FULL_BLACK = 0xff000000;
    constexpr int64_t COLOR_FULL_RED = 0xffff0000;
    constexpr int64_t COLOR_FULL_GREEN = 0xff00ff00;
    constexpr int64_t COLOR_FULL_BLUE = 0xff0000ff;
    EXPECT_EQ(label->GetStyle(STYLE_BACKGROUND_COLOR), COLOR_FULL_BLACK);
    ClickByRef(page, "redBgColorBtn");
    EXPECT_EQ(label->GetStyle(STYLE_BACKGROUND_COLOR), COLOR_FULL_RED);
    ClickByRef(page, "greenBgColorBtn");
    EXPECT_EQ(label->GetStyle(STYLE_BACKGROUND_COLOR), COLOR_FULL_GREEN);
    ClickByRef(page, "blueBgColorBtn");
    EXPECT_EQ(label->GetStyle(STYLE_BACKGROUND_COLOR), COLOR_FULL_BLUE);
    DestroyPage(page);
    TDD_CASE_END();
}
} // namespace ACELite
} // namespace OHOS