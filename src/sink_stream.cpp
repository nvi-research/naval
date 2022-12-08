#include <naval/sink_stream.hpp>

#include <cassert>
#include <ostream>
#include <utility>

#include <naval/detail/serialization.hpp>
#include <naval/sink.hpp>

namespace naval {

SinkStream::SinkStream(std::shared_ptr<ISink> sink, const std::string& stream_url)
    : sink_{std::move(sink)} {
  assert(sink_ != nullptr && "Expected non-null sink pointer");
  detail::SerializeRaw(stream_url, sink_->GetStream());
}

void SinkStream::WriteFrame(const Frame& frame) {
  detail::SerializeRaw(frame, sink_->GetStream());
}

void SinkStream::Flush() {
  sink_->GetStream().flush();
}

}  // namespace naval
