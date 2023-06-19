#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <string>
#include <glm/vec3.hpp>
#include "color.hpp"

struct HitPoint {

	bool intersection;
	float distance;
	std::string name;
	Color color;
	glm::vec3 intersection_point;
	glm::vec3 direction;
};

#endif
