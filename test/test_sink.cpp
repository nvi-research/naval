#include "gtest/gtest.h"

#include <filesystem>
#include <memory>

#include <naval/detail/sinks_impl.hpp>  // IWYU pragma: keep
#include <naval/sink.hpp>

namespace naval {

TEST(TestSink, CreateNullLikeSink) {
  auto sink = CreateNullLikeSink();
  ASSERT_NE(std::dynamic_pointer_cast<detail::NullLikeSink>(sink), nullptr);
}

TEST(TestSink, CreateFileSink) {
  auto temp_file = std::filesystem::path{::testing::TempDir()} / "file_sink_test";
  auto sink = CreateFileSink(temp_file.string());
  ASSERT_NE(std::dynamic_pointer_cast<detail::FileSink>(sink), nullptr);
}

// TEST(TestSink, FileStreamSinkFails) {
//   const std::string test_file_path = "//////";
//   EXPECT_THROW({ FileStreamSink sink{test_file_path}; }, std::runtime_error);
// }

}  // namespace naval
