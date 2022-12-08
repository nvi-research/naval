#include "gtest/gtest.h"

#include <string>
#include <string_view>

#include <naval/colors.hpp>
#include <naval/tag.hpp>

namespace naval {

TEST(TestTagProperties, DefaultConstructor) {
  TagProperties properties{};
  EXPECT_EQ(properties.text_color, colors::kDefaultTextColor);
  EXPECT_EQ(properties.background_color, colors::kDefaultBackgroundColor);
}

TEST(TestTagProperties, WithTextColor) {
  constexpr Color kTextColor = 0xAABBCCFF;
  EXPECT_EQ(TagProperties{}.WithTextColor(kTextColor).text_color, kTextColor);
}

TEST(TestTagProperties, WithBackgroundColor) {
  constexpr Color kBgColor = 0xAABBCCFF;
  EXPECT_EQ(TagProperties{}.WithBackgroundColor(kBgColor).background_color, kBgColor);
}

TEST(TestTag, Constructor) {
  {
    const std::string tag_name = "Hello";
    const std::string tag_value = "World";

    Tag tag{tag_name, tag_value};
    EXPECT_EQ(tag.name, tag_name);
    EXPECT_EQ(tag.value, tag_value);
  }
  {
    const std::string tag_name = "Hello";
    const std::string_view tag_value = "World";

    Tag tag{tag_name, tag_value};
    EXPECT_EQ(tag.name, tag_name);
    EXPECT_EQ(tag.value, tag_value);
  }
  {
    const std::string tag_name = "Hello";
    const char* tag_value = "World";

    Tag tag{tag_name, tag_value};
    EXPECT_EQ(tag.name, tag_name);
    EXPECT_EQ(tag.value, std::string{tag_value});
  }
  {
    const std::string tag_name = "Hello";
    const int tag_value = 666;

    Tag tag{tag_name, tag_value};
    EXPECT_EQ(tag.name, tag_name);
    EXPECT_EQ(tag.value, std::to_string(tag_value));
  }
  {
    const std::string tag_name = "Hello";
    const float tag_value = 1.0F;

    Tag tag{tag_name, tag_value};
    EXPECT_EQ(tag.name, tag_name);
    EXPECT_EQ(tag.value, std::to_string(tag_value));
  }
  {
    const std::string tag_name = "Hello";
    const float tag_value = 1.0;

    Tag tag{tag_name, tag_value};
    EXPECT_EQ(tag.name, tag_name);
    EXPECT_EQ(tag.value, std::to_string(tag_value));
  }
  {
    const std::string tag_name = "Hello";
    const std::string tag_value = "World";
    const Color text_color = 0xAABBCCDD;

    Tag tag{tag_name, tag_value, TagProperties().WithTextColor(text_color)};
    EXPECT_EQ(tag.name, tag_name);
    EXPECT_EQ(tag.value, tag_value);
    EXPECT_EQ(tag.properties.text_color, text_color);
  }
}

}  // namespace naval
