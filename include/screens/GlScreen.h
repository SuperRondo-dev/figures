#pragma once
#include <memory>
#include <vector>
#include <array>
#include <Figures.h>


namespace Figures {
	class GlScreen{
		struct triplet {
			std::array<float, 3> buf_{};
			[[nodiscard]] constexpr const float* ptr() const noexcept { return buf_.data(); }
		};
		static constexpr int default_w = 640, default_h = 480;
		std::unique_ptr<void, void(*)(void*)> handle_{ nullptr, +[](void*) {} };
		std::vector<std::vector<triplet>> figures_{};
	public:
		GlScreen() : GlScreen(default_w, default_h) {}
		GlScreen(int w, int h);
		void add(const Polygon2D& v);
		template<size_t SZ>
		void add(const std::array<Vector2D, SZ> arr);
		void render();
		void exec();
	};
	template<size_t SZ>
	inline void GlScreen::add(const std::array<Vector2D, SZ> arr) {
		std::vector<triplet> vec;
		vec.reserve(SZ);
		for (auto i = 0; i < SZ; ++i) {
			vec.push_back({ arr.at(i).x, arr.at(i).y, 0.0f});
		}
		figures_.push_back(std::move(vec));
	}

	inline void draw(const Polygon2D& x, GlScreen& screen) { screen.add(x); }
	inline void draw(const Circle& x, GlScreen& screen) { draw(x.vert_, screen); }
	inline void draw(const Pentagon& x, GlScreen& screen) { screen.add(x.vert_); }
	inline void draw(const Rectangle& x, GlScreen& screen) { screen.add(x.vert_); }
	inline void draw(const Square& x, GlScreen& screen) { screen.add(x.vert_); }
	inline void draw(const Triangle& x, GlScreen& screen) { screen.add(x.vert_); }	
}