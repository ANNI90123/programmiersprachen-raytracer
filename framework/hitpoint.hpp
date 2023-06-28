#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <string>
#include <glm/vec3.hpp>
#include "color.hpp"

struct HitPoint {

	bool intersection = false;
	float distance = 0.0f;
	std::string name = "no name";
	Color color = Color{0.0f, 0.0f, 0.0f};
	glm::vec3 intersection_point = {0.0f, 0.0f,0.0f};
	glm::vec3 direction = { 0.0f, 0.0f,0.0f };
};

#endif
