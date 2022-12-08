#pragma once

#include <memory>

namespace naval {

class Frame;

class IStream {
 public:
  virtual void WriteFrame(const Frame& frame) = 0;
  virtual void Flush() = 0;

  virtual ~IStream() = default;
};

}  // namespace naval
