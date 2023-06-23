#include <iostream>
#include "shape.hpp"


Shape::Shape(std::string const& name, Color const& color):
	name_(name),
	color_(color){
	std::cout << "Shape constructor\n";
}

Shape::~Shape() {
	std::cout << "Shape destructor\n";
}

std::string Shape::get_name() const{
	return name_;
}

Color Shape::get_color() const {
	return color_;
}


std::ostream& Shape::print(std::ostream& os) const {
	return os << name_ << "\nFarbe: r(" << color_.r << ") g(" << color_.g << ") b(" << color_.b << ") \n";
}

std::ostream& operator<<(std::ostream& os, Shape const& s) {
	return s.print(os);
}