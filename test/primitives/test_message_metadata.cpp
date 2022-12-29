#include "gtest/gtest.h"

#include <string>
#include <vector>

#include <naval/log_level.hpp>
#include <naval/primitives/message_metadata.hpp>
#include <naval/primitives/tag.hpp>

namespace naval {

TEST(TestMessageMetadata, Constructor) {
  // TODO: better tests here
  {
    const LogLevel level = LogLevel::kTrace;
    MessageMetadata metadata{level, {}, {}, "", 0};

    EXPECT_EQ(metadata.level, level);
    EXPECT_EQ(metadata.tags.size(), 0);
  }
}

}  // namespace naval
