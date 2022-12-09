#include <naval/primitives/image.hpp>

#include <cassert>
#include <cstdint>
#include <utility>
#include <vector>

#include <opencv2/imgcodecs.hpp>

#include <naval/detail/serialization.hpp>
#include <naval/primitives/draw_properties.hpp>
#include <naval/primitives/message_metadata.hpp>

namespace naval {

Image::Image(const MessageMetadata& metadata, cv::Mat inner_image)
    : metadata{metadata}, inner_image{std::move(inner_image)} {
  assert(0 <= metadata.draw_properties.image_quality &&
         metadata.draw_properties.image_quality <= 100 &&
         "Image quality is out of [0, 100] bounds");
}

void Image::Encode(ISink& sink) const {
  std::vector<uint8_t> memory_buffer;

  cv::imencode(".jpg", inner_image, memory_buffer,
               {cv::IMWRITE_JPEG_QUALITY, metadata.draw_properties.image_quality});

  detail::SerializeRaw(memory_buffer, sink);
}

}  // namespace naval
