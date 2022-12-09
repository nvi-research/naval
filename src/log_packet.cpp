#include <naval/log_packet.hpp>

#include <algorithm>

#include <naval/primitives/figure.hpp>
#include <naval/primitives/image.hpp>

namespace naval {

std::vector<Figure> LogPacket::GetFigures() const {
  std::lock_guard lock{mutex_};
  return this->figures_;
}

std::vector<Image> LogPacket::GetImages() const {
  std::lock_guard lock{mutex_};
  return this->images_;
}

void LogPacket::AddFigure(Figure figure) {
  std::lock_guard lock{mutex_};
  this->figures_.push_back(std::move(figure));
}

void LogPacket::AddImage(Image image) {
  std::lock_guard lock{mutex_};
  this->images_.push_back(std::move(image));
}

}  // namespace naval
