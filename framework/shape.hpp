#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <glm/vec3.hpp>
#include <string>
#include <iostream>
#include "color.hpp"

class Shape {
public:
	Shape(std::string const& name, Color const& color);

	std::string get_name() const;
	Color get_color() const;

	virtual float area() const = 0;
	virtual float volume() const = 0;

	virtual std::ostream& print(std::ostream& os) const;

private:
	std::string name_;
	Color color_;

};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif