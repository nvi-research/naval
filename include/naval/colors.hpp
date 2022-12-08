#pragma once

#include <cstdint>

namespace naval {

using Color = uint32_t;

namespace colors {

constexpr Color kDefaultTextColor = 0x000000FF;
constexpr Color kDefaultBackgroundColor = 0xFF796CB0;
constexpr Color kDefaultBorderColor = 0xFF796CB0;
constexpr Color kDefaultFillColor = 0xFFFFFF00;

}  // namespace colors

}  // namespace naval
