#include <numbers>
#include "box.hpp"

Box::Box(std::string const& name, glm::vec3 const& color, glm::vec3 const& min, glm::vec3 const& max):
	Shape(name, color),
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


std::ostream& Box::print(std::ostream& os) const {
	return Shape::print(os) << "Min: x(" << min_.x << ") y(" << min_.y << " z(" << min_.z << ") \nMax: x(" << max_.x << ") y(" << max_.y << " z(" << max_.z << ") \n";
}