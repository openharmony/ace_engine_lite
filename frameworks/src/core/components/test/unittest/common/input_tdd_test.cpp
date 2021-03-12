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

#include "input_tdd_test.h"
#include "ui_label_button.h"
#include "ui_view.h"

namespace OHOS {
namespace ACELite {
void InputTddTest::AddBoolProperty(jerry_value_t object, const char *name, bool value) const
{
    jerry_value_t nameProp = jerry_create_string(reinterpret_cast<const jerry_char_t *>(name));
    jerry_value_t valueProp = jerry_create_boolean(value);
    jerry_release_value(jerry_set_property(object, nameProp, valueProp));
    ReleaseJerryValue(nameProp, valueProp, VA_ARG_END_FLAG);
}

bool InputTddTest::CompareColor(ColorType color, uint32_t colorIntValue) const
{
    uint8_t red8 = uint8_t((colorIntValue & TEXT_RED_COLOR_MASK) >> RED_COLOR_START_BIT);
    uint8_t green8 = uint8_t((colorIntValue & TEXT_GREEN_COLOR_MASK) >> GREEN_COLOR_START_BIT);
    uint8_t blue8 = uint8_t((colorIntValue & TEXT_BLUE_COLOR_MASK));
    ColorType compare = Color::GetColorFromRGB(red8, green8, blue8);
    return (color.blue == compare.blue && color.red == compare.red && color.green == compare.green);
}

/**
 * @tc.name: ComponentInputAttributeTest01
 * @tc.desc: test the attribute checked in checkbox is correct
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputAttributeTest01, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1.set the type checkbox and get the native element
     */
    JerrySetStringProperty(attrsObj_, "type", "checkbox");
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UICheckBox *checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetState() == UICheckBox::UNSELECTED));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step2.set the checked attribute true
     * @tc.expected:step2. the value of checked is selected
     */
    AddBoolProperty(attrsObj_, "checked", true);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetState() == UICheckBox::SELECTED));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps: step3:set the checked attribute false
     * @tc.expect: the value of checked attribute is unselected
     */
    AddBoolProperty(attrsObj_, "checked", false);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetState() == UICheckBox::UNSELECTED));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step4.set the checked attribute "aaaa"
     * @tc.expected:step4.the checked attribute is error
     */
    JerrySetStringProperty(attrsObj_, "checked", "aaaa");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetState() == UICheckBox::UNSELECTED));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputAttributeTest02
 * @tc.desc: test the attribute value
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputAttributeTest02, TestSize.Level1)
{
    TDD_CASE_BEGIN();

    /**
     * @tc.steps: step1.set the attibute type button
     */
    JerrySetStringProperty(attrsObj_, "type", "button");

    /**
     * @tc.steps: step2.set the attribute value aaaa
     * @tc.expected:step2.the value of button is aaaa
     */
    JerrySetStringProperty(attrsObj_, "value", "aaa");
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UILabelButton *button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button != nullptr) && (button->GetText(), "aaa"));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the attribute value nullptr
     * @tc.expected:step3.the value of button is nullptr
     */
    jerry_value_t nullProp = UNDEFINED;
    JerrySetNamedProperty(attrsObj_, "value", nullProp);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button != nullptr) && (button->GetText() == nullptr));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputStyleTest03
 * @tc.desc: test the button value
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputStyleTest03, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps: step1.set the type attribute button and the value attribute aaaa
     */
    JerrySetStringProperty(attrsObj_, "type", "button");
    JerrySetStringProperty(attrsObj_, "value", "aaaa");

    /**
     * @tc.steps:step2.set the color value 16711680
     * @tc.expected:step2.the font color of UILabelButton is red
     */
    const int32_t redValue = 16711680;
    JerrySetNumberProperty(styleObj_, "color", redValue);
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UILabelButton *button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_FALSE(button == nullptr);
    ColorType tempColor;
    tempColor.full = button->GetLabelStyle(STYLE_TEXT_COLOR);
    EXPECT_TRUE(CompareColor(tempColor, redValue));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the color value 21474836481
     * @tc.expected:step3.the font color of UILabelButton is red
     */
    const int32_t max = 2147483647;
    JerrySetNumberProperty(styleObj_, "color", max);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_FALSE(button == nullptr);
    tempColor.full = button->GetLabelStyle(STYLE_TEXT_COLOR);
    EXPECT_TRUE(CompareColor(tempColor, max));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step4.set the color property -21474836482
     * @tc.expected:step4.the font color of UILabelButton is red
     */
    const int32_t min = INT_MIN;
    JerrySetNumberProperty(styleObj_, "color", min);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_FALSE(button == nullptr);
    tempColor.full = button->GetLabelStyle(STYLE_TEXT_COLOR);
    EXPECT_TRUE(CompareColor(tempColor, min));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputStyleTest04
 * @tc.desc: test the text-align style in button
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputStyleTest04, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1: set the attribute type button
     */
    JerrySetStringProperty(attrsObj_, "type", "button");

    /**
     * @tc.steps:step2.set the attribute textAlign center
     * @tc.expected:step2.the align attribute is UITextLanguageAlignment::TEXT_ALIGNMENT_CENTER
     */
    JerrySetStringProperty(styleObj_, "textAlign", "center");
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UILabelButton *button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button != nullptr) && (button->GetAlign() == UITextLanguageAlignment::TEXT_ALIGNMENT_CENTER));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the attribute textAlign right
     * @tc.expected:step3.the align attribute is UITextLanguageAlignment::TEXT_ALIGNMENT_RIGHT
     */
    JerrySetStringProperty(styleObj_, "textAlign", "right");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button != nullptr) && (button->GetAlign() == UITextLanguageAlignment::TEXT_ALIGNMENT_RIGHT));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step4.set the attribute textAlign left
     * @tc.expected:step4.the align attribute is UITextLanguageAlignment::TEXT_ALIGNMENT_LEFT
     */
    JerrySetStringProperty(styleObj_, "textAlign", "left");
    component = GetRenderedComponent(K_INPUT);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button != nullptr) && (button->GetAlign() == UITextLanguageAlignment::TEXT_ALIGNMENT_LEFT));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step5.set the attribute textAlign aaa
     * @tc.expected:step5.the align attribute is UITextLanguageAlignment::TEXT_ALIGNMENT_CENTER
     */
    JerrySetStringProperty(styleObj_, "textAlign", "aaa");
    component = GetRenderedComponent(K_INPUT);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button != nullptr) && (button->GetAlign() == UITextLanguageAlignment::TEXT_ALIGNMENT_CENTER));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputAttributeTest05
 * @tc.desc: test the checked attribute in checkbox
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputAttributeTest05, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1.set the type attribute checkbox
     */
    JerrySetStringProperty(attrsObj_, "type", "checkbox");

    /**
     * @tc.steps:step2.set the checked attribute true
     * @tc.expected:step2.the status of checkbox is selected
     */
    const char *checked = "checked";
    AddBoolProperty(attrsObj_, checked, true);
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UICheckBox *checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetState() == UICheckBox::SELECTED));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the checked attribute false
     * @tc.expected:step3.the status of checkbox is unselected
     */
    AddBoolProperty(attrsObj_, checked, false);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetState() == UICheckBox::UNSELECTED));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step4.set the checked attribute aaaa
     * @tc.expected:step4.the status of checkbox is unselected
     */
    JerrySetStringProperty(attrsObj_, checked, "aaaa");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetState() == UICheckBox::UNSELECTED));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputAttributeTest06
 * @tc.desc: test the width style in button
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputAttributeTest06, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1:set tye type attribute button
     */
    JerrySetStringProperty(attrsObj_, "type", "button");

    /**
     * @tc.steps:step2:set the attribute width 50
     * @tc.expected:step2.the width of UILabelButton is 50
     */
    const int widthNumber = 50;
    JerrySetNumberProperty(styleObj_, "width", widthNumber);
    Component *component = GetRenderedComponent(K_INPUT);
    UILabelButton *button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button != nullptr) && (button->GetWidth() == widthNumber));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3:set the attribute height 20
     * @tc.expected:step3.the height of UILabelButton is 20
     */
    const int heightValue = 20;
    JerrySetNumberProperty(styleObj_, "height", heightValue);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>((component->GetComponentRootView()));
    EXPECT_TRUE((button != nullptr) && (button->GetHeight() == heightValue));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step6.set the attribute id button1
     * @tc.expected:step6.the id of button is button1
     */
    JerrySetStringProperty(attrsObj_, "id", "button1");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button != nullptr) && (!strcmp(button->GetViewId(), "button1")));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputStyleTest07
 * @tc.desc: test the margin style
 * @tc.require: AR000DSEFK
 */
