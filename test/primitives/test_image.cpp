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
#include <sstream>
#include <string>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/mat.inl.hpp>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgcodecs.hpp>

#include <naval/detail/sinks_impl.hpp>
#include <naval/log_level.hpp>
#include <naval/primitives/draw_properties.hpp>
#include <naval/primitives/image.hpp>
#include <naval/primitives/tag.hpp>

static const std::string kLennaPath =
    (std::filesystem::path{__FILE__}.remove_filename() / "../lenna.png").string();

namespace naval {

TEST(TestImage, LennaDoesExist) {
  std::filesystem::path lenna_path = std::filesystem::path{kLennaPath};
  ASSERT_TRUE(std::filesystem::is_regular_file(lenna_path)) << lenna_path << " does not exist";
}

static void DoTestImageEncoding(int quality, double min_threshold, double max_threshold) {
  cv::Mat image_mat = cv::imread(kLennaPath);
  Image image{{LogLevel::kDebug, {}, DrawProperties().WithImageQuality(quality)}, image_mat};

  std::stringstream stream;
  detail::StdOStreamSink sink{stream};
  image.Encode(sink);

  size_t buffer_size;
  stream.read(reinterpret_cast<char*>(&buffer_size), sizeof(buffer_size));
  std::vector<uint8_t> data(buffer_size);
  stream.read(reinterpret_cast<char*>(data.data()), buffer_size);

  cv::Mat written_mat = cv::imdecode(data, cv::IMREAD_COLOR);
  cv::Mat absdiff;
  cv::absdiff(image_mat, written_mat, absdiff);
  cv::Scalar sum = cv::sum(absdiff);
  const double all_channels_sum = sum[0] + sum[1] + sum[3];
  ASSERT_LE(all_channels_sum / (written_mat.rows * written_mat.cols), max_threshold);
  ASSERT_GE(all_channels_sum / (written_mat.rows * written_mat.cols), min_threshold);
}

TEST(TestImage, EncodingWithHighQuality) {
  DoTestImageEncoding(100, 0.0, 5.0);
}

TEST(TestImage, EncodingWithLowQuality) {
  DoTestImageEncoding(50, 5.0, 10.0);
}

}  // namespace naval
