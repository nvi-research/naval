#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <naval/log_level.hpp>

namespace naval {

class ISink;
class LogPacket;
struct DrawProperties;
struct Figure;
struct Image;
struct MessageMetadata;
struct Tag;
struct TagProperties;
struct Vertex;

}  // namespace naval

namespace naval::detail {

void SerializeRaw(uint8_t value, ISink& sink);
void SerializeRaw(uint32_t value, ISink& sink);
void SerializeRaw(uint64_t value, ISink& sink);
void SerializeRaw(int32_t value, ISink& sink);
void SerializeRaw(const std::string& value, ISink& sink);
template <typename ItemType>
void SerializeRaw(const std::vector<ItemType>& value, ISink& sink);
void SerializeRaw(const TagProperties& value, ISink& sink);
void SerializeRaw(const Tag& value, ISink& sink);
void SerializeRaw(const DrawProperties& value, ISink& sink);
void SerializeRaw(LogLevel value, ISink& sink);
void SerializeRaw(const MessageMetadata& value, ISink& sink);
void SerializeRaw(const Vertex& value, ISink& sink);
void SerializeRaw(const Figure& value, ISink& sink);
void SerializeRaw(const Image& value, ISink& sink);
void SerializeRaw(const LogPacket& value, ISink& sink);

}  // namespace naval::detail
