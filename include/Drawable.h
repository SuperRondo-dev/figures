#pragma once
#include <memory>

namespace Figures {
	template <typename ScreenType>
	class Drawable final
	{
		struct IDrawable {
			virtual ~IDrawable() = default;
			[[nodiscard]] virtual std::unique_ptr<IDrawable> clone_() const = 0;
			virtual void draw_(ScreenType&) const = 0;
		};
		template <typename T> struct DrawableObject final : IDrawable {
			T data_;
			DrawableObject(T&& x) : data_(std::move(x)) {}
			[[nodiscard]] std::unique_ptr<IDrawable> clone_() const override {
				return std::make_unique<DrawableObject>(*this);
			}
			void draw_(ScreenType& screen) const override {
				Figures::draw(data_, screen);
			}
		};
	private:
		std::unique_ptr<IDrawable> ptr_;
	public:
		template <typename T>
		Drawable(T x) : ptr_(std::make_unique<DrawableObject<T>>(std::move(x))) {}
		Drawable(const Drawable& x) : ptr_(x.ptr_->clone_()) {}
		Drawable(Drawable&& x) noexcept = default;
		Drawable& operator=(Drawable x) noexcept {
			ptr_ = std::move(x.ptr_);
			return *this;
		}
	public:
		friend void draw(const Drawable& x, ScreenType& screen) {
			x.ptr_->draw_(screen);
		}
	};
}