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

#include "gtest/gtest.h"

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <naval/detail/sinks_impl.hpp>

namespace naval::detail {

static const std::vector<uint8_t> kTestSinkData = {0xDE, 0xAD, 0xBE, 0xBF};

TEST(TestSinksImpl, NullLikeSink) {
  NullLikeSink sink;
  EXPECT_NO_THROW({ sink.WriteBytes(nullptr, 1U); });
  EXPECT_NO_THROW({ sink.Flush(); });
}

static void CompareStdIStreamWithBuffer(std::istream& stream,
                                        const std::vector<uint8_t>& expected_buffer) {
  std::vector<uint8_t> buffer(expected_buffer.size());
  stream.read(reinterpret_cast<char*>(buffer.data()), expected_buffer.size());
  for (size_t index = 0; index < expected_buffer.size(); ++index) {
    EXPECT_EQ(buffer[index], expected_buffer[index])
        << "Vectors buffer and expected_buffer differ at index";
  }
}

TEST(TestSinksImpl, FileSink) {
  const auto test_file_path =
      std::filesystem::path{::testing::TempDir()} / "tests_sinks_impl_file_sink";
  {
    FileSink sink{test_file_path};
    sink.WriteBytes(kTestSinkData.data(), kTestSinkData.size());
    sink.Flush();
  }
  ASSERT_TRUE(std::filesystem::exists(test_file_path));

  std::ifstream stream{test_file_path.string(), std::ios::binary};
  ASSERT_TRUE(stream.is_open());
  CompareStdIStreamWithBuffer(stream, kTestSinkData);
  std::filesystem::remove(test_file_path);
}

TEST(TestSinksImpl, FileSinkThrows) {
  EXPECT_THROW({ FileSink sink{"////////"}; }, std::runtime_error);
}

TEST(TestSinksImpl, StdOStreamSink) {
  std::stringstream stream;
  StdOStreamSink sink{stream};
  sink.WriteBytes(kTestSinkData.data(), kTestSinkData.size());
  stream.seekp(0);

  CompareStdIStreamWithBuffer(stream, kTestSinkData);
}

}  // namespace naval::detail
