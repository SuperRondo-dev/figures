#pragma once
#include <iostream>
#include <sstream>
#include <string_view>
#include <array>
#include <Figures.h>
#include <utility>

namespace Figures {
	class ConsoleScreen final {
		std::stringstream buf_;
	public:
		template<typename T>
		void add(T&& v) { buf_ << std::forward<T>(v); }
		void render() { std::cout << buf_.str() << "\n"; }
	};
	
	namespace {
		[[nodiscard]] inline constexpr std::string_view get_rect_row(int row_idx) noexcept {
			return (row_idx < 2 || row_idx > 8) ? "          " : "  ******  ";
		}
	}

	template<typename T>
	void draw(T&& t, ConsoleScreen& scr) {
		scr.add(std::forward<T>(t));
	}	
	void draw(const Rectangle& rect, ConsoleScreen& scr) {
		for (int i = 0; i < 10; ++i) {
			scr.add(get_rect_row(i));
			scr.add('\n');
		}
	}
	void draw(const Triangle& rect, ConsoleScreen& scr) {
		std::array<char, 11> arr_{};
		arr_.fill(' ');
		arr_.at(10) = '\0';
		for (int i = 0; i < 10; ++i) {
			arr_.at(i) = '*';
			scr.add(arr_.data());
			scr.add('\n');
		}
	}
}