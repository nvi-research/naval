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
#include <string>
#include <string_view>

#include <naval/colors.hpp>
#include <naval/primitives/tag.hpp>

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

TEST(TestTagProperties, WithFontSize) {
  constexpr int32_t kNewFontSize = 4;
  EXPECT_EQ(TagProperties{}.WithFontSize(kNewFontSize).font_size, kNewFontSize);
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
