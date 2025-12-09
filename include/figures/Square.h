#pragma once
#include <Vector2D.h>
#include <array>

namespace Figures {
	struct Square final {
		std::array<Vector2D, 4> vert_{};
		constexpr Square() noexcept = default;
		constexpr Square(Vector2D top_left, float side) {
			vert_.at(0) = top_left;
			vert_.at(1) = Vector2D{ top_left.x + side, top_left.y };
			vert_.at(2) = Vector2D{ top_left.x + side, top_left.y - side };
			vert_.at(3) = Vector2D{ top_left.x, top_left.y - side };
		}
	};
}