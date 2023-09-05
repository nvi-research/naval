#include <naval/primitives/popup.hpp>

namespace naval {

Popup::Popup(const MessageMetadata& metadata, std::string text)
    : metadata{metadata}, text{std::move(text)} {
}

}  // namespace naval
