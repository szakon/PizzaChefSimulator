#include <sstream>
#include "Drawing.h"


using namespace std;
/*
Drawing::Drawing(pugi::xml_node node)
{
    load_children(children, node);
}

void Drawing::add(std::unique_ptr<Shape> shape)
{
    children.push_back(std::move(shape));
}

void Drawing::draw(SFML_output & out) const
{
    for (auto const& c : children) {
        c->draw(out, 0, 0);
    }
}

std::string Drawing::dump(std::string const& indent) const
{
    ostringstream oss;
    oss << indent << "Drawing [" << endl;
    for (auto const& c : children) {
        oss << c->dump(indent + "| ");
    }
    oss << indent << "]" << endl;
    return oss.str();
}

void Drawing::populate(std::map<std::string, Shape*, std::less<>> &string2shape) const
{
    for (auto const& c : children) {
        c->populate(string2shape);
    }
}

*/