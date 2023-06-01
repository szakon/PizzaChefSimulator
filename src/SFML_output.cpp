#include <string>
#include <vector>
#include "SFML_output.h"

static const unsigned int WINDOW_WIDTH(1000);
static const unsigned int WINDOW_HEIGHT(700);

SFML_output::SFML_output()
	: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Outil visualisation")
{
	clean();
}

void SFML_output::draw_circle(double absolute_x, double absolute_y, double r, std::string const& color)
{
	sf::CircleShape shape(static_cast<float>(r));
	shape.setFillColor(string2color(color));
	shape.setPosition(static_cast<float>(absolute_x + WINDOW_WIDTH / 2 - r), static_cast<float>(WINDOW_HEIGHT / 2 - (absolute_y + r)));
	window.draw(shape);
}

void SFML_output::display()
{
	window.display();
}

bool SFML_output::check_user_closes_window() {
    if (!window.isOpen())
        return true;
    if (sf::Event event; window.pollEvent(event) && event.type == sf::Event::Closed) {
        window.close();
        return true;
    }
    // We sleep a little to save CPU
    sf::sleep(sf::milliseconds(100));
    return false;
}

void SFML_output::clean()
{
	window.clear();
	sf::RectangleShape shape(sf::Vector2f(static_cast<float>(WINDOW_WIDTH), static_cast<float>(WINDOW_HEIGHT)));
	shape.setPosition(sf::Vector2f(0, 0));
	shape.setFillColor(sf::Color::White);
	window.draw(shape);
}

sf::Color SFML_output::string2color(std::string const &s)
{
	const std::vector<std::string> colors_as_string = {
		"Black",
		"White",
		"Red",
		"Green",
		"Blue",
		"Yellow",
		"Magenta",
		"Cyan"
	};
	const std::vector<sf::Color> colors_as_sfml = {// Colors must be in the same order as in colors_as_string
	sf::Color::Black,
	sf::Color::White,
	sf::Color::Red,
	sf::Color::Green,
	sf::Color::Blue,
	sf::Color::Yellow,
	sf::Color::Magenta,
	sf::Color::Cyan
	};

	auto colorIndex = std::find(colors_as_string.begin(),colors_as_string.end(), s);
	return (colorIndex == colors_as_string.end()) ? colors_as_sfml[0] : colors_as_sfml[colorIndex - colors_as_string.begin()];
}
