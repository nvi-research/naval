#pragma once

#include <mutex>
#include <string>
#include <utility>
#include <vector>

#include <naval/log_level.hpp>
#include <naval/primitives/figure.hpp>
#include <naval/primitives/image.hpp>
#include <naval/primitives/message_metadata.hpp>
#include <naval/primitives/tag.hpp>

namespace cv {
class Mat;
}

namespace naval {

struct DrawProperties;

class LogPacket {
 public:
  std::vector<Figure> GetFigures() const;
  std::vector<Image> GetImages() const;

  template <typename Value>
  void Log(std::string file, int line, LogLevel log_level, Value value, std::vector<Tag> tags,
           const DrawProperties& properties) {
    // User has to provide a function for conversion between outer value type
    // and our vector of vertices
    MessageMetadata metadata{log_level, std::move(tags), properties, std::move(file), line};

    std::lock_guard lock{mutex_};
    if constexpr (std::is_same_v<cv::Mat, Value>) {
      images_.emplace_back(metadata, std::move(value));
    } else {
      figures_.emplace_back(metadata, ConvertToVertices(value));
    }
  }

  void AddFigure(Figure figure);
  void AddImage(Image image);

 private:
  mutable std::mutex mutex_;
  std::vector<Figure> figures_;
  std::vector<Image> images_;
};

#define NAVAL_DEBUG(log_packet, value, tags, draw_properties)                             \
  do {                                                                                    \
    (log_packet).Log(__FILE__, __LINE__, LogLevel::kDebug, value, tags, draw_properties); \
  } while (false)

#define NAVAL_INFO(log_packet, value, tags, draw_properties)                             \
  do {                                                                                   \
    (log_packet).Log(__FILE__, __LINE__, LogLevel::kInfo, value, tags, draw_properties); \
  } while (false)

}  // namespace naval
