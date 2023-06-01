#include <cassert>
#include <string_view> // string_view requires C++17 (either defined in CMakeLists.txt, or in Visual Studio, /Project properties -> Configuration properties->C / C++->Language->C++ Language standard / and select "ISO C++ 17 Standard"
#include <sstream>
#include "Group.h"
#include "Circle.h"

using namespace std;

void load_children(std::vector<std::unique_ptr<Shape>> &children, const pugi::xml_node& node) {
    for (auto child : node.children())
    {
        assert((child.name() == "Circle"sv) || (child.name() == "Group"sv)); // "Circle"sv" equivalent to std::string_view{ "Circle" } thanks to : using namespace std::literals;
        if (child.name() == "Circle"sv)
            children.push_back(std::make_unique<Circle>(child));
        else // child.name() == "Group"sv
            children.push_back(std::make_unique<Group>(child));
    }
}

Group::Group(const pugi::xml_node& node)
	: Shape{ node }
{
    load_children(children, node);
}

Group::Group(std::string const& label, double x, double y)
        : Shape{ label, x, y }
{
}

std::unique_ptr<Shape> Group::clone()
{
    auto g = std::make_unique<Group>(get_label(), get_x(), get_y());
    for (auto const& child : children)
    {
        children.emplace_back(child->clone());
    }
    return std::move(g);
}

std::string Group::dump(std::string const& indent) const
{
	ostringstream oss;
	oss << indent
        << "Group " << Shape::dump(indent)
        << "children: [" << endl;
    for (auto const& c : children) {
        oss << c->dump(indent + "| ");
    }
    oss << indent << "]" << endl;
    return oss.str();
}

void Group::draw(SFML_output & out, double x_origin, double y_origin) const
{
        for (auto const &child : children)
        {
                child->draw(out, x_origin + get_x(), y_origin + get_y());
        }
}

void Group::populate(std::map<std::string, Shape*, std::less<>> &string2shape)
{
    Shape::populate(string2shape);
    for (auto const& c : children) {
        c->populate(string2shape);
    }
}

void Group::set_color(std::string const& aColor)
{
    for (auto const&child : children)
    {
        child->set_color(aColor);
    }
}

