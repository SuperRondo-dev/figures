#include <GlScreen.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

using namespace Figures;

namespace {
	void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}
	GLFWwindow* init(int w, int h) {
        GLFWwindow* Window;
		auto res = glfwInit();
		if (res != GLFW_TRUE) { throw std::runtime_error("Couldn't initialize GLFW"); }
        Window = glfwCreateWindow(w, h, "Figures", nullptr, nullptr);
		if (!Window) { throw std::runtime_error("Couldn't create glfwWindow"); }
        glfwMakeContextCurrent(Window);
        glfwSetFramebufferSizeCallback(Window, framebuffer_size_callback);
        glfwSwapInterval(1);
        return Window;
	}
}

GlScreen::GlScreen(int w, int h) {
	handle_ = { init(w,h), [](void* ptr) { glfwTerminate(); } };
}
void GlScreen::add(const Polygon2D& v) {
	std::vector<triplet> vec;
	vec.reserve(v.size());
	for (auto p : v) { vec.push_back({ p.x, p.y, 0.0f }); }
	figures_.push_back(std::move(vec));
}
void GlScreen::render() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	for (const auto& fig : figures_) {
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		for (auto v : fig) {
			glVertex3fv(v.ptr());
		}
		glEnd();
	}
}
void GlScreen::exec() {
	GLFWwindow* ptr = static_cast<GLFWwindow*>(handle_.get());
	bool b = true;
	while (!glfwWindowShouldClose(ptr)) {
		render();
		glfwSwapBuffers(ptr);
		glfwPollEvents();
	}
}
