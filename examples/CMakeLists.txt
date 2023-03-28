project(naval-examples LANGUAGES CXX)

add_executable(
  naval_example
  example.cpp
)
set_target_properties(naval_example PROPERTIES CXX_STANDARD 17)
target_link_libraries(naval_example PRIVATE naval opencv_core opencv_imgproc opencv_videoio)
