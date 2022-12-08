#include "gtest/gtest.h"

#include <string>

#include <naval/frame.hpp>
#include <naval/noop_stream.hpp>

namespace naval {

TEST(TestNoopStream, NoopStreamDoesNothing) {
  NoopStream stream;

  Frame frame;
  EXPECT_NO_THROW(stream.WriteFrame(frame));
  EXPECT_NO_THROW(stream.Flush());
}

}  // namespace naval
