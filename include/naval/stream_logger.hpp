#pragma once

#include <cstdint>
#include <memory>

namespace naval {

constexpr uint64_t kMagicBytes = 0x4A4DECDE;
constexpr uint32_t kProtocolVersion = 0;

class LogPacket;
class ISink;

class StreamLogger {
 public:
  explicit StreamLogger(std::shared_ptr<ISink> sink);
  void WritePacket(const LogPacket& packet);

 private:
  std::shared_ptr<ISink> sink_;
};

}  // namespace naval
