#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <cstddef>
#include <cstdint>
#include <memory>
#include <sstream>
#include <string>

#include <naval/detail/sinks_impl.hpp>
#include <naval/log_packet.hpp>
#include <naval/sink.hpp>
#include <naval/stream_logger.hpp>

namespace naval {

class MockSink : public ISink {
 public:
  MOCK_METHOD(void, WriteBytes, (const uint8_t* data, size_t count), (override));
  MOCK_METHOD(void, Flush, (), (override));
};

TEST(TestStreamLogger, StreamLoggerCallsSink) {
  auto sink = std::make_shared<MockSink>();

  {
    using ::testing::_;
    using ::testing::AtLeast;
    using ::testing::InSequence;

    InSequence seq;
    EXPECT_CALL(*sink, WriteBytes(_, _)).Times(AtLeast(1));
    EXPECT_CALL(*sink, WriteBytes(_, _)).Times(AtLeast(1));
    EXPECT_CALL(*sink, WriteBytes(_, _)).Times(AtLeast(1));
    EXPECT_CALL(*sink, Flush());
  }

  StreamLogger stream_logger{sink, ""};
  LogPacket frame;
  stream_logger.WritePacket(frame);
}

TEST(TestStreamLogger, StreamLoggerWritesMagicBytesAndProtocolVersion) {
  std::stringstream stream;
  auto sink = std::make_shared<detail::StdOStreamSink>(stream);
  StreamLogger stream_logger{sink, ""};

  EXPECT_EQ(*reinterpret_cast<uint64_t*>(stream.str().data()), kMagicBytes);
  EXPECT_EQ(*reinterpret_cast<uint32_t*>(stream.str().data() + sizeof(uint64_t)), kProtocolVersion);
}

}  // namespace naval
