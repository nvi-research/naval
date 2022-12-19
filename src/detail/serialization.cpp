#include <naval/detail/serialization.hpp>

#include <cstddef>

#include <naval/log_level.hpp>
#include <naval/log_packet.hpp>
#include <naval/primitives/draw_properties.hpp>
#include <naval/primitives/figure.hpp>
#include <naval/primitives/image.hpp>
#include <naval/primitives/message_metadata.hpp>
#include <naval/primitives/tag.hpp>
#include <naval/sink.hpp>

namespace naval::detail {

template <typename Value>
void SerializeRawPrimitive(const Value& value, ISink& sink) {
  sink.WriteBytes(reinterpret_cast<const uint8_t*>(&value), sizeof(value));
}

void SerializeRaw(uint8_t value, ISink& sink) {
  SerializeRawPrimitive<uint8_t>(value, sink);
}

void SerializeRaw(uint32_t value, ISink& sink) {
  SerializeRawPrimitive<uint32_t>(value, sink);
}

void SerializeRaw(uint64_t value, ISink& sink) {
  SerializeRawPrimitive<uint64_t>(value, sink);
}

void SerializeRaw(int32_t value, ISink& sink) {
  SerializeRawPrimitive<int32_t>(value, sink);
}

void SerializeRaw(const TagProperties& value, ISink& sink) {
  SerializeRaw(value.text_color, sink);
  SerializeRaw(value.background_color, sink);
  SerializeRaw(value.font_size, sink);
}

void SerializeRaw(const std::string& value, ISink& sink) {
  SerializeRawPrimitive<size_t>(value.length(), sink);
  sink.WriteBytes(reinterpret_cast<const uint8_t*>(value.c_str()), value.length());
}

template <typename ItemType>
void SerializeRaw(const std::vector<ItemType>& value, ISink& sink) {
  SerializeRawPrimitive<size_t>(value.size(), sink);
  for (const ItemType& item : value) {
    SerializeRaw(item, sink);
  }
}

template void SerializeRaw<std::string>(const std::vector<std::string>& value, ISink& sink);
template void SerializeRaw<uint8_t>(const std::vector<uint8_t>& value, ISink& sink);
template void SerializeRaw<uint32_t>(const std::vector<uint32_t>& value, ISink& sink);
template void SerializeRaw<Tag>(const std::vector<Tag>& value, ISink& sink);
template void SerializeRaw<Vertex>(const std::vector<Vertex>& value, ISink& sink);

void SerializeRaw(const Tag& value, ISink& sink) {
  SerializeRaw(value.name, sink);
  SerializeRaw(value.value, sink);
  SerializeRaw(value.properties, sink);
}

void SerializeRaw(const DrawProperties& value, ISink& sink) {
  SerializeRaw(value.border_color, sink);
  SerializeRaw(value.fill_color, sink);
  SerializeRaw(value.image_quality, sink);
}

void SerializeRaw(LogLevel value, ISink& sink) {
  SerializeRawPrimitive<uint32_t>(static_cast<uint32_t>(value), sink);
}

void SerializeRaw(const MessageMetadata& value, ISink& sink) {
  SerializeRaw(value.level, sink);
  SerializeRaw(value.tags, sink);
  SerializeRaw(value.draw_properties, sink);
}

void SerializeRaw(const Vertex& value, ISink& sink) {
  SerializeRawPrimitive<Vertex>(value, sink);
}

void SerializeRaw(const Figure& value, ISink& sink) {
  SerializeRaw(value.metadata, sink);
  SerializeRaw(value.vertices, sink);
}

void SerializeRaw(const Image& value, ISink& sink) {
  SerializeRaw(value.metadata, sink);
  value.Encode(sink);
}

void SerializeRaw(const LogPacket& value, ISink& stream) {
  SerializeRaw(value.GetFigures(), stream);
  SerializeRaw(value.GetImages(), stream);
}

}  // namespace naval::detail
