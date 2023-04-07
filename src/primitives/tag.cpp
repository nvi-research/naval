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
