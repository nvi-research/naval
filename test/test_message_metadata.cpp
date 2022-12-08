#include "gtest/gtest.h"

#include <vector>

#include <naval/log_level.hpp>
#include <naval/message_metadata.hpp>
#include <naval/tag.hpp>

namespace naval {

TEST(TestMessageMetadata, Constructor) {
  // TODO: better tests here
  {
    const LogLevel level = LogLevel::kTrace;
    MessageMetadata metadata{level, {}};

    EXPECT_EQ(metadata.level, level);
    EXPECT_EQ(metadata.tags.size(), 0);
  }
  {
    const LogLevel level = LogLevel::kDebug;
    MessageMetadata metadata{level, {}, {}};

    EXPECT_EQ(metadata.level, level);
    EXPECT_EQ(metadata.tags.size(), 0);
  }
}

}  // namespace naval
