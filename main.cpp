#include "ConsoleScreen.h"
#include "GlScreen.h"
#include <FigureCollection.h>

int main() {
	using namespace Figures;
	ConsoleScreen console_scr;
	FigureCollection<ConsoleScreen> fc_console;
	fc_console.addFigure("Some text figure\n");
	fc_console.addFigure(5);
	fc_console.addFigure(Rectangle{});
	fc_console.addFigure(Triangle{});
	for (const auto& fig : fc_console) {
		draw(fig, console_scr);
	}
	console_scr.render();

	GlScreen gl_scr;
	FigureCollection<GlScreen> fc;
	fc.addFigure(Square{ {-0.8f,-0.8f}, 0.1f });
	fc.addFigure(Triangle{ { 0.8f, 0.8f }, { 0.75f, 0.0f }, { 0.9f, -0.2f } });
	fc.addFigure(Pentagon{ { -0.2f, -0.2f }, { -0.3f, 0.1f }, { 0.0f, 0.3f }, {0.3f, 0.1f}, {0.2f, -0.2f} });
	fc.addFigure(Rectangle{ { -0.1f, 0.8f }, { 0.1f, 0.6f } });
	fc.addFigure(Circle({ -0.78f, 0.78f }, 0.2f));
	for (const auto& fig : fc) {
		draw(fig, gl_scr);
	}
	gl_scr.render();
	gl_scr.exec();
	return 0;
}