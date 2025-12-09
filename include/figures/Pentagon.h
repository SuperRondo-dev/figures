#pragma once
#include <Vector2D.h>
#include <array>

namespace Figures {
	struct Pentagon final {
		std::array<Vector2D, 5> vert_{};
		constexpr Pentagon() noexcept = default;
		constexpr Pentagon(Vector2D p1, Vector2D p2, Vector2D p3, Vector2D p4, Vector2D p5) : vert_{ p1, p2, p3, p4, p5 } {}
	};
}