void InputTddTest::ComponentInputStyleTest07()
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1:set the type button
     */
    JerrySetStringProperty(styleObj_, "type", "button");

    /**
     * @tc.steps: step2. set the margin 100
     * @tc.expected:step2.the value of margin is 100
     */
    const int marginValue = 100;
    JerrySetNumberProperty(styleObj_, "margin", marginValue);
    Component *component = GetRenderedComponent(K_INPUT);
    UILabelButton *button = reinterpret_cast<UILabelButton *>((component->GetComponentRootView()));
    EXPECT_FALSE(button == nullptr);
    int16_t left = button->GetStyle(STYLE_MARGIN_LEFT);
    int16_t right = button->GetStyle(STYLE_MARGIN_RIGHT);
    int16_t top = button->GetStyle(STYLE_MARGIN_TOP);
    int16_t bottom = button->GetStyle(STYLE_MARGIN_BOTTOM);
    EXPECT_TRUE(left == marginValue && right == marginValue && top == marginValue && bottom == marginValue);

    /**
     * @tc.steps:step3.set the attribute marginLeft 10
     * @tc.expected:step3.the value of marginLeft is 10
     */
    const int marginLeftValue = 10;
    JerrySetNumberProperty(styleObj_, "marginLeft", marginLeftValue);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_FALSE(button == nullptr);
    left = button->GetStyle(STYLE_MARGIN_LEFT);
    EXPECT_TRUE(left == marginLeftValue);
    component->Release();
    delete component;
    component = nullptr;
    ComponentInputStyleTest07Extra();
    TDD_CASE_END();
}

