/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2023, NVI Research
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "gtest/gtest.h"

#include <cstdint>
#include <cstdio>
#include <filesystem>
#include <istream>
#include <string>
#include <utility>
#include <vector>

#include <opencv2/core/mat.hpp>
#include <opencv2/core/mat.inl.hpp>
#include <opencv2/imgcodecs.hpp>

#include <naval/colors.hpp>
#include <naval/detail/serialization.hpp>
#include <naval/detail/sinks_impl.hpp>
#include <naval/log_level.hpp>
#include <naval/log_packet.hpp>
#include <naval/primitives/draw_properties.hpp>
#include <naval/primitives/figure.hpp>
#include <naval/primitives/image.hpp>
#include <naval/primitives/message_metadata.hpp>
#include <naval/primitives/tag.hpp>

namespace naval::detail {

template <typename... Args>
std::vector<uint8_t> JoinByteVectors(Args... args) {
  std::vector<uint8_t> result;

  (result.insert(result.end(), args.begin(), args.end()), ...);

  return result;
}

template <typename Value>
std::vector<uint8_t> SerializeToBytes(const Value& value) {
  std::stringstream stream;
  StdOStreamSink sink{stream};
  Serialize(sink, value);
  auto size = static_cast<size_t>(stream.tellp());
  stream.seekg(std::ios::beg);

  std::vector<uint8_t> buffer(size);
  stream.read(reinterpret_cast<char*>(buffer.data()), size);

  return buffer;
}

template <typename Value>
void DoSerializationTest(const Value& value, const std::vector<uint8_t> expected) {
  std::vector<uint8_t> data = SerializeToBytes(value);

  ASSERT_EQ(data.size(), expected.size());
  for (size_t index = 0; index < data.size(); ++index) {
    EXPECT_EQ(data[index], expected[index])
        << "Vectors data and expected differ at index " << index;
  }
}

TEST(TestSerialization, ArithmeticTypes) {
  {
    const uint8_t test_case = 0xEF;
    DoSerializationTest(test_case, {0xEF});
  }
  {
    const uint32_t test_case = 0xDEADBEEF;
    DoSerializationTest(test_case, {0xEF, 0xBE, 0xAD, 0xDE, 0x00, 0x00, 0x00, 0x00});
  }
  {
    const uint64_t test_case = 0xDEADBEEFDEADBEEF;
    DoSerializationTest(test_case, {0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE});
  }
  {
    const int32_t test_case = 0x0EADBEEF;
    DoSerializationTest(test_case, {0xEF, 0xBE, 0xAD, 0x0E, 0x00, 0x00, 0x00, 0x00});
  }
  {
    const int64_t test_case = 0x0EADBEEFDEADBEEF;
    DoSerializationTest(test_case, {0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0x0E});
  }
  {
    const float test_case = 1e-23F;
    DoSerializationTest(test_case, {0x9A, 0x6D, 0x41, 0x19});
  }
  {
    const double test_case = 1e-23;
    DoSerializationTest(test_case, {0x51, 0xB2, 0x12, 0x40, 0xB3, 0x2D, 0x28, 0x3B});
  }
}

TEST(TestSerialization, LogLevel) {
  const LogLevel test_case = LogLevel::kWarning;
  DoSerializationTest(test_case, {0x04, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0});
}

TEST(TestSerialization, Strings) {
  const std::vector<std::pair<std::string, std::vector<uint8_t>>> test_cases{
      {"Hello, World!", {13,  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  //
                         'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'}},
      {"", {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}}};
  for (const auto& [value, expected] : test_cases) {
    DoSerializationTest(value, expected);
  }
}

TEST(TestSerialization, Vectors) {
  {
    const std::vector<uint8_t> test_case{0x0E, 0xDA};
    const std::vector<uint8_t> expected{2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0E, 0xDA};
    DoSerializationTest(test_case, expected);
  }
  {
    const std::vector<uint8_t> test_case{};
    const std::vector<uint8_t> expected{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x00};
    DoSerializationTest(test_case, expected);
  }
}

TEST(TestSerialization, TagProperties) {
  const TagProperties test_case =
      TagProperties().WithTextColor(0xDEADF00D).WithBackgroundColor(0xDEADBEEF).WithFontSize(4);
  const std::vector<uint8_t> expected =
      JoinByteVectors(SerializeToBytes<Color>(0xDEADF00D), SerializeToBytes<Color>(0xDEADBEEF),
                      SerializeToBytes<int>(4));
  DoSerializationTest(test_case, expected);
}

TEST(TestSerialization, Tag) {
  const Tag test_case{"object", "human",
                      TagProperties().WithTextColor(0xDEADF00D).WithBackgroundColor(0xDEADBEEF),
                      LogLevel::kInfo};
  const std::vector<uint8_t> expected = JoinByteVectors(
      SerializeToBytes(test_case.name), SerializeToBytes(test_case.value),
      SerializeToBytes(test_case.properties), SerializeToBytes(test_case.log_level));
  DoSerializationTest(test_case, expected);
}

TEST(TestSerialization, DrawProperties) {
  const DrawProperties test_case = DrawProperties()
                                       .WithFillColor(0xDEADF00D)
                                       .WithBorderColor(0xDEADBEEF)
                                       .WithImageQuality(50)
                                       .WithLineThickness(1);
  const std::vector<uint8_t> expected = JoinByteVectors(
      SerializeToBytes(test_case.border_color), SerializeToBytes(test_case.fill_color),
      SerializeToBytes(test_case.image_quality), SerializeToBytes(test_case.line_thickness));

  DoSerializationTest(test_case, expected);
}

static const MessageMetadata kTestMessageMetadata{
    LogLevel::kDebug,
    {{"id", "0", TagProperties().WithTextColor(0xDEADF00D).WithBackgroundColor(0xDEADBEEF)}},
    DrawProperties().WithFillColor(0xDEADF00D).WithBorderColor(0xDEADBEEF)};

TEST(TestSerialization, MessageMetadata) {
  const MessageMetadata test_case = kTestMessageMetadata;
  const std::vector<uint8_t> expected =
      JoinByteVectors(SerializeToBytes(test_case.level), SerializeToBytes(test_case.tags),
                      SerializeToBytes(test_case.draw_properties));

  DoSerializationTest(kTestMessageMetadata, expected);
}

TEST(TestSerialization, Vertex) {
  const Vertex test_case{1.0F, 2.0F};
  const std::vector<uint8_t> expected =
      JoinByteVectors(SerializeToBytes(test_case.x), SerializeToBytes(test_case.y));
  DoSerializationTest(test_case, expected);
}

TEST(TestSerialization, Figure) {
  const Figure test_case{kTestMessageMetadata, {{1.0F, 2.0F}}};
  const std::vector<uint8_t> expected =
      JoinByteVectors(SerializeToBytes(test_case.metadata), SerializeToBytes(test_case.vertices));
  DoSerializationTest(test_case, expected);
}

static const std::string kLennaPath =
    (std::filesystem::path{__FILE__}.remove_filename() / "../lenna.png").string();

TEST(TestSerialization, Image) {
  ASSERT_TRUE(std::filesystem::is_regular_file(kLennaPath));

  cv::Mat mat = cv::imread(kLennaPath);
  const Image test_case{kTestMessageMetadata, mat};

  std::vector<uint8_t> image_bytes;
  cv::imencode(".jpg", mat, image_bytes,
               {cv::IMWRITE_JPEG_QUALITY, test_case.metadata.draw_properties.image_quality});

  const std::vector<uint8_t> expected = JoinByteVectors(
      SerializeToBytes(test_case.metadata), SerializeToBytes(image_bytes.size()), image_bytes);

  DoSerializationTest(test_case, expected);
}

TEST(TestSerialization, LogPacket) {
  const Figure test_figure{kTestMessageMetadata, {{1.0F, 2.0F}}};
  LogPacket test_case{1.0};
  test_case.AddFigure(test_figure);

  const std::vector<uint8_t> expected = JoinByteVectors(
      SerializeToBytes(test_case.GetTimestamp()), SerializeToBytes(test_case.GetFigures()),
      SerializeToBytes(test_case.GetImages()), SerializeToBytes(test_case.GetPopups()));

  DoSerializationTest(test_case, expected);
}

}  // namespace naval::detail
