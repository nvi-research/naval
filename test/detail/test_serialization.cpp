#include "gtest/gtest.h"

#include <cstdint>
#include <cstdio>
#include <filesystem>
#include <istream>
#include <memory>
#include <string>
#include <vector>

#include <opencv2/core/mat.hpp>
#include <opencv2/core/mat.inl.hpp>
#include <opencv2/imgcodecs.hpp>

#include <naval/detail/serialization.hpp>
#include <naval/draw_properties.hpp>
#include <naval/figure.hpp>
#include <naval/frame.hpp>
#include <naval/image.hpp>
#include <naval/log_level.hpp>
#include <naval/message_metadata.hpp>
#include <naval/tag.hpp>

namespace naval::detail {

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

template <typename ItemType>
std::vector<ItemType> DeserializeVector(std::istream& stream) {
  auto length = DeserializeValue<size_t>(stream);

  std::vector<ItemType> vec;
  vec.reserve(length);
  for (size_t _ = 0; _ < length; ++_) {
    vec.push_back(DeserializeValue<ItemType>(stream));
  }

  return vec;
}

template <>
std::vector<uint32_t> DeserializeValue(std::istream& stream) {
  return DeserializeVector<uint32_t>(stream);
}

template <>
std::vector<uint8_t> DeserializeValue(std::istream& stream) {
  return DeserializeVector<uint8_t>(stream);
}

template <>
std::vector<std::string> DeserializeValue(std::istream& stream) {
  return DeserializeVector<std::string>(stream);
}

template <>
std::vector<Tag> DeserializeValue(std::istream& stream) {
  return DeserializeVector<Tag>(stream);
}

template <>
std::vector<Vertex> DeserializeValue(std::istream& stream) {
  return DeserializeVector<Vertex>(stream);
}

template <>
Tag DeserializeValue(std::istream& stream) {
  auto name = DeserializeValue<std::string>(stream);
  auto value = DeserializeValue<std::string>(stream);
  auto properties = DeserializeValue<TagProperties>(stream);

  return {name, value, properties};
}

template <>
MessageMetadata DeserializeValue(std::istream& stream) {
  auto log_level = DeserializeValue<LogLevel>(stream);
  auto tags = DeserializeValue<std::vector<Tag>>(stream);
  auto properties = DeserializeValue<DrawProperties>(stream);

  return {log_level, tags, properties};
}

template <>
Figure DeserializeValue(std::istream& stream) {
  auto metadata = DeserializeValue<MessageMetadata>(stream);
  auto vertices = DeserializeValue<std::vector<Vertex>>(stream);

  return {metadata, vertices};
}

template <>
Image DeserializeValue(std::istream& stream) {
  auto metadata = DeserializeValue<MessageMetadata>(stream);
  std::vector<uint8_t> mat_buffer;
  cv::Mat mat = cv::imdecode(mat_buffer, cv::IMREAD_COLOR);

  return {metadata, mat};
}

template <>
std::unique_ptr<Frame> DeserializeValue(std::istream& stream) {
  auto figures = DeserializeVector<Figure>(stream);
  auto images = DeserializeVector<Image>(stream);

  auto frame = std::make_unique<Frame>();
  for (const auto& figure : figures) {
    frame->AddFigure(figure);
  }
  for (const auto& image : images) {
    frame->AddImage(image);
  }
  return frame;
}

template <typename Value>
void DoTestSerialization(const Value& value) {
  std::stringstream stream;
  SerializeRaw(value, stream);

  EXPECT_EQ(DeserializeValue<Value>(stream), value);
  EXPECT_EQ(stream.peek(), EOF);
}

template <>
void DoTestSerialization(const Frame& value) {
  std::stringstream stream;
  SerializeRaw(value, stream);

  auto deserialized = DeserializeValue<std::unique_ptr<Frame>>(stream);
  EXPECT_EQ(deserialized->GetFigures(), value.GetFigures());
  EXPECT_EQ(deserialized->GetImages().size(),
            value.GetImages().size());  // TODO: compare images here
  EXPECT_EQ(stream.peek(), EOF);
}

TEST(TestSerialization, ArithmeticTypes) {
  {
    const uint32_t test_case = 0xDEADBEEF;
    DoTestSerialization(test_case);
  }
}

TEST(TestSerialization, Strings) {
  const std::vector<std::string> test_cases{"Hello, World!", ""};
  for (const auto& test_case : test_cases) {
    DoTestSerialization(test_case);
  }
}

TEST(TestSerialization, Vectors) {
  {
    const std::vector<uint32_t> test_case{0, 1};
    DoTestSerialization(test_case);
  }
  {
    const std::vector<uint32_t> test_case{};
    DoTestSerialization(test_case);
  }
  {
    const std::vector<std::string> test_case{"Hello, World!", "I hate C++"};
    DoTestSerialization(test_case);
  }
}

TEST(TestSerialization, TagProperties) {
  const TagProperties test_case =
      TagProperties().WithTextColor(0xDEADF00D).WithBackgroundColor(0xDEADBEEF);
  DoTestSerialization(test_case);
}

TEST(TestSerialization, Tag) {
  const Tag test_case{"object", "human",
                      TagProperties().WithTextColor(0xDEADF00D).WithBackgroundColor(0xDEADBEEF)};
  DoTestSerialization(test_case);
}

TEST(TestSerialization, DrawProperties) {
  const DrawProperties test_case =
      DrawProperties().WithFillColor(0xDEADF00D).WithBorderColor(0xDEADBEEF).WithImageQuality(50);
  DoTestSerialization(test_case);
}

TEST(TestSerialization, LogLevel) {
  const std::vector<LogLevel> test_cases{LogLevel::kDebug, LogLevel::kTrace, LogLevel::kInfo};

  for (const auto& test_case : test_cases) {
    DoTestSerialization(test_case);
  }
}

static const MessageMetadata kTestMessageMetadata{
    LogLevel::kDebug,
    {{"id", "0", TagProperties().WithTextColor(0xDEADF00D).WithBackgroundColor(0xDEADBEEF)}},
    DrawProperties().WithFillColor(0xDEADF00D).WithBorderColor(0xDEADBEEF)};

TEST(TestSerialization, MessageMetadata) {
  DoTestSerialization(kTestMessageMetadata);
}

TEST(TestSerialization, Vertex) {
  const Vertex test_case{1.0F, 2.0F};
  DoTestSerialization(test_case);
}

TEST(TestSerialization, Figure) {
  const Figure test_case{kTestMessageMetadata, {{1.0F, 2.0F}}};
  DoTestSerialization(test_case);
}

static const std::string kLennaPath =
    (std::filesystem::path{__FILE__}.remove_filename() / "../lenna.png").string();

TEST(TestSerialization, Image) {
  const MessageMetadata test_message_metadata{LogLevel::kDebug, {}};
  ASSERT_TRUE(std::filesystem::is_regular_file(kLennaPath));
  cv::Mat mat = cv::imread(kLennaPath);
  const Image image{test_message_metadata, mat};

  std::stringstream stream;
  SerializeRaw(image, stream);

  // TODO: actually test serialization of the image
  EXPECT_EQ(DeserializeValue<MessageMetadata>(stream), test_message_metadata);
}

TEST(TestSerialization, Frame) {
  const Figure test_figure{kTestMessageMetadata, {{1.0F, 2.0F}}};
  Frame test_case;
  test_case.AddFigure(test_figure);

  DoTestSerialization(test_case);
}

}  // namespace naval::detail
