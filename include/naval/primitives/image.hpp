#pragma once

#include <opencv2/core/mat.hpp>
#include <opencv2/core/mat.inl.hpp>

#include <naval/primitives/message_metadata.hpp>

namespace naval {

class ISink;

struct Image {
  Image(const MessageMetadata& metadata, cv::Mat inner_image);
  void Encode(ISink& sink) const;

  MessageMetadata metadata;
  cv::Mat inner_image;
};

}  // namespace naval
