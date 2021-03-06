#############################################################################
# Makefile for building: GraphEditor.app/Contents/MacOS/GraphEditor
# Generated by qmake (2.01a) (Qt 4.6.0) on: Th 4 thg 12 23 23:33:24 2009
# Project:  GraphEditor.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/local/Qt4.6/mkspecs/macx-g++ -macx -o Makefile GraphEditor.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -gdwarf-2 -arch i386 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -gdwarf-2 -arch i386 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Qt4.6/mkspecs/macx-g++ -I. -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/Library/Frameworks/QtXml.framework/Versions/4/Headers -I/usr/include/QtXml -I/usr/include -I. -I. -F/Library/Frameworks
LINK          = g++
LFLAGS        = -headerpad_max_install_names -arch i386
LIBS          = $(SUBLIBS) -F/Library/Frameworks -L/Library/Frameworks -framework QtXml -framework QtGui -framework QtCore 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		taskdialog.cpp \
		diagramscene.cpp \
		edgexml.cpp \
		node.cpp \
		nodexml.cpp \
		task.cpp \
		xmlprovider.cpp moc_mainwindow.cpp \
		moc_taskdialog.cpp \
		moc_diagramscene.cpp \
		qrc_resource.cpp
OBJECTS       = main.o \
		mainwindow.o \
		taskdialog.o \
		diagramscene.o \
		edgexml.o \
		node.o \
		nodexml.o \
		task.o \
		xmlprovider.o \
		moc_mainwindow.o \
		moc_taskdialog.o \
		moc_diagramscene.o \
		qrc_resource.o
DIST          = /usr/local/Qt4.6/mkspecs/common/unix.conf \
		/usr/local/Qt4.6/mkspecs/common/mac.conf \
		/usr/local/Qt4.6/mkspecs/common/mac-g++.conf \
		/usr/local/Qt4.6/mkspecs/qconfig.pri \
		/usr/local/Qt4.6/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.6/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.6/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.6/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.6/mkspecs/features/debug.prf \
		/usr/local/Qt4.6/mkspecs/features/default_post.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/x86.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.6/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.6/mkspecs/features/qt.prf \
		/usr/local/Qt4.6/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.6/mkspecs/features/moc.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.6/mkspecs/features/resources.prf \
		/usr/local/Qt4.6/mkspecs/features/uic.prf \
		/usr/local/Qt4.6/mkspecs/features/yacc.prf \
		/usr/local/Qt4.6/mkspecs/features/lex.prf \
		/usr/local/Qt4.6/mkspecs/features/include_source_dir.prf \
		GraphEditor.pro
QMAKE_TARGET  = GraphEditor
DESTDIR       = 
TARGET        = GraphEditor.app/Contents/MacOS/GraphEditor

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-gdwarf-2 \
		-arch \
		i386 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile GraphEditor.app/Contents/PkgInfo GraphEditor.app/Contents/Resources/empty.lproj GraphEditor.app/Contents/Info.plist $(TARGET)

$(TARGET): ui_mainwindow.h ui_taskdialog.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) GraphEditor.app/Contents/MacOS/ || $(MKDIR) GraphEditor.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: GraphEditor.pro  /usr/local/Qt4.6/mkspecs/macx-g++/qmake.conf /usr/local/Qt4.6/mkspecs/common/unix.conf \
		/usr/local/Qt4.6/mkspecs/common/mac.conf \
		/usr/local/Qt4.6/mkspecs/common/mac-g++.conf \
		/usr/local/Qt4.6/mkspecs/qconfig.pri \
		/usr/local/Qt4.6/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.6/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.6/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.6/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.6/mkspecs/features/debug.prf \
		/usr/local/Qt4.6/mkspecs/features/default_post.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/x86.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.6/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.6/mkspecs/features/qt.prf \
		/usr/local/Qt4.6/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.6/mkspecs/features/moc.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.6/mkspecs/features/resources.prf \
		/usr/local/Qt4.6/mkspecs/features/uic.prf \
		/usr/local/Qt4.6/mkspecs/features/yacc.prf \
		/usr/local/Qt4.6/mkspecs/features/lex.prf \
		/usr/local/Qt4.6/mkspecs/features/include_source_dir.prf \
		/Library/Frameworks/QtXml.framework/QtXml.prl \
		/Library/Frameworks/QtCore.framework/QtCore.prl \
		/Library/Frameworks/QtGui.framework/QtGui.prl
	$(QMAKE) -spec /usr/local/Qt4.6/mkspecs/macx-g++ -macx -o Makefile GraphEditor.pro
