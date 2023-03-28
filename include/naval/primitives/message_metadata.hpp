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

/**
 * @file message_metadata.hpp
 * @author Vyacheslav Zhdanovskiy (vyacheslav.zhdanovskiy@nvi-research.com)
 *
 * @copyright Copyright (c) 2023 NVI Research
 */

#pragma once

#include <vector>

#include <naval/log_level.hpp>
#include <naval/primitives/draw_properties.hpp>
#include <naval/primitives/tag.hpp>

namespace naval {

/**
 * @struct MessageMetadata
 * 
 * @brief Message metadata that contains log level, tags, draw properties.
 * 
 */
struct MessageMetadata {
  MessageMetadata(LogLevel level, std::vector<Tag> tags, const DrawProperties& draw_properties)
      : level{level}, tags{std::move(tags)}, draw_properties{draw_properties} {
  }

  LogLevel level;
  std::vector<Tag> tags;
  DrawProperties draw_properties;
};

inline bool operator==(const MessageMetadata& lhs, const MessageMetadata& rhs) {
  return lhs.level == rhs.level && lhs.tags == rhs.tags &&
         lhs.draw_properties == rhs.draw_properties;
}

}  // namespace naval
