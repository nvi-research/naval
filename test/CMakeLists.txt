# project(naval-tests LANGUAGES CXX)

enable_testing()

find_package(GTest REQUIRED)

add_executable(
  test_naval
  detail/test_serialization.cpp
  test_draw_properties.cpp
  test_figure.cpp
  test_frame.cpp
  test_image.cpp
  test_message_metadata.cpp
  test_noopstream.cpp
  test_sink.cpp
  test_sink_stream.cpp
  test_tag.cpp
)
set_target_properties(test_naval PROPERTIES CXX_STANDARD 17)
target_link_libraries(test_naval PRIVATE naval GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_naval)
