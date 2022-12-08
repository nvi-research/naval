#pragma once

#include <naval/stream.hpp>

namespace naval {

class NoopStream : public IStream {
 public:
  void WriteFrame(const Frame& /*frame*/) override {
  }

  void Flush() override {
  }
};

}  // namespace naval
