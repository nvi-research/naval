#pragma once

#include <memory>

namespace naval {

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
