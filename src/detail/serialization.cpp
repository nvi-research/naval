#include <naval/detail/serialization.hpp>

#include <naval/log_packet.hpp>
#include <naval/primitives/image.hpp>

namespace naval {

class ISink;

}

namespace naval::detail {

template <>
void Serialize(ISink& sink, const Image& value) {
  Serialize(sink, value.metadata);
  value.Encode(sink);
}

void Serialize(ISink& sink, const LogPacket& value) {
  Serialize(sink, value.GetTimestamp());
  Serialize(sink, value.GetFigures());
  Serialize(sink, value.GetImages());
}

}  // namespace naval::detail
