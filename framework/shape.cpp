#include "shape.hpp"

Shape::Shape(std::string const& name, glm::vec3 const& color):
	name_(name),
	color_(color){

}

std::ostream& Shape::print(std::ostream& os) const {
	return os << name_ << "\nFarbe: r(" << color_.r << ") g(" << color_.g << ") b(" << color_.b << ") \n";
}

std::ostream& operator<<(std::ostream& os, Shape const& s) {
	return s.print(os);
}