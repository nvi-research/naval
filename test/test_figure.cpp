#include "gtest/gtest.h"

#include <memory>

#include <naval/figure.hpp>

namespace naval {

TEST(TestVertex, Constructor) {
  {
    Vertex vertex;
    EXPECT_FLOAT_EQ(vertex.x, 0.0F);
    EXPECT_FLOAT_EQ(vertex.y, 0.0F);
  }
  {
    const float x = 1.0;
    const float y = 2.0;
    Vertex vertex{x, y};

    EXPECT_FLOAT_EQ(vertex.x, x);
    EXPECT_FLOAT_EQ(vertex.y, y);
  }
}

TEST(TestFigure, Constructor) {
  // TODO: do test
}

}  // namespace naval
