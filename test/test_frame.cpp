#include "gtest/gtest.h"

#include <cstddef>
#include <memory>
#include <vector>

#include <opencv2/core/mat.hpp>
#include <opencv2/core/mat.inl.hpp>

#include <naval/figure.hpp>
#include <naval/frame.hpp>
#include <naval/log_level.hpp>
#include <naval/message_metadata.hpp>
#include <naval/tag.hpp>

namespace naval {

TEST(TestFrame, EmptyFrameNoFigures) {
  Frame frame;
  EXPECT_EQ(frame.GetFigures().size(), 0);
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

TEST(TestFrame, ConvertToVerticesMyRect) {
  const std::vector<Vertex> expected{
      {0.0F, 0.0F}, {100.0F, 0.0F}, {100.0F, 200.0F}, {0.0F, 200.0F}};

  std::vector<Vertex> vertices = ConvertToVertices(kRect);
  ASSERT_EQ(vertices.size(), expected.size());
  for (size_t index = 0; index < vertices.size(); ++index) {
    EXPECT_EQ(vertices[index], expected[index])
        << "Vectors vertices and expected differ at index " << index;
  }
}

TEST(TestFrame, MyRectHasCorrectVertices) {
  Frame frame;
  frame.Debug(kRect, {}, {});

  const std::vector<Vertex> expected{
      {0.0F, 0.0F}, {100.0F, 0.0F}, {100.0F, 200.0F}, {0.0F, 200.0F}};
  std::vector<Figure> figures = frame.GetFigures();
  ASSERT_EQ(figures.size(), 1U);

  ASSERT_EQ(figures[0].vertices.size(), expected.size());
  for (size_t index = 0; index < expected.size(); ++index) {
    EXPECT_EQ(figures[0].vertices[index], expected[index])
        << "Vectors vertices and expected differ at index " << index;
  }
}

TEST(TestFrame, LogLevels) {
  Frame frame;
  frame.Debug(kRect, {}, {});
  frame.Info(kRect, {}, {});

  std::vector<Figure> figures = frame.GetFigures();
  ASSERT_EQ(figures.size(), 2U);
  EXPECT_EQ(figures[0].metadata.level, LogLevel::kDebug);
  EXPECT_EQ(figures[1].metadata.level, LogLevel::kInfo);
}

TEST(TestFigure, AddFigure) {
  Figure test_case{{LogLevel::kDebug, {}}, {}};

  Frame frame;
  frame.AddFigure(test_case);
  auto figures = frame.GetFigures();
  ASSERT_EQ(figures.size(), 1U);
  EXPECT_EQ(figures[0], test_case);
}

TEST(TestFrame, LogImage) {
  Frame frame;
  frame.Debug(cv::Mat(), {}, {});

  ASSERT_EQ(frame.GetImages().size(), 1U);
}

TEST(TestFigure, AddImage) {
  // TODO
}

TEST(TestFigure, EncodeAllImages) {
  // TODO
}

}  // namespace naval
