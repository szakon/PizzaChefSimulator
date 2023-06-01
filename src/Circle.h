#pragma once
#include "Shape.h"

class Circle :
    public Shape {
public:
    explicit Circle(const pugi::xml_node& node);
    Circle(std::string const& label, double x, double y, double r, std::string const& color);
    std::unique_ptr<Shape> clone() override;
    [[nodiscard]] std::string dump(std::string const& indent) const override;
    void draw(SFML_output & out, double x_origin, double y_origin) const override;
    void set_color(std::string const& aColor) override;
private:
    double r;
    std::string color;
};
