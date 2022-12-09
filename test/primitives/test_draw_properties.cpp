#include "gtest/gtest.h"

#include <cstdint>
#include <memory>

#include <naval/colors.hpp>
#include <naval/primitives/draw_properties.hpp>

namespace naval {

TEST(TestDrawProperties, DefaultConstructor) {
  DrawProperties properties{};
  EXPECT_EQ(properties.border_color, colors::kDefaultBorderColor);
  EXPECT_EQ(properties.fill_color, colors::kDefaultFillColor);
}

TEST(TestDrawProperties, WithBorderColor) {
  constexpr Color kBorderColor = 0xAABBCCFF;
  EXPECT_EQ(DrawProperties{}.WithBorderColor(kBorderColor).border_color, kBorderColor);
}

TEST(TestDrawProperties, WithFillColor) {
  constexpr Color kFillColor = 0xAABBCCFF;
  EXPECT_EQ(DrawProperties{}.WithFillColor(kFillColor).fill_color, kFillColor);
}

TEST(TestDrawProperties, WithImageQuality) {
  constexpr int32_t kImageQuality = 50;
  EXPECT_EQ(DrawProperties{}.WithImageQuality(kImageQuality).image_quality, kImageQuality);
}

}  // namespace naval
