#pragma once
#include <memory>
#include <vector>
#include "Shape.h"

void load_children(std::vector<std::unique_ptr<Shape>> &children, const pugi::xml_node& node);

class Group :
    public Shape {
public:
    explicit Group(const pugi::xml_node& node);
    Group(std::string const& label, double x, double y);
    std::unique_ptr<Shape> clone() override;
    [[nodiscard]] std::string dump(std::string const& indent) const override;
    void draw(SFML_output & out, double x_origin, double y_origin) const override;
    void populate(std::map<std::string, Shape*, std::less<>> &string2shape) override;
    void set_color(std::string const& aColor) override;
private:
    std::vector<std::unique_ptr<Shape>> children;
};
