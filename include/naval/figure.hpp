#pragma once

#include <limits>
#include <vector>

#include <naval/message_metadata.hpp>

namespace naval {

struct Vertex {
  Vertex();
  Vertex(float x, float y);

  bool operator==(const Vertex& other) const {
    constexpr float kEpsilon = std::numeric_limits<float>::epsilon();
    return std::abs(x - other.x) < kEpsilon && std::abs(y - other.y) < kEpsilon;
  }

  float x;
  float y;
};

struct Figure {
  Figure(const MessageMetadata& metadata, std::vector<Vertex> vertices);

  MessageMetadata metadata;
  std::vector<Vertex> vertices;
};

template <typename GeometryType>
std::vector<Vertex> ConvertToVertices(const GeometryType& geometry);

inline bool operator==(const Figure& lhs, const Figure& rhs) {
  return lhs.metadata == rhs.metadata && lhs.vertices == rhs.vertices;
}

}  // namespace naval
