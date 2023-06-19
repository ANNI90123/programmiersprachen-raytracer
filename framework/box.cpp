#include <numbers>
#include "box.hpp"

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
	min_(min),
	max_(max){
	if (!(max_.x > min_.x && max_.y > min_.y && max_.z > min_.z)) {
		throw "Diese Vectoren spannen keine Box ein";
	}
}

float Box::area() const {
	float side_1 = (max_.x - min_.x) * (max_.y - min_.y);
	float side_2 = (max_.x - min_.x) * (max_.z - min_.z);
	float side_3 = (max_.y - min_.y) * (max_.z - min_.z);
	return 2 * (side_1 + side_2 + side_3);
}

float Box::volume() const{
	return (max_.x - min_.x) * (max_.y - min_.y) * (max_.z - min_.z);
}