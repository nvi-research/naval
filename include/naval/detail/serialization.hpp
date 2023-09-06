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
 * @file serialization.hpp
 * @author Vyacheslav Zhdanovskiy (vyacheslav.zhdanovskiy@nvi-research.com)
 *
 * This file contains detail serialization code that should not be used directly by the user.
 *
 * @copyright Copyright (c) 2023 NVI Research
 */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <naval/detail/macros.hpp>
#include <naval/log_level.hpp>
#include <naval/primitives/draw_properties.hpp>
#include <naval/primitives/figure.hpp>
#include <naval/primitives/message_metadata.hpp>
#include <naval/primitives/popup.hpp>
#include <naval/primitives/tag.hpp>
#include <naval/sink.hpp>

namespace naval {

class Image;
class LogPacket;

};  // namespace naval

namespace naval::detail {

template <typename Value>
inline void SerializeRaw(ISink& sink, Value value) {
  sink.WriteBytes(reinterpret_cast<const uint8_t*>(&value), sizeof(value));
}

template <typename Value>
void Serialize(ISink& sink, const Value& value);

inline void Serialize(ISink& sink, uint8_t value) {
  SerializeRaw(sink, value);
}

inline void Serialize(ISink& sink, uint32_t value) {
  SerializeRaw<uint64_t>(sink, value);
}

inline void Serialize(ISink& sink, uint64_t value) {
  SerializeRaw(sink, value);
}

inline void Serialize(ISink& sink, int32_t value) {
  SerializeRaw<int64_t>(sink, value);
}

inline void Serialize(ISink& sink, int64_t value) {
  SerializeRaw(sink, value);
}

inline void Serialize(ISink& sink, float value) {
  SerializeRaw(sink, value);
}

inline void Serialize(ISink& sink, double value) {
  SerializeRaw(sink, value);
}

inline void Serialize(ISink& sink, LogLevel value) {
  Serialize(sink, static_cast<int>(value));
}

template <typename VectorType>
inline void Serialize(ISink& sink, const std::vector<VectorType>& value) {
  Serialize(sink, value.size());
  for (const auto& item : value) {
    Serialize(sink, item);
  }
}

template <>
inline void Serialize(ISink& sink, const std::string& value) {
  Serialize(sink, value.size());
  sink.WriteBytes(reinterpret_cast<const uint8_t*>(value.data()), value.size());
}

#define NAVAL_SERIALIZE_FIELD(field) Serialize(sink, value.field);
#define NAVAL_SERIALIZE(Type, ...)                                \
  template <>                                                     \
  inline void Serialize(ISink& sink, const Type& value) {         \
    NAVAL_EXPAND(NAVAL_PASTE(NAVAL_SERIALIZE_FIELD, __VA_ARGS__)) \
  }

// tag.hpp
NAVAL_SERIALIZE(TagProperties, text_color, background_color, font_size)
NAVAL_SERIALIZE(Tag, name, value, properties, log_level);

// draw_properties.hpp
NAVAL_SERIALIZE(DrawProperties, border_color, fill_color, image_quality, line_thickness);

// message_metadata.hpp
NAVAL_SERIALIZE(MessageMetadata, level, tags, draw_properties);

// figure.hpp
NAVAL_SERIALIZE(Vertex, x, y);
NAVAL_SERIALIZE(Figure, metadata, vertices);

// image.hpp
template <>
void Serialize(ISink& sink, const Image& image);

// popup.hpp
NAVAL_SERIALIZE(Popup, metadata, text);

// log_packet.hpp
void Serialize(ISink& sink, const LogPacket& image);

}  // namespace naval::detail
