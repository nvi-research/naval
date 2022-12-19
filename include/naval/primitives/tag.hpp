#pragma once

#include <cstdint>
#include <string>
#include <string_view>

#include <naval/colors.hpp>

namespace naval {

struct TagProperties {
  TagProperties();

  bool operator==(const TagProperties& other) const {
    return text_color == other.text_color && background_color == other.background_color &&
           font_size == other.font_size;
  }

  TagProperties WithTextColor(Color text_color) const;
  TagProperties WithBackgroundColor(Color background_color) const;
  TagProperties WithFontSize(int32_t font_size) const;

  uint32_t text_color;
  uint32_t background_color;
  int32_t font_size;
};

struct Tag {
  Tag(std::string name, std::string value);
  Tag(std::string name, std::string_view value);
  Tag(std::string name, const char* value);

  // TODO: use template constructor for numeric values
  Tag(std::string name, int value);
  Tag(std::string name, float value);
  Tag(std::string name, double value);

  template <typename ValueType>
  Tag(std::string name, ValueType value, const TagProperties& properties)
      : Tag{name, std::move(value)} {
    this->properties = properties;
  }

  bool operator==(const Tag& other) const {
    return name == other.name && value == other.value && properties == other.properties;
  }

  std::string name;
  std::string value;
  TagProperties properties;
};

}  // namespace naval