void InputTddTest::ComponentInputStyleTest07Extra()
{
    /**
     * @tc.steps:step4.set the attribute marginButtom 10
     * @tc.expected:step4.the attribute of marginButton 10
     */
     const uint8_t marginValue = 10;
    JerrySetNumberProperty(styleObj_, "marginButtom", marginValue);
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UILabelButton *button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button != nullptr) && (button->GetStyle(STYLE_MARGIN_BOTTOM) == marginValue));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps: step5.set the attribute marginRight 10
     * @tc.expected:step5.the value of marginRight is 10
     */
    JerrySetNumberProperty(styleObj_, "marginRight", marginValue);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button == nullptr) && (button->GetStyle(STYLE_MARGIN_RIGHT) == marginValue));
    component->Release();
    delete component;
    component = nullptr;
    /**
     * @tc.steps:step6.set the attribute marginTop 10
     * @tc.expected:step6.the attribute marginTop is 10
     */
    JerrySetNumberProperty(styleObj_, "marginTop", marginValue);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button != nullptr) && (button->GetStyle(STYLE_MARGIN_TOP) == marginValue));
    component->Release();
    delete component;
    component = nullptr;
}

/**
 * @tc.name: ComponentInputStyleTest08
 * @tc.desc: test the border style in button
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputStyleTest08, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps: step1:set the attribute button
     */
    JerrySetStringProperty(attrsObj_, "type", "button");

    /**
     * @tc.steps:step2.set the borderWidth 2
     * @tc.expected:step2.the border width of button is 2
     */
    const int borderWidthValue = 2;
    JerrySetNumberProperty(styleObj_, "borderWidth", borderWidthValue);
    Component * component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UILabelButton *button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((component != nullptr) && (button->GetStyle(STYLE_BORDER_WIDTH) == borderWidthValue));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the borderColor red
     * @tc.expected:step3.the borderColor of UILabelButton is red
     */
    const int color = 16711680;
    JerrySetNumberProperty(styleObj_, "borderColor", color);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_FALSE(button == nullptr);
    ColorType tempColor;
    tempColor.full = button->GetStyle(STYLE_BORDER_COLOR);
    EXPECT_TRUE(CompareColor(tempColor, color));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.step:step4.set the radius 1
     * @tc.expected:step4.the attribute of radius is 1
     */
    const int radiusNum = 1;
    JerrySetNumberProperty(styleObj_, "borderRadius", radiusNum);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_TRUE((button != nullptr) && (button->GetStyle(STYLE_BORDER_RADIUS) == 1));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps: step5:set the attribute backgroundColor red
     * @tc.expected: the backgroundColor of UILabelButton is red
     */
    const char *backgroundColor = "backgroundColor";
    JerrySetNumberProperty(styleObj_, backgroundColor, color);
    component = GetRenderedComponent(K_INPUT);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_FALSE(button == nullptr);
    tempColor.full = button->GetStyle(STYLE_BACKGROUND_COLOR);
    EXPECT_TRUE(CompareColor(tempColor, color));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputStyleTest09
 * @tc.desc: test checkbox width, height and id
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputStyleTest09, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps: step1.set the type attribute checkbox
     */
    JerrySetStringProperty(attrsObj_, "type", "checkbox");

    /**
     * @tc.steps:step2.set the attribute width 50
     * @tc.expected:step2.the width of checkbox is 50
     */
    const int widthValue = 50;
    JerrySetNumberProperty(styleObj_, "width", widthValue);
    Component * component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UICheckBox *checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetWidth() == widthValue));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the attribute height 20
     * @tc.expected:step3.the height of UILabelButton is 20
     */
    const int heightValue = 20;
    JerrySetNumberProperty(styleObj_, "height", heightValue);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetHeight() == heightValue));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step4.set the attribute id checkbox1
     * @tc.expected:step4.the attribute id of checkbox is checkbox1
     */
    JerrySetStringProperty(attrsObj_, "id", "checkbox1");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (!strcmp("checkbox1", checkbox->GetViewId())));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputStyleTest10
 * @tc.desc: test the margin style in checkbox
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputStyleTest10, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1: set the attribute type checkbox
     */
    JerrySetStringProperty(attrsObj_, "type", "checkbox");

    /**
     * @tc.steps:step2.set the attribute margin 10
     * @tc.expected:step2.the attribute margin of checkbox is 10
     */
    const int marginValue = 100;
    JerrySetNumberProperty(styleObj_, "margin", marginValue);
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UICheckBox *checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetStyle(STYLE_MARGIN_LEFT) == marginValue) && (checkbox->GetStyle(STYLE_MARGIN_RIGHT) == marginValue) &&
                (checkbox->GetStyle(STYLE_MARGIN_TOP) == marginValue) && (checkbox->GetStyle(STYLE_MARGIN_BOTTOM) == marginValue));
    component->Release();
    delete component;
    component = nullptr;
    /**
     * @tc.steps:step3.set the attribute marginLeft 10
     * @tc.expected:step3.the attribute margin left is 10
     */
    const int value = 20;
    JerrySetNumberProperty(styleObj_, "marginLeft", value);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetStyle(STYLE_MARGIN_LEFT) == value));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step4. set the attribute marginRight 10
     * @tc.expected:step4.the value of marginRight is 10
     */
    JerrySetNumberProperty(styleObj_, "marginRight", value);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetStyle(STYLE_MARGIN_RIGHT) == value));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step5.set the attribute marginTop 10
     * @tc.expected:step5.the marginRight attribute of checkbox is 10
     */
    JerrySetNumberProperty(styleObj_, "marginTop", value);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetStyle(STYLE_MARGIN_TOP) == value));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step6.set the attribute marginBottom 10
     * @tc.expected:step6.the attribute marginBottom of checkbox is 10
     */
    JerrySetNumberProperty(styleObj_, "marginBottom", value);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetStyle(STYLE_MARGIN_BOTTOM) == value));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputStyleTest11
 * @tc.desc: test the border and backgroundColor style in button
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputStyleTest11, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps: step1.set the attribute type checkbox
     */
    JerrySetStringProperty(attrsObj_, "type", "checkbox");

    /**
     * @tc.steps: step2:set the attribute borderWidth 2
     * @tc.expected: the borderWidth of checkbox is 2
     */
    const int borderWidthValue = 2;
    JerrySetNumberProperty(styleObj_, "borderWidth", borderWidthValue);
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UICheckBox *checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetStyle(STYLE_BORDER_WIDTH) == borderWidthValue));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the attribute borderColor red
     * @tc.expected:step3.the borderColor of checkbox is red
     */
    const int color = 16711680;
    JerrySetNumberProperty(styleObj_, "borderColor", color);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_FALSE(checkbox == nullptr);
    ColorType tempColor;
    tempColor.full = checkbox->GetStyle(STYLE_BORDER_COLOR);
    EXPECT_TRUE(CompareColor(tempColor, color));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps: step4.set the attribute radius 1
     * @tc.expected: step4.the style radius of checkbox is 1
     */
    const int radiusValue = 1;
    JerrySetNumberProperty(styleObj_, "borderRadius", radiusValue);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE((checkbox != nullptr) && (checkbox->GetStyle(STYLE_BORDER_RADIUS) == radiusValue));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step5.set the backgroundColor red
     * @tc.expected:step5.the backgroundColor of checkbox is red
     */
    JerrySetNumberProperty(styleObj_, "backgroundColor", color);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_TRUE(checkbox != nullptr);
    tempColor.full = checkbox->GetStyle(STYLE_BACKGROUND_COLOR);
    EXPECT_TRUE(CompareColor(tempColor, color));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputStyleTest12
 * @tc.desc: test the value attribute in input component
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputStyleTest12, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1.set the attribute type button and set the attribute checked true
     */
    JerrySetStringProperty(attrsObj_, "type", "button");
    AddBoolProperty(attrsObj_, "checked", false);

    /**
     * @tc.steps:step2.get the component
     * @tc.expected:step2.the type of component is button
     */
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UILabelButton *button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_FALSE(button == nullptr);
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the name attribute in checkbox
     * @tc.expected:step3.the type of component is checkbox
     */
    JerrySetStringProperty(attrsObj_, "name", "test");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    button = reinterpret_cast<UILabelButton *>(component->GetComponentRootView());
    EXPECT_FALSE(button == nullptr);
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputAttributeTest13
 * @tc.desc: test the unsupport attribute in checkbox
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputAttributeTest13, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1.set the attribute type checkbox
     * @tc.expected:step1.the create result is checkbox
     */
    JerrySetStringProperty(attrsObj_, "type", "checkbox");
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UICheckBox *checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_FALSE(checkbox == nullptr);
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step2.set the type value aaaa
     * @tc.expected:step2.the type of component is checkbox
     */
    JerrySetStringProperty(attrsObj_, "value", "aaaa");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_FALSE(checkbox == nullptr);
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the name attribute in checkbox
     * @tc.expected:step3.the type of component is checkbox
     */
    JerrySetStringProperty(attrsObj_, "name", "test");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_FALSE(checkbox == nullptr);
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentInputAttributeTest14
 * @tc.desc: test the not support style in checkbox
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentInputAttributeTest14, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1.set the type checkbox
     */
    JerrySetStringProperty(attrsObj_, "type", "checkbox");

    /**
     * @tc.steps:step2.set the fontSize style 38
     * @tc.expected:step2.create ui component checkbox
     */
    const uint8_t fontSize = 38;
    JerrySetNumberProperty(styleObj_, "fontSize", fontSize);
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UICheckBox *checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_FALSE(checkbox == nullptr);
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the color style red
     * @tc.expected:step3.create checkbox success
     */
    const int colorValue = 16711680;
    JerrySetNumberProperty(styleObj_, "color", colorValue);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_FALSE(checkbox == nullptr);
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps: step4.set the textAlign style left
     * @tc.expected:step4.create ui component checkbox
     */
    JerrySetStringProperty(styleObj_, "textAlign", "left");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    checkbox = reinterpret_cast<UICheckBox *>(component->GetComponentRootView());
    EXPECT_FALSE(checkbox == nullptr);
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentRadioAttributeTest01
 * @tc.desc: test the checked attribute in radioButton
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentRadioAttributeTest01, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1.set the type attribute radio
     * @tc.steps: create UIRadioButton
     */
    JerrySetStringProperty(attrsObj_, "type", "radio");

    /**
     * @steps:step2.set the attribute checked true
     * @expected:step2.the state of radioButton is selected
     */
    AddBoolProperty(attrsObj_, "checked", true);
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UIRadioButton *radio = reinterpret_cast<UIRadioButton *>(component->GetComponentRootView());
    EXPECT_FALSE((radio == nullptr) && (radio->GetState() == UICheckBox::UICheckBoxState::SELECTED));
