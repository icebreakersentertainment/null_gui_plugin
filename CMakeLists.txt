cmake_minimum_required(VERSION 3.1.0)

project(null_gui_plugin)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(IMGUI_PLUGIN_COMPILER_FLAGS "")
if(MSVC)
  set(IMGUI_PLUGIN_COMPILER_FLAGS "/EHsc /MP")
  if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    set(IMGUI_PLUGIN_COMPILER_FLAGS "/EHsc /MP")
  endif()
endif()

# Headers
include_directories(include)

# Source
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(null_gui_plugin SHARED ${SOURCES})

target_include_directories(null_gui_plugin PRIVATE ${ICEENGINE_INCLUDE_DIRS})
target_include_directories(null_gui_plugin PRIVATE ${BOOST_INCLUDE_DIRS})
target_include_directories(null_gui_plugin PRIVATE ${GLM_INCLUDE_DIRS})

target_compile_options(null_gui_plugin PRIVATE ${IMGUI_PLUGIN_COMPILER_FLAGS})