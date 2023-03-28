/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2023, NVI Research
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

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
    EXPECT_CALL(*sink, Flush());
  }

  StreamLogger stream_logger{sink};
  LogPacket frame{0.0};
  stream_logger.WritePacket(frame);
}

TEST(TestStreamLogger, StreamLoggerWritesMagicBytesAndProtocolVersion) {
  std::stringstream stream;
  auto sink = std::make_shared<detail::StdOStreamSink>(stream);
  StreamLogger stream_logger{sink};

  EXPECT_EQ(*reinterpret_cast<uint64_t*>(stream.str().data()), kMagicBytes);
  EXPECT_EQ(*reinterpret_cast<uint32_t*>(stream.str().data() + sizeof(uint64_t)), kProtocolVersion);
}

}  // namespace naval
