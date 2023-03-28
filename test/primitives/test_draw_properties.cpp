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

TEST(TestDrawProperties, WithLineThickness) {
  constexpr int32_t kLineThickness = 50;
  EXPECT_EQ(DrawProperties{}.WithLineThickness(kLineThickness).line_thickness, kLineThickness);
}

}  // namespace naval