component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the attribute checked false
     * @tc.expected:step3.the state of radioButton is unselected
     */
    AddBoolProperty(attrsObj_, "checked", false);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    radio = reinterpret_cast<UIRadioButton *>(component->GetComponentRootView());
    EXPECT_FALSE((radio == nullptr) && (radio->GetState() == UICheckBox::UICheckBoxState::UNSELECTED));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @steps: step4:set the attribute checked aaaa
     * @expected: the state of radio is unselected
     */
    JerrySetStringProperty(attrsObj_, "checked", "aaaa");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    radio = reinterpret_cast<UIRadioButton *>(component->GetComponentRootView());
    EXPECT_FALSE((radio == nullptr) && (radio->GetState() == UICheckBox::UICheckBoxState::SELECTED));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentRadioStyleTest03
 * @tc.desc: test the border style in button
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentRadioStyleTest03, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1:set the attribute type radio
     */
    JerrySetStringProperty(attrsObj_, "type", "radio");

    /**
     * @tc.steps:step2.set the radio border width 2
     * @tc.expected:step2.the border width of radio is 2
     */
    const int borderWidthVal = 2;
    JerrySetNumberProperty(styleObj_, "borderWidth", borderWidthVal);
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UIRadioButton *radioButton = reinterpret_cast<UIRadioButton *>(component->GetComponentRootView());
    EXPECT_TRUE((radioButton != nullptr) && (radioButton->GetStyle(STYLE_BORDER_WIDTH) == borderWidthVal));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the borderRadius 100
     * @tc.expected:step3.the borderRadius of radioButton is 100
     */
    const int radiusVal = 100;
    JerrySetNumberProperty(styleObj_, "borderRadius", radiusVal);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    radioButton = reinterpret_cast<UIRadioButton *>(component->GetComponentRootView());
    EXPECT_TRUE((radioButton != nullptr) && (radioButton->GetStyle(STYLE_BORDER_RADIUS) == radiusVal));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step4.set the background color of radioButton red
     * @tc.expected:step4.the background color of radiobutton is red
     */
    const int32_t redValue = 16711680;
    JerrySetNumberProperty(styleObj_, "backgroundColor", redValue);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    radioButton = reinterpret_cast<UIRadioButton *>(component->GetComponentRootView());
    EXPECT_FALSE(radioButton == nullptr);
    ColorType bgColor;
    bgColor.full = radioButton->GetStyle(STYLE_BACKGROUND_COLOR);
    EXPECT_TRUE(CompareColor(bgColor, redValue));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

