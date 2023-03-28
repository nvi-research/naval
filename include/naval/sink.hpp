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
 * @file sink.hpp
 * @author Vyacheslav Zhdanovskiy (vyacheslav.zhdanovskiy@nvi-research.com)
 *
 * @copyright Copyright (c) 2023 NVI Research
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>

namespace naval {

/**
 * @class ISink
 * 
 * @brief Interface that encapsulating where and how the logger should write its data.
 * 
 */
class ISink {
 public:
  /**
   * @brief Writes @p count bytes starting from @p data.
   * 
   * @param data Data pointer.
   * @param count Data byte length.
   */
  virtual void WriteBytes(const uint8_t* data, size_t count) = 0;

  /**
   * @brief Flushes the current sink contents.
   * 
   */
  virtual void Flush() = 0;

  /**
   * @brief Destroy the ISink object
   * 
   */
  virtual ~ISink() = default;
};

/**
 * @brief Create a /dev/null-like ISink object.
 * 
 * This sink will do nothing.
 * 
 */
std::shared_ptr<ISink> CreateNullLikeSink();

/**
 * @brief Create a ISink object that will write to @p path.
 * 
 */
std::shared_ptr<ISink> CreateFileSink(const std::string& path);

}  // namespace naval
