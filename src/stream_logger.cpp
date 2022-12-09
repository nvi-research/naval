#include <naval/stream_logger.hpp>

#include <cassert>
#include <utility>

#include <naval/detail/serialization.hpp>
#include <naval/sink.hpp>

namespace naval {

StreamLogger::StreamLogger(std::shared_ptr<ISink> sink) : sink_{std::move(sink)} {
  assert(sink_ != nullptr && "Expected non-null sink");
}

void StreamLogger::WriteFrame(const LogPacket& frame) {
  detail::SerializeRaw(frame, *sink_);
  sink_->Flush();
}

}  // namespace naval
