#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>

namespace naval {

class ISink {
 public:
  virtual void WriteBytes(const uint8_t* data, size_t count) = 0;
  virtual void Flush() = 0;
  virtual ~ISink() = default;
};

std::shared_ptr<ISink> CreateNullLikeSink();
std::shared_ptr<ISink> CreateFileSink(const std::string& path);

}  // namespace naval
