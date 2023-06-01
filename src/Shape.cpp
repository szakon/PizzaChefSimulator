#include <sstream>
#include "Shape.h"

using namespace std;

Shape::Shape(const pugi::xml_node& node)
	: label{ node.attribute("label").as_string() }
	, x{ node.attribute("x").as_double() }
	, y{ node.attribute("y").as_double() }
{
}

Shape::Shape(std::string_view label, double x, double y)
        : label{ label }
        , x{ x }
        , y{ y }
{
}

std::string Shape::dump(std::string const& indent) const
{
	ostringstream oss;
	oss << "\"" << label << "\", "
		<< "x: " << x << ", "
		<< "y: " << y << ", ";
	return oss.str();
}

std::string Shape::get_label() const
{
    return label;
}

double Shape::get_x() const
{
    return x;
}

double Shape::get_y() const
{
    return y;
}

void Shape::populate(std::map<std::string, Shape*, std::less<>> &string2shape)
{
   string2shape[label] = this;
}

void Shape::set_label(std::string_view aLabel)
{
    label = aLabel;
}

void Shape::translation(int delta_x, int delta_y)
{
    x += delta_x;
    y += delta_y;
}