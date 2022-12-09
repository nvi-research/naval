#include <naval/primitives/draw_properties.hpp>

#include <naval/colors.hpp>

namespace naval {

constexpr int32_t kDefaultImageQuality = 100;

DrawProperties::DrawProperties()
    : border_color{colors::kDefaultBorderColor},
      fill_color{colors::kDefaultFillColor},
      image_quality{kDefaultImageQuality} {
}

DrawProperties DrawProperties::WithBorderColor(Color border_color) const {
  DrawProperties copy = *this;
  copy.border_color = border_color;

  return copy;
}

DrawProperties DrawProperties::WithFillColor(Color fill_color) const {
  DrawProperties copy = *this;
  copy.fill_color = fill_color;

  return copy;
}

DrawProperties DrawProperties::WithImageQuality(int32_t image_quality) const {
  DrawProperties copy = *this;
  copy.image_quality = image_quality;

  return copy;
}

}  // namespace naval
