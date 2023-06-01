#include <sstream>
#include "Circle.h"

using namespace std;

Circle::Circle(const pugi::xml_node& node)
	: Shape{ node }
	, r{ node.attribute("r").as_double() }
	, color{ node.attribute("color").as_string() }
{
}

Circle::Circle(std::string const& label, double x, double y, double r, std::string const& color)
        : Shape{ label, x, y }
        , r{ r }
        , color{ color }
{
}

std::unique_ptr<Shape> Circle::clone()
{
    return std::make_unique<Circle>(get_label(), get_x(), get_y(), r, color);
}

std::string Circle::dump(std::string const& indent) const
{
	ostringstream oss;
	oss << indent
        << "Circle " << Shape::dump(indent)
		<< "r: " << r << ", "
		<< "color: " << "\"" << color << "\"" << endl;
	return oss.str();
}

void Circle::draw(SFML_output & out, double x_origin, double y_origin) const
{
        out.draw_circle(x_origin + get_x(), y_origin + get_y(), r, color);
}

void Circle::set_color(std::string const& aColor)
{
    color = aColor;
}
