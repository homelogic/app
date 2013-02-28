#############################################################################
# Makefile for building: HomeLogic
# Generated by qmake (3.0) (Qt 5.0.1) on: Wed Feb 27 22:27:01 2013
# Project:  HomeLogic.pro
# Template: app
# Command: D:\Qt\Qt5.0.1\5.0.1\mingw47_32\bin\qmake.exe -spec win32-g++ CONFIG+=debug CONFIG+=declarative_debug CONFIG+=qml_debug -o Makefile HomeLogic.pro
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = D:\Qt\Qt5.0.1\5.0.1\mingw47_32\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: HomeLogic.pro ../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/win32-g++/qmake.conf ../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/spec_pre.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/device_config.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/common/shell-win32.conf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/qconfig.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_axbase.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_axcontainer.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_axserver.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_bootstrap.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_clucene.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_concurrent.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_core.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_declarative.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_designer.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_designercomponents.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_gui.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_help.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_multimedia.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_network.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_opengl.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_platformsupport.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_printsupport.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_qml.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_qmldevtools.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_qmltest.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_qtmultimediaquicktools.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_quick.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_quickparticles.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_script.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_scripttools.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_serialport.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_sql.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_svg.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_testlib.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_uitools.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_v8.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_webkit.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_widgets.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_xml.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/qt_functions.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/qt_config.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/win32-g++/qmake.conf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/spec_post.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/exclusive_builds.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/default_pre.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/win32/default_pre.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/debug.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/debug_and_release.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/default_post.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/shared.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/qml_debug.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/declarative_debug.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/win32/rtti.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/warn_on.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/qt.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/resources.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/moc.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/win32/opengl.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/uic.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/win32/windows.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/testcase_targets.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/exceptions.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/yacc.prf \
		../../../../../../../Qt/Qt5.0.1/5.0.1/mingw47_32/mkspecs/features/lex.prf \
		HomeLogic.pro \
		D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/Qt5Widgets.prl \
		D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/Qt5Sql.prl \
		D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/Qt5SerialPort.prl \
		D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/Qt5Gui.prl \
		D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/Qt5Core.prl \
		D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/libEGLd.prl \
		D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/libGLESv2d.prl
	$(QMAKE) -spec win32-g++ CONFIG+=debug CONFIG+=declarative_debug CONFIG+=qml_debug -o Makefile HomeLogic.pro
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\spec_pre.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\device_config.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\common\shell-win32.conf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\qconfig.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_axbase.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_axcontainer.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_axserver.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_bootstrap.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_clucene.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_concurrent.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_core.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_declarative.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_designer.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_designercomponents.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_gui.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_help.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_multimedia.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_multimediawidgets.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_network.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_opengl.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_platformsupport.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_printsupport.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_qml.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_qmldevtools.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_qmltest.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_qtmultimediaquicktools.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_quick.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_quickparticles.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_script.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_scripttools.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_serialport.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_sql.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_svg.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_testlib.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_uitools.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_v8.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_webkit.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_webkitwidgets.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_widgets.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_xml.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\modules\qt_lib_xmlpatterns.pri:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\qt_functions.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\qt_config.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\win32-g++\qmake.conf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\spec_post.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\exclusive_builds.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\default_pre.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\win32\default_pre.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\debug.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\debug_and_release.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\default_post.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\shared.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\qml_debug.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\declarative_debug.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\win32\rtti.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\warn_on.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\qt.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\resources.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\moc.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\win32\opengl.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\uic.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\win32\windows.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\testcase_targets.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\exceptions.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\yacc.prf:
..\..\..\..\..\..\..\Qt\Qt5.0.1\5.0.1\mingw47_32\mkspecs\features\lex.prf:
HomeLogic.pro:
D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/Qt5Widgets.prl:
D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/Qt5Sql.prl:
D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/Qt5SerialPort.prl:
D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/Qt5Gui.prl:
D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/Qt5Core.prl:
D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/libEGLd.prl:
D:/Qt/Qt5.0.1/5.0.1/mingw47_32/lib/libGLESv2d.prl:
qmake: FORCE
	@$(QMAKE) -spec win32-g++ CONFIG+=debug CONFIG+=declarative_debug CONFIG+=qml_debug -o Makefile HomeLogic.pro

qmake_all: FORCE

make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
