#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <glm/vec3.hpp>
#include <string>
#include <iostream>

class Shape {
public:
	Shape(std::string const& name, glm::vec3 const& color);

	virtual float area() const = 0;
	virtual float volume() const = 0;

	virtual std::ostream& print(std::ostream& os) const;

private:
	std::string name_;
	glm::vec3 color_;

};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif