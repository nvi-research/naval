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

#include <naval/draw_properties.hpp>
#include <naval/image.hpp>
#include <naval/log_level.hpp>
#include <naval/tag.hpp>

static const std::string kLennaPath =
    (std::filesystem::path{__FILE__}.remove_filename() / "lenna.png").string();

namespace naval {

TEST(TestImage, LennaDoesExist) {
  std::filesystem::path lenna_path = std::filesystem::path{kLennaPath};
  ASSERT_TRUE(std::filesystem::is_regular_file(lenna_path)) << lenna_path << " does not exist";
}

static void DoTestImageEncoding(int quality, double min_threshold, double max_threshold) {
  cv::Mat image_mat = cv::imread(kLennaPath);
  Image image{{LogLevel::kDebug, {}, DrawProperties().WithImageQuality(quality)}, image_mat};

  std::stringstream stream;
  image.Encode(stream);

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
