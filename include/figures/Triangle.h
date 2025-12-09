#pragma once
#include <Vector2D.h>
#include <array>

namespace Figures {
	struct Triangle final {
		std::array<Vector2D, 3> vert_{};
		constexpr Triangle() noexcept = default;
		constexpr Triangle(Vector2D p1, Vector2D p2, Vector2D p3)	: vert_{p1,p2,p3} {}
	};
}