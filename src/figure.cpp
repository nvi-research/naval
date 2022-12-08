#include <naval/figure.hpp>

#include <utility>

namespace naval {
struct MessageMetadata;
}

namespace naval {

Vertex::Vertex() : x{0.0F}, y{0.0F} {
}

Vertex::Vertex(float x, float y) : x{x}, y{y} {
}

Figure::Figure(const MessageMetadata& metadata, std::vector<Vertex> vertices)
    : metadata{metadata}, vertices{std::move(vertices)} {
}

}  // namespace naval
