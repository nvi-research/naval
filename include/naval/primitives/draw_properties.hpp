#pragma once

#include <cstdint>

#include <naval/colors.hpp>

namespace naval {

struct DrawProperties {
  DrawProperties();

  DrawProperties WithBorderColor(Color text_color) const;
  DrawProperties WithFillColor(Color fill_color) const;
  DrawProperties WithImageQuality(int32_t image_quality) const;

  Color border_color;
  Color fill_color;
  int32_t image_quality;
};

inline bool operator==(const DrawProperties& lhs, const DrawProperties& rhs) {
  return lhs.border_color == rhs.border_color && lhs.fill_color == rhs.fill_color &&
         lhs.image_quality == rhs.image_quality;
}

}  // namespace naval
