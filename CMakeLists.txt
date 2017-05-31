cmake_minimum_required(VERSION 3.6)
project(rollo_control)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_library(FONTCONFIG_LIB fontconfig)
find_library(MOSQUITTO_LIBRARY NAMES libmosquitto mosquitto)
find_library(MOSQUITTOPP_LIBRARY NAMES libmosquittopp mosquittopp)


message ( "FONTCONFIG_LIB      = "  ${FONTCONFIG_LIB})
message ( "MOSQUITTO_LIBRARY   = "  ${MOSQUITTO_LIBRARY})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/nana/include)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/nana)

set(SOURCE_FILES src/main.cpp src/ControlMessage.cpp src/MosquittoClient.cpp src/RolloController.cpp)
add_executable(rollo_switch ${SOURCE_FILES})

set_property(TARGET rollo_switch PROPERTY CXX_STANDARD 14)



target_link_libraries(rollo_switch Threads::Threads  ${FONTCONFIG_LIB} ${MOSQUITTOPP_LIBRARY} ${MOSQUITTO_LIBRARY} nana)
