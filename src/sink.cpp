#include <naval/sink.hpp>

#include <naval/detail/sinks_impl.hpp>

namespace naval {

std::shared_ptr<ISink> CreateNullLikeSink() {
  return std::make_shared<naval::detail::NullLikeSink>();
}

std::shared_ptr<ISink> CreateFileSink(const std::string& path) {
  return std::make_shared<naval::detail::FileSink>(path);
}

}  // namespace naval
