#include <naval/stream_logger.hpp>

#include <cassert>
#include <utility>

#include <naval/detail/serialization.hpp>
#include <naval/sink.hpp>

namespace naval {

StreamLogger::StreamLogger(std::shared_ptr<ISink> sink) : sink_{std::move(sink)} {
  assert(sink_ != nullptr && "Expected non-null sink");
  detail::Serialize(*sink_, kMagicBytes);
  detail::Serialize(*sink_, kProtocolVersion);
}

void StreamLogger::WritePacket(const LogPacket& packet) {
  detail::Serialize(*sink_, packet);
  sink_->Flush();
}

}  // namespace naval
