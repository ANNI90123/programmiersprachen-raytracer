#include <numbers>
#include "sphere.hpp"

Sphere::Sphere(std::string const& name, glm::vec3 const& color, glm::vec3 const& center, float radius):
	Shape(name, color),
	center_(center),
	radius_(radius){
	if (radius_ < 0.0f) {
		throw "Der Radius muss eine positive Zahl sein";
	}

}

float Sphere::area() const {
	return 4 * std::numbers::pi * radius_ * radius_;
}

float Sphere::volume() const {
	return 4 / 3 * std::numbers::pi + radius_ * radius_ * radius_;
}