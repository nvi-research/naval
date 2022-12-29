#pragma once

#include <vector>

#include <naval/log_level.hpp>
#include <naval/primitives/draw_properties.hpp>
#include <naval/primitives/tag.hpp>

namespace naval {

struct MessageMetadata {
  MessageMetadata(LogLevel level, std::vector<Tag> tags, const DrawProperties& draw_properties,
                  std::string file, int line)
      : level{level},
        tags{std::move(tags)},
        draw_properties{draw_properties},
        file{std::move(file)},
        line{line} {
  }

  LogLevel level;
  std::vector<Tag> tags;
  DrawProperties draw_properties;
  std::string file;
  int line;
};

inline bool operator==(const MessageMetadata& lhs, const MessageMetadata& rhs) {
  return lhs.level == rhs.level && lhs.tags == rhs.tags &&
         lhs.draw_properties == rhs.draw_properties;
}

}  // namespace naval
