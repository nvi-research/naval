#include <naval/frame.hpp>

#include <algorithm>
#include <cstdint>

#include <naval/detail/serialization.hpp>
#include <naval/figure.hpp>
#include <naval/image.hpp>

namespace naval {

std::vector<Figure> Frame::GetFigures() const {
  std::lock_guard lock{mutex_};
  return this->figures_;
}

std::vector<Image> Frame::GetImages() const {
  std::lock_guard lock{mutex_};
  return this->images_;
}

void Frame::AddFigure(Figure figure) {
  std::lock_guard lock{mutex_};
  this->figures_.push_back(std::move(figure));
}

void Frame::AddImage(Image image) {
  std::lock_guard lock{mutex_};
  this->images_.push_back(std::move(image));
}

void Frame::EncodeAllImages(std::ostream& stream) const {
  std::lock_guard lock{mutex_};

  detail::SerializeRaw(static_cast<uint64_t>(images_.size()), stream);
  for (const auto& image : images_) {
    image.Encode(stream);
  }
}

}  // namespace naval
