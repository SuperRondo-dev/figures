#pragma once
#include <Vector2D.h>
#include <array>

namespace Figures {
	struct Rectangle final {
		std::array<Vector2D, 4> vert_{};
		constexpr Rectangle() noexcept = default;
		constexpr Rectangle(Vector2D top_left, Vector2D bottom_right) {
			vert_.at(0) = top_left;
			vert_.at(1) = Vector2D{ bottom_right.x, top_left.y };
			vert_.at(2) = bottom_right;
			vert_.at(3) = Vector2D{ top_left.x, bottom_right.y };
		}
	};
}