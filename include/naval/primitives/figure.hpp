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

/**
 * @file figure.hpp
 * @author Vyacheslav Zhdanovskiy (vyacheslav.zhdanovskiy@nvi-research.com)
 *
 * @copyright Copyright (c) 2023 NVI Research
 */
#pragma once

#include <limits>
#include <vector>

#include <naval/primitives/message_metadata.hpp>

namespace naval {

/**
 * @struct Vertex
 * 
 * @brief A 2D Vertex.
 * 
 */
struct Vertex {
  /**
   * @brief Construct a new Vertex object
   * 
   */
  Vertex();

  /**
   * @brief Construct a new Vertex object ( @p x @p y )
   * 
   * @param x 
   * @param y 
   */
  Vertex(float x, float y);

  bool operator==(const Vertex& other) const {
    constexpr float kEpsilon = std::numeric_limits<float>::epsilon();
    return std::abs(x - other.x) < kEpsilon && std::abs(y - other.y) < kEpsilon;
  }

  float x;
  float y;
};

/**
 * @struct Figure
 * 
 * @brief Polygon-like Figure.
 * 
 */
struct Figure {
  /**
   * @brief Construct a new Figure object.
   * 
   * @param metadata Figure metadata.
   * @param vertices Figure vertices.
   */
  Figure(const MessageMetadata& metadata, std::vector<Vertex> vertices);

  MessageMetadata metadata;
  std::vector<Vertex> vertices;
};

/**
 * @brief Functions that converts arbirtarty GeometryType to vector of vertices.
 * 
 * User has to provide a specialization for this function for his own geometry types.
 */
template <typename GeometryType>
std::vector<Vertex> ConvertToVertices(const GeometryType& geometry);

inline bool operator==(const Figure& lhs, const Figure& rhs) {
  return lhs.metadata == rhs.metadata && lhs.vertices == rhs.vertices;
}

}  // namespace naval
