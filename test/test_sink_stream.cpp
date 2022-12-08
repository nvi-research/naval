#include "gtest/gtest.h"

#include <cstddef>
#include <istream>
#include <memory>
#include <string>
#include <utility>

#include <naval/frame.hpp>
#include <naval/sink.hpp>
#include <naval/sink_stream.hpp>

namespace naval {

// TODO: fix copypaste
template <typename Value>
Value DeserializeValue(std::istream& stream) {
  Value value;
  stream.read(reinterpret_cast<std::istream::char_type*>(&value), sizeof(value));

  return value;
}

template <>
std::string DeserializeValue(std::istream& stream) {
  auto length = DeserializeValue<size_t>(stream);

  std::string value(length, '\0');
  stream.read(value.data(), static_cast<std::streamsize>(length));

  return value;
}

TEST(TestSinkStream, WriteFrame) {
  std::stringstream output_stream;
  auto sink = std::make_shared<OutputStreamSink>(output_stream);

  Frame frame;
  const std::string test_stream_url = "test_stream_url";
  SinkStream stream{std::move(sink), test_stream_url};
  stream.WriteFrame(frame);
  // TODO: actually test flush properly
  stream.Flush();

  EXPECT_EQ(DeserializeValue<std::string>(output_stream), test_stream_url);
  EXPECT_EQ(DeserializeValue<size_t>(output_stream), 0);  // 0 figures
  EXPECT_EQ(DeserializeValue<size_t>(output_stream), 0);  // 0 images
}

}  // namespace naval
