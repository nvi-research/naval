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
  include/naval/detail/macros.hpp
  include/naval/detail/serialization.hpp
  include/naval/detail/sinks_impl.hpp
  include/naval/log_level.hpp
  include/naval/log_packet.hpp
  include/naval/primitives/draw_properties.hpp
  include/naval/primitives/figure.hpp
  include/naval/primitives/image.hpp
  include/naval/primitives/message_metadata.hpp
  include/naval/primitives/popup.hpp
  include/naval/primitives/tag.hpp
  include/naval/sink.hpp
  include/naval/stream_logger.hpp
  src/detail/serialization.cpp
  src/log_packet.cpp
  src/primitives/draw_properties.cpp
  src/primitives/figure.cpp
  src/primitives/image.cpp
  src/primitives/popup.cpp
  src/primitives/tag.cpp
  src/sink.cpp
  src/stream_logger.cpp
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

option(NAVAL_BUILD_EXAMPLES "Build examples" OFF)
if(NAVAL_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()
