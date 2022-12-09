#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <cstddef>
#include <cstdint>
#include <memory>

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
    EXPECT_CALL(*sink, Flush());
  }

  StreamLogger stream_logger{sink};
  LogPacket frame;
  stream_logger.WritePacket(frame);
}

}  // namespace naval
