#pragma once
#include <string>
#include "pugixml.hpp"
#include "SFML_output.h"

class Shape
{
public:
	explicit Shape(const pugi::xml_node& node);
    Shape(std::string_view label, double x, double y);
	virtual ~Shape() = default;
    virtual std::unique_ptr<Shape> clone() = 0;
    virtual void draw(SFML_output & out, double x_origin, double y_origin) const =0;
    [[nodiscard]] virtual std::string dump(std::string const& indent) const; // We cannot have a default argument anymore (otherwise "Clang-Tidy: Default arguments on virtual or override methods are prohibited")
    [[nodiscard]] std::string get_label() const;
    [[nodiscard]] double get_x() const;
    [[nodiscard]] double get_y() const;
    virtual void populate(std::map<std::string, Shape*, std::less<>> &string2shape);
    void set_label(std::string_view aLabel);
    virtual void set_color(std::string const& aColor) = 0;
    void translation(int delta_x, int delta_y);
private:
	std::string label;
    double x;
    double y;
};

