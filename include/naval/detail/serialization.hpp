#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <naval/detail/macros.hpp>
#include <naval/log_level.hpp>
#include <naval/primitives/draw_properties.hpp>
#include <naval/primitives/figure.hpp>
#include <naval/primitives/message_metadata.hpp>
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
NAVAL_SERIALIZE(Tag, name, value, properties);

// draw_properties.hpp
NAVAL_SERIALIZE(DrawProperties, border_color, fill_color, image_quality, line_thickness);

// message_metadata.hpp
NAVAL_SERIALIZE(MessageMetadata, level, tags, draw_properties, file, line);

// figure.hpp
NAVAL_SERIALIZE(Vertex, x, y);
NAVAL_SERIALIZE(Figure, metadata, vertices);

// image.hpp
template <>
void Serialize(ISink& sink, const Image& image);

// log_packet.hpp
void Serialize(ISink& sink, const LogPacket& image);

}  // namespace naval::detail
