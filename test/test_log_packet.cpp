#include "gtest/gtest.h"

#include <cstddef>
#include <memory>
#include <vector>

#include <opencv2/core/mat.hpp>
#include <opencv2/core/mat.inl.hpp>

#include <naval/log_level.hpp>
#include <naval/log_packet.hpp>
#include <naval/primitives/figure.hpp>
#include <naval/primitives/message_metadata.hpp>
#include <naval/primitives/tag.hpp>

namespace naval {

TEST(TestLogPacket, EmptypacketNoFigures) {
  LogPacket packet;
  EXPECT_EQ(packet.GetFigures().size(), 0);
}

struct MyRect {
  MyRect() = default;
  MyRect(float x, float y, float width, float height) : x{x}, y{y}, width{width}, height{height} {
  }

  float x;
  float y;
  float width;
  float height;
};

std::vector<Vertex> ConvertToVertices(const MyRect& rect) {
  return {{rect.x, rect.y},
          {rect.x + rect.width, rect.y},
          {rect.x + rect.width, rect.y + rect.height},
          {rect.x, rect.y + rect.height}};
}

static const MyRect kRect{0.0F, 0.0F, 100.0F, 200.0F};

TEST(TestPacket, ConvertToVerticesMyRect) {
  const std::vector<Vertex> expected{
      {0.0F, 0.0F}, {100.0F, 0.0F}, {100.0F, 200.0F}, {0.0F, 200.0F}};

  std::vector<Vertex> vertices = ConvertToVertices(kRect);
  ASSERT_EQ(vertices.size(), expected.size());
  for (size_t index = 0; index < vertices.size(); ++index) {
    EXPECT_EQ(vertices[index], expected[index])
        << "Vectors vertices and expected differ at index " << index;
  }
}

TEST(TestPacket, MyRectHasCorrectVertices) {
  LogPacket packet;
  packet.Debug(kRect, {}, {});

  const std::vector<Vertex> expected{
      {0.0F, 0.0F}, {100.0F, 0.0F}, {100.0F, 200.0F}, {0.0F, 200.0F}};
  std::vector<Figure> figures = packet.GetFigures();
  ASSERT_EQ(figures.size(), 1U);

  ASSERT_EQ(figures[0].vertices.size(), expected.size());
  for (size_t index = 0; index < expected.size(); ++index) {
    EXPECT_EQ(figures[0].vertices[index], expected[index])
        << "Vectors vertices and expected differ at index " << index;
  }
}

TEST(TestPacket, LogLevels) {
  LogPacket packet;
  packet.Debug(kRect, {}, {});
  packet.Info(kRect, {}, {});

  std::vector<Figure> figures = packet.GetFigures();
  ASSERT_EQ(figures.size(), 2U);
  EXPECT_EQ(figures[0].metadata.level, LogLevel::kDebug);
  EXPECT_EQ(figures[1].metadata.level, LogLevel::kInfo);
}

TEST(TestPacket, AddFigure) {
  Figure test_case{{LogLevel::kDebug, {}}, {}};

  LogPacket packet;
  packet.AddFigure(test_case);
  auto figures = packet.GetFigures();
  ASSERT_EQ(figures.size(), 1U);
  EXPECT_EQ(figures[0], test_case);
}

TEST(TestPacket, LogImage) {
  LogPacket packet;
  packet.Debug(cv::Mat(), {}, {});

  ASSERT_EQ(packet.GetImages().size(), 1U);
}

TEST(TestPacket, AddImage) {
  // TODO
}

TEST(TestPacket, EncodeAllImages) {
  // TODO
}

}  // namespace naval
