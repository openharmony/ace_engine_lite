TEMPLATE = lib
CONFIG += staticlib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LOSCFG_TEST_JS_BUILD = false
is_debug = debug

DESTDIR = ../libs

DEFINES  -= UNICODE
DEFINES  -= FEATURE_TIMER_MODULE
DEFINES += TARGET_SIMULATOR
DEFINES += JS_ENGINE_EXTERNAL_CONTEXT
DEFINES += SCREENSIZE_SPECIFIED
DEFINES += JS_PROFILER=0
DEFINES += QT_SIMULATOR

eval(is_debug == release) {
    DEFINES += JS_PROFILER=1
}

LOSCFG_TEST_JS_BUILD {
    DEFINES += JSFWK_TEST
}


SOURCES += \
        ../../../../src/core/animation/transition_impl.cpp \
        #../../../../src/core/async/js_async_work.cpp \
        #../../../../src/core/async/message_queue_utils.cpp \
        ../../../../src/core/base/ace_log.cpp \
        ../../../../src/core/base/ace_mem_base.cpp \
        ../../../../src/core/base/dft_impl.cpp \
        ../../../../src/core/base/async_task_manager.cpp \
        ../../../../src/core/base/cache/cache_manager.cpp \
        ../../../../src/core/base/dfx_assist.cpp \
        ../../../../src/core/base/event_util.cpp \
        ../../../../src/core/base/js_debugger_config.cpp \
        ../../../../src/core/base/js_fwk_common.cpp \
        ../../../../src/core/base/key_parser.cpp \
        ../../../../src/core/base/lazy_load_manager.cpp \
        ../../../../src/core/base/lazy_load_watcher.cpp \
        ../../../../src/core/base/locale_util.cpp \
        ../../../../src/core/base/mem_proc.cpp \
        ../../../../src/core/base/memory_heap.cpp \
        ../../../../src/core/base/number_parser.cpp \
        ../../../../src/core/base/product_adapter.cpp \
        ../../../../src/core/base/string_util.cpp \
        ../../../../src/core/base/time_util.cpp \
        ../../../../src/core/components/analog_clock_component.cpp \
        ../../../../src/core/components/camera_component.cpp \
        ../../../../src/core/components/canvas_component.cpp \
        ../../../../src/core/components/chart_component.cpp \
        ../../../../src/core/components/circle_progress_component.cpp \
        ../../../../src/core/components/clock_hand_component.cpp \
        ../../../../src/core/components/component.cpp \
        ../../../../src/core/components/component_utils.cpp \
        ../../../../src/core/components/div_component.cpp \
        ../../../../src/core/components/event_listener.cpp \
        ../../../../src/core/components/horizon_progress_component.cpp \
        ../../../../src/core/components/image_animator_component.cpp \
        ../../../../src/core/components/image_component.cpp \
        ../../../../src/core/components/input_button_component.cpp \
        ../../../../src/core/components/input_checkbox_component.cpp \
        ../../../../src/core/components/input_radio_component.cpp \
        ../../../../src/core/components/list_adapter.cpp \
        ../../../../src/core/components/list_component.cpp \
        ../../../../src/core/components/marquee_component.cpp \
        ../../../../src/core/components/panel_view.cpp \
        ../../../../src/core/components/picker_view_component.cpp \
        ../../../../src/core/components/qrcode_component.cpp \
        ../../../../src/core/components/scroll_layer.cpp \
        ../../../../src/core/components/slider_component.cpp \
        ../../../../src/core/components/stack_component.cpp \
        ../../../../src/core/components/swiper_component.cpp \
        ../../../../src/core/components/switch_component.cpp \
        ../../../../src/core/components/tab_bar_component.cpp \
        ../../../../src/core/components/tab_content_component.cpp \
        ../../../../src/core/components/tabs_component.cpp \
        ../../../../src/core/components/text_component.cpp \
        ../../../../src/core/components/video_component.cpp \
        ../../../../src/core/components/video_view.cpp \
        #../../../../src/core/context/ace_ability.cpp \
        ../../../../src/core/context/ace_event_error_code.cpp \
        ../../../../src/core/context/fatal_handler.cpp \
        ../../../../src/core/context/js_ability.cpp \
        ../../../../src/core/context/js_ability_impl.cpp \
        ../../../../src/core/context/js_app_context.cpp \
        ../../../../src/core/context/js_app_environment.cpp \
        ../../../../src/core/context/js_framework_raw.cpp \
        ../../../../src/core/context/js_profiler.cpp \
        ../../../../src/core/context/js_timer_list.cpp \
        ../../../../src/core/dialog/js_dialog.cpp \
        ../../../../src/core/directive/descriptor_utils.cpp \
        ../../../../src/core/directive/directive_watcher_callback.cpp \
        ../../../../src/core/jsi/jsi.cpp \
        ../../../../src/core/modules/app_module.cpp \
        ../../../../src/core/modules/dfx_module.cpp \
        ../../../../src/core/modules/dialog_module.cpp \
        ../../../../src/core/modules/module_manager.cpp \
        ../../../../src/core/modules/presets/cjson_parser.cpp \
        ../../../../src/core/modules/presets/console_log_impl.cpp \
        ../../../../src/core/modules/presets/console_module.cpp \
        ../../../../src/core/modules/presets/date_time_format_module.cpp \
        ../../../../src/core/modules/presets/intl_module.cpp \
        ../../../../src/core/modules/presets/localization_module.cpp \
        ../../../../src/core/modules/presets/number_format_module.cpp \
        ../../../../src/core/modules/presets/preset_module.cpp \
        ../../../../src/core/modules/presets/profiler_module.cpp \
        ../../../../src/core/modules/presets/render_module.cpp \
        ../../../../src/core/modules/presets/require_module.cpp \
        ../../../../src/core/modules/presets/timer_module.cpp \
        ../../../../src/core/modules/presets/version_module.cpp \
        ../../../../src/core/modules/router_module.cpp \
        ../../../../src/core/modules/sample_module.cpp \
        ../../../../src/core/resource/video_muted_image_res.cpp \
        ../../../../src/core/resource/video_play_image_res.cpp \
        ../../../../src/core/router/js_page_state.cpp \
        ../../../../src/core/router/js_page_state_machine.cpp \
        ../../../../src/core/router/js_router.cpp \
        ../../../../src/core/stylemgr/app_style.cpp \
        ../../../../src/core/stylemgr/app_style_item.cpp \
        ../../../../src/core/stylemgr/app_style_list.cpp \
        ../../../../src/core/stylemgr/app_style_manager.cpp \
        ../../../../src/core/stylemgr/app_style_sheet.cpp \
        ../../../../src/core/wrapper/js.cpp \
        ../../../../targets/platform_adapter.cpp \
        #../../../../src/core/modules/presets/feature_ability_module.cpp \
        targets/simulator/mock/async_work_manager.cpp \
        targets/simulator/mock/hal_sys_param.cpp \
        targets/simulator/mock/js_async_work.cpp

