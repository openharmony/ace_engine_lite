CONFIG -= qt
TEMPLATE = lib
CONFIG += staticlib

CONFIG -= app_bundle

DESTDIR = ../libs

LIBS += -lpthread libwsock32 libws2_32


DEFINES += JERRY_CPOINTER_32_BIT=0
DEFINES += JERRY_DEBUGGER=0
DEFINES += JERRY_ES2015=0
DEFINES += JERRY_EXTERNAL_CONTEXT=1
DEFINES += JERRY_FUNCTION_BACKTRACE
DEFINES += JERRY_FUNCTION_NAME
DEFINES += JERRY_GC_LIMIT=(0)
//DEFINES += JERRY_HEAPDUMP
DEFINES += JERRY_LINE_INFO=1
DEFINES += JERRY_MEM_GC_BEFORE_EACH_ALLOC=0
DEFINES += JERRY_NDEBUG
DEFINES += JERRY_PARSER=1
DEFINES += JERRY_PARSER_DUMP_BYTE_CODE=0
DEFINES += JERRY_REF_TRACKER
DEFINES += JERRY_REGEXP_DUMP_BYTE_CODE=0
DEFINES += JERRY_REGEXP_STRICT_MODE=0
DEFINES += JERRY_STACK_LIMIT=(0)
DEFINES += JERRY_SYSTEM_ALLOCATOR=0
DEFINES += JERRY_VALGRIND=0
DEFINES += JERRY_VM_EXEC_STOP=0

INCLUDEPATH += \
        ../../../../../../../../third_party/jerryscript/jerry-core/include \
        ../../../../../../../../third_party/jerryscript/jerry-core/api \
        ../../../../../../../../third_party/jerryscript/jerry-core/debugger \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations \
        ../../../../../../../../third_party/jerryscript/jerry-core/ext \
        ../../../../../../../../third_party/jerryscript/jerry-core/jcontext \
        ../../../../../../../../third_party/jerryscript/jerry-core/jmem \
        ../../../../../../../../third_party/jerryscript/jerry-core/jrt \
        ../../../../../../../../third_party/jerryscript/jerry-core/lit \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/regexp \
        ../../../../../../../../third_party/jerryscript/jerry-core/vm \
        ../../../../../../../../third_party/jerryscript/jerry-core \
        ../../../../../../../../third_party/jerryscript/jerry-ext/debugger \
        ../../../../../../../../third_party/jerryscript/jerry-ext/common \
        ../../../../../../../../third_party/jerryscript/jerry-ext/include \
        ../../../../../../../../third_party/jerryscript/jerry-ext/arg \
        ../../../../../../../../third_party/jerryscript/jerry-ext/handle-scope \
        ../../../../../../../../third_party/jerryscript/jerry-port/default/include \
        # ../../../../../../../../third_party/jerryscript/jerry-libm/include


SOURCES += \
        ../../../../../../../../third_party/jerryscript/jerry-core/api/jerry-debugger-transport.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/api/jerry-debugger.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/api/jerry-snapshot.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/api/jerry.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/debugger/debugger.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-alloc.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-gc.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-helpers-collection.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-helpers-conversion.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-helpers-errol.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-helpers-external-pointers.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-helpers-number.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-helpers-string.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-helpers-value.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-helpers.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-init-finalize.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-lcache.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-literal-storage.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-module.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/base/ecma-property-hashmap.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-array-iterator-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-array-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-array.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-arraybuffer-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-arraybuffer.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-boolean-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-boolean.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-dataview-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-dataview.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-date-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-date.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-error-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-error.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-evalerror-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-evalerror.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-function-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-function.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-global.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-helpers-date.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-helpers-error.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-helpers-json.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-helpers-sort.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-helpers.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-iterator-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-json.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-map-iterator-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-map-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-map.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-math.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-number-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-number.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-object-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-promise-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-promise.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-rangeerror-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-rangeerror.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-referenceerror-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-referenceerror.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-regexp-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-regexp.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-set-iterator-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-set-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-set.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-string-iterator-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-string-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-string.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-symbol-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-symbol.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-syntaxerror-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-syntaxerror.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-type-error-thrower.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-typeerror-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-typeerror.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-urierror-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-urierror.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtins.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-float32array-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-float32array.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-float64array-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-float64array.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-int16array-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-int16array.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-int32array-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-int32array.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-int8array-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-int8array.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-typedarray-helpers.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-typedarray-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-typedarray.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-uint16array-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-uint16array.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-uint32array-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-uint32array.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-uint8array-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-uint8array.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-uint8clampedarray-prototype.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/builtin-objects/typedarray/ecma-builtin-uint8clampedarray.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-array-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-arraybuffer-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-boolean-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-comparison.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-container-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-conversion.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-dataview-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-eval.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-exceptions.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-function-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-get-put-value.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-iterator-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-jobqueue.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-lex-env.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-number-arithmetic.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-number-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-objects-arguments.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-objects-general.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-objects.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-promise-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-reference.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-regexp-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-string-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-symbol-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ecma/operations/ecma-typedarray-object.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ext/ext-utils.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ext/heapdump.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/ext/tracker.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/jcontext/jcontext.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/jmem/jmem-allocator.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/jmem/jmem-heap.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/jmem/jmem-poolman.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/jrt/jrt-fatals.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/lit/lit-char-helpers.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/lit/lit-magic-strings.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/lit/lit-strings.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js/byte-code.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js/common.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js/js-lexer.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js/js-parser-expr.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js/js-parser-mem.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js/js-parser-module.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js/js-parser-statm.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js/js-parser-util.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js/js-parser.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js/js-scanner-util.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/js/js-scanner.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/regexp/re-bytecode.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/regexp/re-compiler.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/parser/regexp/re-parser.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/vm/opcodes-ecma-arithmetics.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/vm/opcodes-ecma-bitwise.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/vm/opcodes-ecma-relational-equality.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/vm/opcodes.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/vm/vm-stack.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/vm/vm-utils.c \
        ../../../../../../../../third_party/jerryscript/jerry-core/vm/vm.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/arg/arg-js-iterator-helper.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/arg/arg-transform-functions.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/arg/arg.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/debugger/debugger-common.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/debugger/debugger-rp.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/debugger/debugger-serial.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/debugger/debugger-sha1.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/debugger/debugger-tcp.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/debugger/debugger-ws.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/handle-scope/handle-scope-allocator.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/handle-scope/handle-scope.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/handler/handler-assert.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/handler/handler-gc.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/handler/handler-print.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/handler/handler-register.c \
        ../../../../../../../../third_party/jerryscript/jerry-ext/module/module.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/acos.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/asin.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/atan.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/atan2.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/ceil.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/copysign.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/exp.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/fabs.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/finite.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/floor.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/fmod.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/isnan.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/log.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/nextafter.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/pow.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/scalbn.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/sqrt.c \
        #../../../../../../../../third_party/jerryscript/jerry-libm/trig.c \
        ../../../../../../../../third_party/jerryscript/jerry-port/default/default-date.c \
        ../../../../../../../../third_party/jerryscript/jerry-port/default/default-debugger.c \
        ../../../../../../../../third_party/jerryscript/jerry-port/default/default-external-context.c \
        ../../../../../../../../third_party/jerryscript/jerry-port/default/default-fatal.c \
        ../../../../../../../../third_party/jerryscript/jerry-port/default/default-io.c \
        ../../../../../../../../third_party/jerryscript/jerry-port/default/default-module.c
