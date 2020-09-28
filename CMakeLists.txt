# CMakeList.txt : CMake project for WakumiHMS, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("WakumiHMS")

# Add source to this project's executable.

#server app
add_executable (WakumiHMS-Server "src/server/WakumiHMSserver.cpp")

#client app
add_executable (WakumiHMS-Client "src/client/WakumiHMSclient.cpp")

#dependencies
include_directories(Ultralight/include)
