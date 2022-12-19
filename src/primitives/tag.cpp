#include <naval/primitives/tag.hpp>

#include <utility>

#include <naval/colors.hpp>

namespace naval {

constexpr int32_t kDefaultTagFontSize = 8;

TagProperties::TagProperties()
    : text_color{colors::kDefaultTextColor},
      background_color{colors::kDefaultBackgroundColor},
      font_size{kDefaultTagFontSize} {
}

TagProperties TagProperties::WithTextColor(Color text_color) const {
  TagProperties copy = *this;
  copy.text_color = text_color;

  return copy;
}

TagProperties TagProperties::WithBackgroundColor(Color background_color) const {
  TagProperties copy = *this;
  copy.background_color = background_color;

  return copy;
}

TagProperties TagProperties::WithFontSize(int32_t font_size) const {
  TagProperties copy = *this;
  copy.font_size = font_size;

  return copy;
}

Tag::Tag(std::string name, std::string value) : name{std::move(name)}, value{std::move(value)} {
}

Tag::Tag(std::string name, std::string_view value) : name{std::move(name)}, value{value} {
}

Tag::Tag(std::string name, const char* value) : name{std::move(name)}, value{value} {
}

Tag::Tag(std::string name, int value) : name{std::move(name)}, value{std::to_string(value)} {
}

Tag::Tag(std::string name, float value) : name{std::move(name)}, value{std::to_string(value)} {
}

Tag::Tag(std::string name, double value) : name{std::move(name)}, value{std::to_string(value)} {
}

}  // namespace naval
