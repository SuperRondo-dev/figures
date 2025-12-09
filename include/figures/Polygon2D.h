#pragma once
#include <vector>
#include "Vector2D.h"

namespace Figures {
	struct Polygon2D final : public std::vector<Vector2D> {
		using std::vector<Vector2D>::vector;
	};
}