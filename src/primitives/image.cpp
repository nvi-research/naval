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

  detail::Serialize(sink, memory_buffer);
}

}  // namespace naval
