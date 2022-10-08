CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT("hack")

SET(CMAKE_CXX_FLAGS "-std=c++2a -lpthread -Wall -fpic -O2 -ggdb --no-gnu-unique")
SET(CMAKE_C_FLAGS "-m32 -lpthread -Wall -fpic -O2 --no-gnu-unique")
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

FILE(GLOB SOURCES "src/*.cpp")

ADD_SUBDIRECTORY(libraries/fmt) # fmt::format(format string, args...) -> std::format(format string, args...)
ADD_LIBRARY(${CMAKE_PROJECT_NAME} SHARED ${SOURCES} src/utils.h src/utils.cpp src/game.cpp src/game.h)
TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} fmt)
