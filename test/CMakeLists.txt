project(naval-tests LANGUAGES CXX)

enable_testing()

find_package(GTest REQUIRED)

add_executable(
  test_naval
  detail/test_serialization.cpp
  detail/test_sink_impl.cpp
  primitives/test_draw_properties.cpp
  primitives/test_figure.cpp
  primitives/test_image.cpp
  primitives/test_message_metadata.cpp
  primitives/test_tag.cpp
  test_log_packet.cpp
  test_sink.cpp
  test_stream_logger.cpp
)
set_target_properties(test_naval PROPERTIES CXX_STANDARD 17)
target_link_libraries(test_naval PRIVATE naval GTest::gmock GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_naval)
