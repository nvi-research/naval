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
 * @file stream_logger.hpp
 * @author Vyacheslav Zhdanovskiy (vyacheslav.zhdanovskiy@nvi-research.com)
 *
 * @copyright Copyright (c) 2023 NVI Research
 */

#pragma once

#include <cstdint>
#include <memory>

/**
 * @namespace naval
 * 
 * @brief The naval main namespace.
 * 
 */
namespace naval {

/**
 * @brief Magic bytes (file signature) of the .navalil file format.
 *
 */
constexpr uint64_t kMagicBytes = 0x4A4DECDE;
/**
 * @brief Current .navalil protocol version.
 *
 * Used by naval-player to check if it supports playing the current file.
 */
constexpr uint32_t kProtocolVersion = 3;

class LogPacket;
class ISink;

/**
 * @class StreamLogger
 * 
 * @brief Stream logger that the produces the output .navalil log file from LogPackets.
 * 
 * \see LogPacket
 */
class StreamLogger {
 public:
  /**
   * @brief Construct a new StreamLogger object.
   * 
   * @param sink The sink that StreamLogger should log to.
   */
  explicit StreamLogger(std::shared_ptr<ISink> sink);

  /**
   * @brief Logs the provided LogPacket.
   * 
   * @param packet The provided LogPacket.
   */
  void WritePacket(const LogPacket& packet);

 private:
  std::shared_ptr<ISink> sink_;
};

}  // namespace naval
