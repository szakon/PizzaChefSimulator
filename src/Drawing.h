#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "Shape.h"

class Drawing
{
public:
    explicit Drawing(pugi::xml_node node);
    void add(std::unique_ptr<Shape> shape);
    [[nodiscard]] std::string dump(std::string const& indent) const;
    void draw(SFML_output & out) const;
    void populate(std::map<std::string, Shape*, std::less<>> &string2shape) const;
private:
    std::vector<std::unique_ptr<Shape>> children;
};

