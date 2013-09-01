cmake_minimum_required(VERSION 2.8.8)

project(TSF-chewing)
add_subdirectory(libchewing)
include_directories(
	libchewing/include
	tsfhelper
)

# http://www.utf8everywhere.org/
add_definitions(/D_UNICODE=1 /DUNICODE=1)

set(SRC ${PROJECT_SOURCE_DIR}/src)

set(TSF_SRC ${PROJECT_SOURCE_DIR}/tsf)

add_library(ChewingService SHARED
        ${SRC}/DllMain.cpp
        ${SRC}/ChewingEngine.cpp

        ${TSF_SRC}/ImeEngine.cpp
        ${TSF_SRC}/CandidateList.h
        ${TSF_SRC}/CandidateWindow.h
        ${TSF_SRC}/DisplayAttributeInfo.h
        ${TSF_SRC}/EditSession.h
        ${TSF_SRC}/EnumDisplayAttributeInfo.h
        ${TSF_SRC}/Globals.h
        ${TSF_SRC}/Resource.h
        ${TSF_SRC}/TextService.h
        ${TSF_SRC}/Util.h
        ${TSF_SRC}/CandidateList.cpp
        ${TSF_SRC}/CandidateWindow.cpp
        ${TSF_SRC}/Compartment.cpp
        ${TSF_SRC}/Composition.cpp
        ${TSF_SRC}/DisplayAttribute.cpp
        ${TSF_SRC}/DisplayAttributeInfo.cpp
        ${TSF_SRC}/DisplayAttributeProvider.cpp
        ${TSF_SRC}/EndComposition.cpp
        ${TSF_SRC}/EnumDisplayAttributeInfo.cpp
        ${TSF_SRC}/Globals.cpp
        ${TSF_SRC}/KeyEventSink.cpp
        ${TSF_SRC}/KeyHandler.cpp
        ${TSF_SRC}/LanguageBar.cpp
        ${TSF_SRC}/PreComp.cpp
        ${TSF_SRC}/Register.cpp
        ${TSF_SRC}/Server.cpp
        ${TSF_SRC}/StartComposition.cpp
        ${TSF_SRC}/TextEditSink.cpp
        ${TSF_SRC}/TextService.cpp
        ${TSF_SRC}/ThreadMgrEventSink.cpp
        ${TSF_SRC}/TextService.def
        ${TSF_SRC}/TextService.ico
        ${TSF_SRC}/TextService.rc
        ${TSF_SRC}/Util.cpp
)
# How to link to target in subproject?
target_link_libraries(ChewingService chewing_static)
