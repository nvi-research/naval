#pragma once

#include <mutex>
#include <ostream>
#include <utility>
#include <vector>

#include <naval/figure.hpp>
#include <naval/image.hpp>
#include <naval/log_level.hpp>
#include <naval/message_metadata.hpp>
#include <naval/tag.hpp>

namespace cv {
class Mat;
}

namespace naval {

struct DrawProperties;

class Frame {
 public:
  std::vector<Figure> GetFigures() const;
  std::vector<Image> GetImages() const;
  void EncodeAllImages(std::ostream& stream) const;

  template <typename Value>
  void Info(Value value, std::vector<Tag> tags = {}, const DrawProperties& properties = {}) {
    Log(LogLevel::kInfo, std::move(value), std::move(tags), properties);
  }

  template <typename Value>
  void Debug(Value value, std::vector<Tag> tags = {}, const DrawProperties& properties = {}) {
    Log(LogLevel::kDebug, std::move(value), std::move(tags), properties);
  }

  template <typename Value>
  void Log(LogLevel log_level, Value value, std::vector<Tag> tags,
           const DrawProperties& properties) {
    // User has to provide a function for conversion between outer value type
    // and our vector of vertices
    MessageMetadata metadata{log_level, std::move(tags), properties};

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

}  // namespace naval
