cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(naval LANGUAGES CXX)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

include(cmake/cmake-scripts.cmake)

find_package(OpenCV REQUIRED)

add_library(
  naval STATIC
  include/naval/colors.hpp
  include/naval/debug_visualizer.hpp
  include/naval/detail/serialization.hpp
  include/naval/draw_properties.hpp
  include/naval/figure.hpp
  include/naval/frame.hpp
  include/naval/image.hpp
  include/naval/log_level.hpp
  include/naval/message_metadata.hpp
  include/naval/noop_stream.hpp
  include/naval/sink_stream.hpp
  include/naval/sink.hpp
  include/naval/stream.hpp
  include/naval/tag.hpp
  src/detail/serialization.cpp
  src/draw_properties.cpp
  src/figure.cpp
  src/frame.cpp
  src/image.cpp
  src/sink_stream.cpp
  src/tag.cpp
)
set_target_properties(naval PROPERTIES CXX_STANDARD 17)
target_include_directories(naval PUBLIC include)
target_link_libraries(
  naval
  PUBLIC opencv_core
  PRIVATE opencv_imgproc opencv_imgcodecs
)

option(NAVAL_BUILD_TESTS "Build test programs" OFF)
if(NAVAL_BUILD_TESTS)
  add_subdirectory(test)
endif()
