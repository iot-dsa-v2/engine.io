cmake_minimum_required(VERSION 3.7)
project(engine_io)

# set version number
set (MAJOR 1)
set (MINOR 0)

set(CMAKE_CXX_STANDARD 11)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

# if(NOT LINUX) should work, too, if you need that
if(LINUX) 
    message(STATUS ">>> Linux")
    # linux stuff here
	set(OS linux)
else()
    message(STATUS ">>> Not Linux")
    # stuff that should happen not on Linux 
if (WIN32)
	set(OS win)
endif (WIN32)
endif()

include_directories("${CMAKE_CURRENT_LIST_DIR}/core/inc")
include_directories("${CMAKE_CURRENT_LIST_DIR}/deps/libuv-1.x/include")


if(LINUX)
	set(LIBS_DIR "${CMAKE_CURRENT_LIST_DIR}/deps/libuv.1.10.0-preview1-22040/runtimes/linux-x64/native")
	link_directories("${LIBS_DIR}")
endif(LINUX)

if (WIN32)
	set(LIBS_DIR "${CMAKE_CURRENT_LIST_DIR}/deps/libuv.1.10.0-preview1-22040/runtimes/win-x64/native")
	link_directories("${LIBS_DIR}")
endif (WIN32)

set(ENGINE_IO_SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/core/src")
set(ENGINE_IO_BINARY_DIR "${CMAKE_CURRENT_LIST_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ENGINE_IO_BINARY_DIR})

set(SOURCE_FILES
        "${ENGINE_IO_SRC_DIR}/engine.io.cpp"
        "${ENGINE_IO_SRC_DIR}/platform.cpp"
        "${ENGINE_IO_SRC_DIR}/operating-context.cpp"
        "${ENGINE_IO_SRC_DIR}/platform-config.cpp"
		"${ENGINE_IO_SRC_DIR}/platform-${OS}.cpp"
        "${ENGINE_IO_SRC_DIR}/stream.io-uv.cpp"
        "${ENGINE_IO_SRC_DIR}/systembus.cpp"
        )

add_executable(engine_io ${SOURCE_FILES})

if(LINUX)
	target_link_libraries(engine_io libuv.so)
endif (LINUX)

if (WIN32)
	target_link_libraries(engine_io libuv.lib)
endif (WIN32)