/usr/local/Qt4.6/mkspecs/common/unix.conf:
/usr/local/Qt4.6/mkspecs/common/mac.conf:
/usr/local/Qt4.6/mkspecs/common/mac-g++.conf:
/usr/local/Qt4.6/mkspecs/qconfig.pri:
/usr/local/Qt4.6/mkspecs/features/qt_functions.prf:
/usr/local/Qt4.6/mkspecs/features/qt_config.prf:
/usr/local/Qt4.6/mkspecs/features/exclusive_builds.prf:
/usr/local/Qt4.6/mkspecs/features/default_pre.prf:
/usr/local/Qt4.6/mkspecs/features/mac/default_pre.prf:
/usr/local/Qt4.6/mkspecs/features/mac/dwarf2.prf:
/usr/local/Qt4.6/mkspecs/features/debug.prf:
/usr/local/Qt4.6/mkspecs/features/default_post.prf:
/usr/local/Qt4.6/mkspecs/features/mac/default_post.prf:
/usr/local/Qt4.6/mkspecs/features/mac/x86.prf:
/usr/local/Qt4.6/mkspecs/features/mac/objective_c.prf:
/usr/local/Qt4.6/mkspecs/features/warn_on.prf:
/usr/local/Qt4.6/mkspecs/features/qt.prf:
/usr/local/Qt4.6/mkspecs/features/unix/thread.prf:
/usr/local/Qt4.6/mkspecs/features/moc.prf:
/usr/local/Qt4.6/mkspecs/features/mac/rez.prf:
/usr/local/Qt4.6/mkspecs/features/mac/sdk.prf:
/usr/local/Qt4.6/mkspecs/features/resources.prf:
/usr/local/Qt4.6/mkspecs/features/uic.prf:
/usr/local/Qt4.6/mkspecs/features/yacc.prf:
/usr/local/Qt4.6/mkspecs/features/lex.prf:
/usr/local/Qt4.6/mkspecs/features/include_source_dir.prf:
/Library/Frameworks/QtXml.framework/QtXml.prl:
/Library/Frameworks/QtCore.framework/QtCore.prl:
/Library/Frameworks/QtGui.framework/QtGui.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/local/Qt4.6/mkspecs/macx-g++ -macx -o Makefile GraphEditor.pro

GraphEditor.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) GraphEditor.app/Contents || $(MKDIR) GraphEditor.app/Contents 
	@$(DEL_FILE) GraphEditor.app/Contents/PkgInfo
	@echo "APPL????" >GraphEditor.app/Contents/PkgInfo
GraphEditor.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) GraphEditor.app/Contents/Resources || $(MKDIR) GraphEditor.app/Contents/Resources 
	@touch GraphEditor.app/Contents/Resources/empty.lproj
	
GraphEditor.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) GraphEditor.app/Contents || $(MKDIR) GraphEditor.app/Contents 
	@$(DEL_FILE) GraphEditor.app/Contents/Info.plist
	@sed -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,GraphEditor,g" -e "s,@TYPEINFO@,????,g" /usr/local/Qt4.6/mkspecs/macx-g++/Info.plist.app >GraphEditor.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/GraphEditor1.0.0 || $(MKDIR) .tmp/GraphEditor1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/GraphEditor1.0.0/ && $(COPY_FILE) --parents mainwindow.h taskdialog.h diagramscene.h edgexml.h node.h nodexml.h task.h xmlprovider.h .tmp/GraphEditor1.0.0/ && $(COPY_FILE) --parents resource.qrc .tmp/GraphEditor1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp taskdialog.cpp diagramscene.cpp edgexml.cpp node.cpp nodexml.cpp task.cpp xmlprovider.cpp .tmp/GraphEditor1.0.0/ && $(COPY_FILE) --parents mainwindow.ui taskdialog.ui .tmp/GraphEditor1.0.0/ && (cd `dirname .tmp/GraphEditor1.0.0` && $(TAR) GraphEditor1.0.0.tar GraphEditor1.0.0 && $(COMPRESS) GraphEditor1.0.0.tar) && $(MOVE) `dirname .tmp/GraphEditor1.0.0`/GraphEditor1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/GraphEditor1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r GraphEditor.app
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_mainwindow.cpp moc_taskdialog.cpp moc_diagramscene.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_taskdialog.cpp moc_diagramscene.cpp
moc_mainwindow.cpp: diagramscene.h \
		node.h \
		task.h \
		mainwindow.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ mainwindow.h -o moc_mainwindow.cpp

moc_taskdialog.cpp: taskdialog.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ taskdialog.h -o moc_taskdialog.cpp

moc_diagramscene.cpp: node.h \
		task.h \
		diagramscene.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ diagramscene.h -o moc_diagramscene.cpp

compiler_rcc_make_all: qrc_resource.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resource.cpp
qrc_resource.cpp: resource.qrc \
		icon/open.ico \
		icon/new.ico \
		icon/pointer.ico \
		icon/save.ico \
		icon/fictivetask.ico \
		icon/cycle.ico \
		icon/creator.ico \
		icon/task.ico \
		icon/creator16.ico
	/Developer/Tools/Qt/rcc -name resource resource.qrc -o qrc_resource.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_taskdialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_taskdialog.h
ui_mainwindow.h: mainwindow.ui
	/Developer/Tools/Qt/uic mainwindow.ui -o ui_mainwindow.h

ui_taskdialog.h: taskdialog.ui
	/Developer/Tools/Qt/uic taskdialog.ui -o ui_taskdialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		diagramscene.h \
		node.h \
		task.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		diagramscene.h \
		node.h \
		task.h \
		ui_mainwindow.h \
		xmlprovider.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

taskdialog.o: taskdialog.cpp taskdialog.h \
		ui_taskdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o taskdialog.o taskdialog.cpp

diagramscene.o: diagramscene.cpp diagramscene.h \
		node.h \
		task.h \
		taskdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o diagramscene.o diagramscene.cpp

edgexml.o: edgexml.cpp edgexml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o edgexml.o edgexml.cpp

node.o: node.cpp diagramscene.h \
		node.h \
		task.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o node.o node.cpp

nodexml.o: nodexml.cpp nodexml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o nodexml.o nodexml.cpp

task.o: task.cpp task.h \
		node.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o task.o task.cpp

xmlprovider.o: xmlprovider.cpp xmlprovider.h \
		diagramscene.h \
		node.h \
		task.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o xmlprovider.o xmlprovider.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_taskdialog.o: moc_taskdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_taskdialog.o moc_taskdialog.cpp

moc_diagramscene.o: moc_diagramscene.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_diagramscene.o moc_diagramscene.cpp

qrc_resource.o: qrc_resource.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_resource.o qrc_resource.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

