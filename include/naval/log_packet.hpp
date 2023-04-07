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
 * @file log_packet.hpp
 * @author Vyacheslav Zhdanovskiy (vyacheslav.zhdanovskiy@nvi-research.com)
 *
 * @copyright Copyright (c) 2023 NVI Research
 */

#pragma once

#include <mutex>
#include <utility>
#include <vector>

#include <naval/log_level.hpp>
#include <naval/primitives/figure.hpp>
#include <naval/primitives/image.hpp>
#include <naval/primitives/message_metadata.hpp>
#include <naval/primitives/tag.hpp>

namespace cv {
class Mat;
}

namespace naval {

struct DrawProperties;

/**
 * @class LogPacket
 * 
 * @brief Log contents for a single video frame.
 * 
 */
class LogPacket {
 public:
  /**
   * @brief LogPacket timestamp type.
   * 
   */
  using Timestamp = double;

 public:
  /**
   * @brief Construct a new Log Packet object
   * 
   * @param timestamp_sec Timestamp of the LogPacket.
   */
  explicit LogPacket(Timestamp timestamp_sec) : timestamp_sec_{timestamp_sec} {
  }

  /**
   * @brief Returns the contained Figure objects.
   * 
   * @see Figure
   */
  std::vector<Figure> GetFigures() const;

  /**
   * @brief Returns the contained Image objects.
   * 
   * @see Image
   */
  std::vector<Image> GetImages() const;

  /**
   * @brief Log value with Info level.
   * 
   * A handy wrapper over Log() method.
   * 
   * @see Log
   */
  template <typename Value>
  void Info(Value value, std::vector<Tag> tags = {}, const DrawProperties& properties = {}) {
    Log(LogLevel::kInfo, std::move(value), std::move(tags), std::move(properties));
  }

  /**
   * @brief Log value with Info level.
   * 
   * A handy wrapper over Log() method.
   * 
   * @see Log
   */
  template <typename Value>
  void Debug(Value value, std::vector<Tag> tags = {}, const DrawProperties& properties = {}) {
    Log(LogLevel::kDebug, std::move(value), std::move(tags), std::move(properties));
  }

  /**
   * @brief Logs @p value.
   * 
   * @tparam Value Value type.
   * @param log_level Log level.
   * @param value Value.
   * @param tags Vector of Tag.
   * @param properties DrawProperties.
   * 
   * @see LogLevel, Value, DrawProperties
   */
  template <typename Value>
  void Log(LogLevel log_level, Value value, std::vector<Tag> tags,
           const DrawProperties& properties) {
    // User has to provide a function for conversion between outer value type
    // and our vector of vertices
    MessageMetadata metadata{log_level, std::move(tags), properties};

    std::lock_guard lock{mutex_};
    if constexpr (std::is_same_v<cv::Mat, Value>) {
      images_.emplace_back(metadata, std::move(value));
    } else {
      figures_.emplace_back(metadata, ConvertToVertices(value));
    }
  }

  /**
   * @brief Add a new Figure to the LogPacket.
   * 
   * @param figure Figure.
   * 
   * @see Figure.
   */
  void AddFigure(Figure figure);

  /**
   * @brief Add a new Image to the LogPacket.
   * 
   * @param figure Image.
   * 
   * @see Image.
   */
  void AddImage(Image image);

  /**
   * @brief Get the LogPacket timestamp.
   */
  Timestamp GetTimestamp() const {
    return timestamp_sec_;
  }

 private:
  mutable std::mutex mutex_;
  Timestamp timestamp_sec_;
  std::vector<Figure> figures_;
  std::vector<Image> images_;
};

}  // namespace naval
