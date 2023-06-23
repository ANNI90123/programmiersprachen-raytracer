#include <cmath>
#include <numbers>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "sphere.hpp"

Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float radius):
	Shape{ name, color },
	center_{ center },
	radius_{ radius } {
	if (radius_ < 0.0f) {
		radius_ = -radius_;
	}
	std::cout << "Sphere constructor\n";

}

Sphere::~Sphere() {
	std::cout << "Sphere destructor\n";
}

float Sphere::area() const {
	return 4 * std::numbers::pi * radius_ * radius_;
}

float Sphere::volume() const {
	return (4.0f / 3.0f) * std::numbers::pi * radius_ * radius_ * radius_;
}


std::ostream& Sphere::print(std::ostream& os) const{
	return Shape::print(os) << "Center: x(" << center_.x << ") y(" << center_.y << ") z(" << center_.z << ") \nRadius: " << radius_ << "\n";
}


HitPoint Sphere::intersect(Ray const& ray) const {

	float distance = 0.0f;
	float norm_direction = sqrt(ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y + ray.direction.z * ray.direction.z);
	glm::vec3 direction{ray.direction.x /norm_direction, ray.direction.y / norm_direction, ray.direction.z / norm_direction};
	bool intersection = glm::intersectRaySphere(ray.origin, direction, center_, radius_ * radius_, distance);
	glm::vec3 intersection_point = ray.origin + distance * direction;

	
	if (intersection) {
		return HitPoint{intersection, distance, Shape::get_name(), Shape::get_color(), intersection_point, direction};
	}
	else {
		return HitPoint{ intersection, INFINITY, Shape::get_name(), Shape::get_color(), glm::vec3{INFINITY, INFINITY, INFINITY}, direction };
	}
	

}