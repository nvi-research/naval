#include "gtest/gtest.h"

#include <sstream>
#include <stdexcept>
#include <string>

#include <naval/sink.hpp>

namespace naval {

TEST(TestSink, OutputStreamSink) {
  std::stringstream stream;

  OutputStreamSink sink{stream};

  EXPECT_EQ(&stream, &sink.GetStream())
      << "OutputStreamSink::GetStream() does not return the same stream";
}

TEST(TestSink, FileStreamSink) {
  const std::string test_file_path = ::testing::TempDir() + "/file_stream_sink_test";
  FileStreamSink sink{test_file_path};

  const std::string test_message = "Hello, world!";
  sink.GetStream() << test_message;
  sink.GetStream().flush();

  std::ifstream input{test_file_path, std::ios::binary};
  std::string line;
  std::getline(input, line);
  EXPECT_EQ(line, test_message);
}

TEST(TestSink, FileStreamSinkFails) {
  const std::string test_file_path = "//////";
  EXPECT_THROW({ FileStreamSink sink{test_file_path}; }, std::runtime_error);
}

}  // namespace naval
