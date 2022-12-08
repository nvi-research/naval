#pragma once

#include <cstdint>
#include <ostream>
#include <string>
#include <vector>

#include <naval/log_level.hpp>

namespace naval {

class Frame;
struct DrawProperties;
struct Figure;
struct Image;
struct MessageMetadata;
struct Tag;
struct TagProperties;
struct Vertex;

}  // namespace naval

namespace naval::detail {

void SerializeRaw(uint8_t value, std::ostream& stream);
void SerializeRaw(uint32_t value, std::ostream& stream);
void SerializeRaw(uint64_t value, std::ostream& stream);
void SerializeRaw(int32_t value, std::ostream& stream);
void SerializeRaw(const std::string& value, std::ostream& stream);
template <typename ItemType>
void SerializeRaw(const std::vector<ItemType>& value, std::ostream& stream);
void SerializeRaw(const TagProperties& value, std::ostream& stream);
void SerializeRaw(const Tag& value, std::ostream& stream);
void SerializeRaw(const DrawProperties& value, std::ostream& stream);
void SerializeRaw(LogLevel value, std::ostream& stream);
void SerializeRaw(const MessageMetadata& value, std::ostream& stream);
void SerializeRaw(const Vertex& value, std::ostream& stream);
void SerializeRaw(const Figure& value, std::ostream& stream);
void SerializeRaw(const Image& value, std::ostream& stream);
void SerializeRaw(const Frame& value, std::ostream& stream);

}  // namespace naval::detail