/**
 * @tc.name: ComponentRadioStyleTest04
 * @tc.desc: test set radio width, height and id
 * @tc.require: AR000DSEFK
 */
HWTEST_F(InputTddTest, ComponentRadioStyleTest04, TestSize.Level1)
{
    TDD_CASE_BEGIN();
    /**
     * @tc.steps:step1.set the attribute type radio
     */
    JerrySetStringProperty(attrsObj_, "type", "radio");

    /**
     * @tc.steps:step2.set the radio width 50
     * @tc.expected:step2.the width of radio is 50
     */
    const int widthVal = 50;
    JerrySetNumberProperty(styleObj_, "width", widthVal);
    Component *component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    UIRadioButton *radioButton = reinterpret_cast<UIRadioButton *>(component->GetComponentRootView());
    EXPECT_TRUE((radioButton != nullptr) && (radioButton->GetWidth() == widthVal));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step3.set the radiobutton height 50
     * @tc.expected:step3.the height of radioButton is 50
     */
    const int heightVal = 50;
    JerrySetNumberProperty(styleObj_, "height", heightVal);
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    radioButton = reinterpret_cast<UIRadioButton *>(component->GetComponentRootView());
    EXPECT_TRUE((radioButton != nullptr) && (radioButton->GetHeight() == heightVal));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps: step4.set the attribute id radio1
     * @tc.expected:step4.the id of radioButton is radio1
     */
    JerrySetStringProperty(attrsObj_, "id", "radio1");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    radioButton = reinterpret_cast<UIRadioButton *>(component->GetComponentRootView());
    EXPECT_TRUE((radioButton != nullptr) && (!strcmp("radio1", radioButton->GetViewId())));
    component->Release();
    delete component;
    component = nullptr;

    /**
     * @tc.steps:step5.set the style display none
     * @tc.expected:step5.the visible of radiobutton is false
     */
    JerrySetStringProperty(styleObj_, "display", "none");
    component = GetRenderedComponent(K_INPUT);
    EXPECT_FALSE(component == nullptr);
    radioButton = reinterpret_cast<UIRadioButton *>(component->GetComponentRootView());
    EXPECT_TRUE((radioButton != nullptr) && (!radioButton->IsVisible()));
    component->Release();
    delete component;
    component = nullptr;
    TDD_CASE_END();
}

#ifndef TDD_ASSERTIONS
void InputTddTest::RunTests()
{
    ComponentInputAttributeTest01();
    ComponentInputAttributeTest02();
    ComponentInputStyleTest03();
    ComponentInputStyleTest04();
    ComponentInputAttributeTest05();
    ComponentInputAttributeTest06();
    ComponentInputStyleTest07();
    ComponentInputStyleTest08();
    ComponentInputStyleTest09();
    ComponentInputStyleTest10();
    ComponentInputStyleTest11();
    ComponentInputStyleTest12();
    ComponentInputAttributeTest13();
    ComponentInputAttributeTest14();
    ComponentRadioAttributeTest01();
    ComponentRadioStyleTest03();
    ComponentRadioStyleTest04();
}
#endif
}
}
