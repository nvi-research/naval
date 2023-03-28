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

/**
 * @file tag.hpp
 * @author Vyacheslav Zhdanovskiy (vyacheslav.zhdanovskiy@nvi-research.com)
 *
 * @copyright Copyright (c) 2023 NVI Research
 */

#pragma once

#include <cstdint>
#include <string>
#include <string_view>

#include <naval/colors.hpp>
#include <naval/log_level.hpp>

namespace naval {

/**
 * @struct TagProperties
 * 
 * @brief Single tag properties.
 * 
 */
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

/**
 * @struct Tag.
 * 
 * @brief A tag that will be drawn like [name: value] near the associated primitive.
 * 
 */
struct Tag {
  Tag(std::string name, std::string value);
  Tag(std::string name, std::string_view value);
  Tag(std::string name, const char* value);

  // TODO: use template constructor for numeric values
  Tag(std::string name, int value);
  Tag(std::string name, float value);
  Tag(std::string name, double value);

  template <typename ValueType>
  Tag(std::string name, ValueType value, const TagProperties& properties,
      LogLevel level = LogLevel::kInfo)
      : Tag{name, std::move(value)} {
    this->properties = properties;
    this->log_level = level;
  }

  bool operator==(const Tag& other) const {
    return name == other.name && value == other.value && properties == other.properties &&
           log_level == other.log_level;
  }

  std::string name;
  std::string value;
  TagProperties properties;
  LogLevel log_level = LogLevel::kInfo;
};

}  // namespace naval
