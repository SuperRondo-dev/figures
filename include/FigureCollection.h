#pragma once
#include <vector>
#include <Drawable.h>

namespace Figures {
	template<typename ScreenType>
	struct FigureCollection final : public std::vector<Drawable<ScreenType>> {
		using std::vector<Drawable<ScreenType>>::vector;
		template<typename T>
		void addFigure(T&& t) { push_back(Drawable<ScreenType>(std::forward<T>(t))); }
	};
}