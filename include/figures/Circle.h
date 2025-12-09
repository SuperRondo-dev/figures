#pragma once
#include <Polygon2D.h>
#include <cmath>

namespace Figures {
	struct Circle final {
		Polygon2D vert_{};
		Circle() noexcept = default;
		Circle(Vector2D center, float radius) {
            static constexpr unsigned int number_of_segments = 360;
            static constexpr float pi = 3.14159f;
            static constexpr float angle = pi * 2 / number_of_segments;
            float vert_offset = std::tanf(angle);
            float hor_offset = std::cosf(angle);
            vert_.reserve(number_of_segments);
            auto get_point = [center, radius](unsigned int segment) -> Vector2D {
                return { center.x + radius * std::cosf(pi * 2 / number_of_segments * segment),
                    center.y + radius * std::sinf(pi * 2 / number_of_segments * segment) };
                };
            for (auto i = 0; i < number_of_segments; ++i) {
                vert_.push_back(get_point(i));
            }
		}
	};
}