#pragma once

#include <ostream>

#include <opencv2/core/mat.hpp>
#include <opencv2/core/mat.inl.hpp>

#include <naval/message_metadata.hpp>

namespace naval {

struct Image {
  Image(const MessageMetadata& metadata, cv::Mat inner_image);
  void Encode(std::ostream& stream) const;

  MessageMetadata metadata;
  cv::Mat inner_image;
};

}  // namespace naval