HEADERS += \
        ../../../../../../../../foundation/graphic/ui/interfaces/kits/components/ui_view.h \
        targets/simulator/mock/async_work_manager.h


INCLUDEPATH += \
            ../../../../../../../../foundation/graphic/ui/interfaces/innerkits \
            ../../../../../../../../foundation/graphic/ui/interfaces/innerkits/common \
            ../../../../../../../../foundation/graphic/ui/interfaces/innerkits/dock \
            ../../../../../../../../foundation/graphic/ui/interfaces/innerkits/font \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/animator \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/common \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/components \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/dfx \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/events \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/font \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/layout \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/themes \
            ../../../../../../../../foundation/graphic/utils/frameworks/windows \
            ../../../../../../../../foundation/graphic/utils/interfaces/innerkits \
            ../../../../../../../../foundation/graphic/utils/interfaces/kits \
            ../../../../../../../../foundation/graphic/ui/interfaces/innerkits/ui/common \
            ../../../../../../../../foundation/communication/ipc_lite/interfaces/kits \
            ../../../../../../../../base/hiviewdfx/hilog_lite/interfaces/native/kits \
            ../../../../../../../../foundation/aafwk/aafwk_lite/interfaces/kits/ability_lite \
            ../../../../../../../../foundation/aafwk/aafwk_lite/interfaces/kits/want_lite \
            ../../../../../../../../foundation/aafwk/aafwk_lite/interfaces/innerkits/abilitymgr_lite \
            ../../../../../../../../foundation/appexecfwk/appexecfwk_lite/interfaces/kits/bundle_lite \
            ../../../../../../../../foundation/appexecfwk/appexecfwk_lite/utils/bundle_lite \
            ../../../../../../../../foundation/communication/ipc_lite/liteipc/include \
            ../../../../../../../../third_party/bounds_checking_function/include \
            ../../../../../../../../foundation/ace/ace_engine_lite/interfaces/innerkits/builtin/async \
            ../../../../../../../../foundation/ace/ace_engine_lite/interfaces/innerkits/builtin/base \
            ../../../../../../../../foundation/ace/ace_engine_lite/interfaces/innerkits/builtin/jsi \
            ../../../../include/context \
            ../../../../include/base \
            ../../../../include/modules \
            ../../../../include/resource \
            ../../../../src/core \
            ../../../../src/core/animation \
            ../../../../src/core/base \
            ../../../../src/core/base/cache \
            ../../../../src/core/components \
            ../../../../src/core/context \
            ../../../../src/core/directive \
            ../../../../src/core/router \
            ../../../../src/core/jsi \
            ../../../../src/core/modules \
            ../../../../src/core/router \
            ../../../../src/core/stylemgr \
            ../../../../src/core/wrapper \
            ../../../../targets \
            targets/simulator \
            targets/simulator/mock \
            ../../../../../../../../kernel/liteos_a/kernel/include/ \
            ../../../../../../../../kernel/liteos_a/kernel/common \
            ../../../../../../../../third_party/jerryscript/jerry-core/include \
            ../../../../../../../../third_party/jerryscript/jerry-ext/include/jerryscript-ext \
            ../../../../../../../..//third_party/jerryscript/jerry-port/default/include \
            ../../../../../../../../third_party/cJSON \
            ../../../../../../../../utils/native/lite/timer_task/include/ \
            ../../../../../../../../third_party/freetype/include \
            ../../../../../../../../base/global/resmgr_lite/interfaces/innerkits/include \
            ../../../../../../../../base/global/i18n_lite/interfaces/kits/i18n/include \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/ui \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/config \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/ui/animator \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/ui/common \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/ui/components \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/ui/dfx \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/ui/events \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/ui/font \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/ui/layout \
            ../../../../../../../../foundation/graphic/ui/interfaces/kits/ui/themes \
            ../../../../../../../../foundation/graphic/ui/interfaces/innerkits/ui/common \
            ../../../../../../../../foundation/communication/ipc_lite/interfaces/kits \
            ../../../../../../../../base/hiviewdfx/hilog_lite/interfaces/native/kits \
            ../../../../../../../../foundation/aafwk/aafwk_lite/frameworks/abilitymgr_lite/include \
            ../../../../../../../../foundation/communication/ipc_lite/liteipc/include \
