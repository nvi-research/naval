#include <naval/detail/serialization.hpp>

#include <cstddef>
#include <naval/draw_properties.hpp>
#include <naval/log_level.hpp>
#include <naval/message_metadata.hpp>

#include <naval/figure.hpp>
#include <naval/frame.hpp>
#include <naval/image.hpp>
#include <naval/tag.hpp>

namespace naval::detail {

template <typename Value>
void SerializeRawPrimitive(const Value& value, std::ostream& stream) {
  stream.write(reinterpret_cast<const std::ostream::char_type*>(&value), sizeof(value));
}

void SerializeRaw(uint8_t value, std::ostream& stream) {
  SerializeRawPrimitive<uint8_t>(value, stream);
}

void SerializeRaw(uint32_t value, std::ostream& stream) {
  SerializeRawPrimitive<uint32_t>(value, stream);
}

void SerializeRaw(uint64_t value, std::ostream& stream) {
  SerializeRawPrimitive<uint64_t>(value, stream);
}

void SerializeRaw(int32_t value, std::ostream& stream) {
  SerializeRawPrimitive<int32_t>(value, stream);
}

void SerializeRaw(const TagProperties& value, std::ostream& stream) {
  SerializeRaw(value.text_color, stream);
  SerializeRaw(value.background_color, stream);
}

void SerializeRaw(const std::string& value, std::ostream& stream) {
  SerializeRawPrimitive<size_t>(value.length(), stream);
  stream.write(value.c_str(), static_cast<std::streamsize>(value.length()));
}

template <typename ItemType>
void SerializeRaw(const std::vector<ItemType>& value, std::ostream& stream) {
  SerializeRawPrimitive<size_t>(value.size(), stream);
  for (const ItemType& item : value) {
    SerializeRaw(item, stream);
  }
}

template void SerializeRaw<std::string>(const std::vector<std::string>& value,
                                        std::ostream& stream);
template void SerializeRaw<uint8_t>(const std::vector<uint8_t>& value, std::ostream& stream);
template void SerializeRaw<uint32_t>(const std::vector<uint32_t>& value, std::ostream& stream);
template void SerializeRaw<Tag>(const std::vector<Tag>& value, std::ostream& stream);
template void SerializeRaw<Vertex>(const std::vector<Vertex>& value, std::ostream& stream);

void SerializeRaw(const Tag& value, std::ostream& stream) {
  SerializeRaw(value.name, stream);
  SerializeRaw(value.value, stream);
  SerializeRaw(value.properties, stream);
}

void SerializeRaw(const DrawProperties& value, std::ostream& stream) {
  SerializeRaw(value.border_color, stream);
  SerializeRaw(value.fill_color, stream);
  SerializeRaw(value.image_quality, stream);
}

void SerializeRaw(LogLevel value, std::ostream& stream) {
  SerializeRawPrimitive<uint32_t>(static_cast<uint32_t>(value), stream);
}

void SerializeRaw(const MessageMetadata& value, std::ostream& stream) {
  SerializeRaw(value.level, stream);
  SerializeRaw(value.tags, stream);
  SerializeRaw(value.draw_properties, stream);
}

void SerializeRaw(const Vertex& value, std::ostream& stream) {
  SerializeRawPrimitive<Vertex>(value, stream);
}

void SerializeRaw(const Figure& value, std::ostream& stream) {
  SerializeRaw(value.metadata, stream);
  SerializeRaw(value.vertices, stream);
}

void SerializeRaw(const Image& value, std::ostream& stream) {
  SerializeRaw(value.metadata, stream);
  value.Encode(stream);
}

void SerializeRaw(const Frame& value, std::ostream& stream) {
  SerializeRaw(value.GetFigures(), stream);
  value.EncodeAllImages(stream);
  // SerializeRaw(value.GetImages(), stream);
}

}  // namespace naval::detail
