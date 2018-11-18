cmake_minimum_required(VERSION 3.1.0)

project(null_gui_plugin)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(NULL_GUI_PLUGIN_COMPILER_FLAGS "")
set(NULL_GUI_PLUGIN_DEFINITIONS "")
if(MSVC)
  set(NULL_GUI_PLUGIN_COMPILER_FLAGS "/EHsc /MP")
  if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    set(NULL_GUI_PLUGIN_COMPILER_FLAGS "/EHsc /MP")
  endif()
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug OR CMAKE_BUILD_TYPE MATCHES RelWithDebInfo OR ICEENGINE_ENABLE_DEBUG_LOGGING)
  list(APPEND NULL_GUI_PLUGIN_DEFINITIONS -DICEENGINE_ENABLE_DEBUG_LOGGING)
endif()

if(ICEENGINE_ENABLE_TRACE_LOGGING)
  list(APPEND NULL_GUI_PLUGIN_DEFINITIONS -DICEENGINE_ENABLE_TRACE_LOGGING)
endif()

# Headers
include_directories(include)

# Source
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(null_gui_plugin SHARED ${SOURCES})

target_include_directories(null_gui_plugin PRIVATE ${ICEENGINE_INCLUDE_DIRS})
target_include_directories(null_gui_plugin PRIVATE ${BOOST_INCLUDE_DIRS})
target_include_directories(null_gui_plugin PRIVATE ${GLM_INCLUDE_DIRS})

target_compile_definitions(null_gui_plugin PRIVATE ${NULL_GUI_PLUGIN_DEFINITIONS})
target_compile_options(null_gui_plugin PRIVATE ${NULL_GUI_PLUGIN_COMPILER_FLAGS})