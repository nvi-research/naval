#pragma once

#include <memory>
#include <string>

#include <naval/stream.hpp>

namespace naval {

class Frame;
class ISink;

class SinkStream : public IStream {
 public:
  SinkStream(std::shared_ptr<ISink> sink, const std::string& stream_url);

  void WriteFrame(const Frame& frame) override;
  void Flush() override;

 private:
  std::shared_ptr<ISink> sink_;
};

}  // namespace naval
