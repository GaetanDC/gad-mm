#-------------------------------------------------
#
# Project created by QtCreator 2012-08-11T09:36:21
#
#-------------------------------------------------

QT += network
# QT += statemachine

QT       += core gui widgets printsupport sql

TARGET = gad-mm
TEMPLATE = app
#VERS = $$system(perl version.pl)
VERS = 2.99G
DEFINES += VER=\"\\\"$${VERS}\\\"\"
CONFIG += c++11
CONFIG+=sdk_no_version_check
CONFIG+=qt console
CONFIG+=debug
CONFIG+=fontAwesomeFree


macx{
ICON = icon.icns
#QMAKE_MAC_SDK = macosx11.0
}
win32 {
    RC_FILE = myresource.rc
}

include(QtAwesome/QtAwesome/QtAwesome.pri)
#include(UGlobalHotkey/uglobalhotkey.pri)

INCLUDEPATH += ./

SOURCES += main.cpp\
    mainwindow.cpp \
    settingsdialog.cpp \
    version.cpp \
    asset_editor.cpp \
    task_adder.cpp \
    task_closer.cpp \
    myassetsmodel.cpp \
    mytodomodel.cpp \
    mylogmodel.cpp \
	 mytabledelegates.cpp

HEADERS  += mainwindow.h \
    settingsdialog.h \
    aboutbox.h \
    def.h \
    version.h \
    asset_editor.h \
    task_adder.h \
    task_closer.h \
    myassetsmodel.h \
    mytodomodel.h \
    mylogmodel.h \
    mytabledelegates.h
    
FORMS    += mainwindow.ui \
    settingsdialog.ui \
    aboutbox.ui \
    asset_editor.ui \
    task_adder.ui \
    task_closer.ui
    

OTHER_FILES += \
    version.pl \
    myresource.rc \
    icon.icsn \
    todour.ico \
    deploy.sh 
    
DISTFILES += \
    Feature-move-show-all \
    Feature-AlwaysOnTop \
    Todour.desktop \
    autobuild/gad-mm.desktop \
    LICENSE \
    README \
    PRIVACY-POLICY \
    CHANGELOG \
    Feature_Url_Support \
    Feature-Advanced_filters.txt \
    Feature-follow_select \
    Feature-Enter_To_Search \
    Feature-customized-font-colors \
    Feature-Setup-ini \
    Feature-tagstrip \
    PLAN.md \
    todour.png \
    autobuild/package-windows.sh \
    autobuild/Setup.iss \
    autobuild/README.md \
    autobuild/package-linux.sh \
    autobuild/DEBIAN_CONTROL_FILE.txt

RESOURCES += \
    resources.qrc

