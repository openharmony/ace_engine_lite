TEMPLATE = subdirs
CONFIG += ordered

COPY_DEST = $$replace(OUT_PWD, /, \\)
system("mkdir $$COPY_DEST\\simulator\\font")
system("copy ..\\..\\..\\..\\..\\..\\graphic\\ui\\tools\\qt\\simulator\\font\\SourceHanSansSC-Regular.otf $$COPY_DEST\\simulator\\font")

SUBDIRS += \
    ../../../../../../graphic/ui/tools/qt/simulator/libui \
    ../../../../../../graphic/ui/tools/qt/simulator/third_party/freetype \
    ../../../../../../graphic/ui/tools/qt/simulator/third_party/harfbuzz \
    ../../../../../../graphic/ui/tools/qt/simulator/third_party/icu \
    ../../../../../../graphic/ui/tools/qt/simulator/third_party/libjpeg \
    ../../../../../../graphic/ui/tools/qt/simulator/third_party/libpng \
    ../../../../../../graphic/ui/tools/qt/simulator/third_party/qrcodegen \
    ../../../../../../graphic/ui/tools/qt/simulator/third_party/zlib \
    cjson \
    jerryScript \
    jsfwk \
    entry/entry.pro