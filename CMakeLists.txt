# CMakeList.txt : CMake project for WakumiHMS, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("WakumiHMS")

#dependencies
include_directories(Ultralight/include)

find_library(
    ULTRA_LIB_CORE
    NAMES UltralightCore
    HINTS Ultralight/lib)

find_library(
    ULTRA_LIB_APP_CORE
    NAMES AppCore
    HINTS Ultralight/lib)

find_library(
    ULTRA_LIB
    NAMES Ultralight
    HINTS Ultralight/lib)

find_library(
    ULTRA_LIB_WEB_CORE
    NAMES WebCore
    HINTS Ultralight/lib)

# Add source to this project's executable.

#server app
add_executable (WakumiHMS-Server 
"src/server/WakumiHMSserver.cpp"
)

#client app
add_executable (WakumiHMS-Client 
"src/client/WakumiHMSclient.cpp"
"src/client/UIElements.h"
"src/client/GlobalInfo.cpp"
)

target_link_libraries(WakumiHMS-Client
    ${ULTRA_LIB_CORE} ${ULTRA_LIB_APP_CORE} ${ULTRA_LIB} ${ULTRA_LIB_WEB_CORE}
)

#platform specific configs for targets
if (MSVC)
  # Tell MSVC to use main instead of WinMain for Windows subsystem executables
  set_target_properties(WakumiHMS-Server PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
  set_target_properties(WakumiHMS-Client PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
  set(CMAKE_VS_INCLUDE_INSTALL_TO_DEFAULT_BUILD 1)
endif()

#ui assets/bins installing
install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/Ultralight/bin/ ${CMAKE_CURRENT_LIST_DIR}/assets DESTINATION ${INSTALL_PATH}/ )
