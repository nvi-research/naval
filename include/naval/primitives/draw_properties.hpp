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
 * @file draw_properties.hpp
 * @author Vyacheslav Zhdanovskiy (vyacheslav.zhdanovskiy@nvi-research.com)
 *
 * @copyright Copyright (c) 2023 NVI Research
 */

#pragma once

#include <cstdint>

#include <naval/colors.hpp>

namespace naval {

/**
 * @struct DrawProperties
 * 
 * @brief Draw properties of a log primitive.
 * 
 */
struct DrawProperties {
  /**
   * @brief Construct a new DrawProperties object
   * 
   */
  DrawProperties();

  /**
   * @brief Creates a copy of DrawProperties with new border color.
   * 
   * @param border_color Border color.
   */
  DrawProperties WithBorderColor(Color border_color) const;

  /**
   * @brief Creates a copy of DrawProperties with new fill color.
   * 
   * @param fill_color Fill color.
   */
  DrawProperties WithFillColor(Color fill_color) const;

  /**
   * @brief Creates a copy of DrawProperties with new image quality.
   * 
   * @param image_quality Image quality [0<=x<=100].
   */
  DrawProperties WithImageQuality(int32_t image_quality) const;

  /**
   * @brief Creates a copy of DrawProperties with new line thickness.
   * 
   * @param line_thickness Line thickness [0<=x<=100].
   */
  DrawProperties WithLineThickness(int32_t line_thickness) const;

  /**
   * @brief Border color.
   * 
   */
  Color border_color;
  /**
   * @brief Fill color.
   * 
   */
  Color fill_color;
  /**
   * @brief Image quality [0, 100]
   * 
   */
  int32_t image_quality;
  /**
   * @brief Line thickness.
   * 
   */
  int32_t line_thickness;
};

/**
 * @brief Compares two DrawProperties object for equality.
 * 
 */
inline bool operator==(const DrawProperties& lhs, const DrawProperties& rhs) {
  return lhs.border_color == rhs.border_color && lhs.fill_color == rhs.fill_color &&
         lhs.image_quality == rhs.image_quality;
}

}  // namespace naval
