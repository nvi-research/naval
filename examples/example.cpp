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

#include <filesystem>
#include <iostream>
#include <vector>

#include <naval/log_packet.hpp>
#include <naval/sink.hpp>
#include <naval/stream_logger.hpp>
#include <opencv2/videoio.hpp>

namespace fs = std::filesystem;

namespace my_namespace {

// This is user-defined rect that that we want to log
struct MyRect {
  MyRect(float x, float y, float width, float height) : x{x}, y{y}, width{width}, height{height} {
  }

  float x;
  float y;
  float width;
  float height;
};

}  // namespace my_namespace

namespace naval {

// User has to provide this function to convert from his types into naval primitives
template <>
inline std::vector<Vertex> ConvertToVertices(const my_namespace::MyRect& geometry) {
  const auto [x, y, width, height] = geometry;
  return {{x + width, y}, {x + width, y + height}, {x, y + height}, {x, y}};
}

}  // namespace naval

int main() {
  // Video is located alongside the source .cpp
  const fs::path video_path = fs::path{__FILE__}.remove_filename() / "bunny.mp4";
  // Log file location is small_bunny_1080p_60fps.mp4.navalil
  const fs::path log_path = fs::path{video_path}.replace_extension(".mp4.navalil");
  cv::VideoCapture video_capture{video_path.string()};

  naval::StreamLogger stream_logger{naval::CreateFileSink(log_path)};

  while (true) {
    cv::Mat frame;
    const double timestamp_sec = video_capture.get(cv::CAP_PROP_POS_MSEC) / 1000;
    std::cout << "Processing frame with ts_sec = " << timestamp_sec << "\n";
    if (!video_capture.read(frame)) {
      break;
    }

    my_namespace::MyRect rect{300, 300, 300, 300};
    naval::LogPacket log_packet{timestamp_sec};
    log_packet.Info(rect, {{"Object type", "Simple rect"}, {"Metadata", "Lots of information!"}});

    stream_logger.WritePacket(log_packet);
  }

  return 0;
}
