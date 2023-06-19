#ifndef SHPERE_HPP
#define SHEPRE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include "ray.hpp"
#include "hitpoint.hpp"

class Sphere : public Shape {
public:
	Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float radius);

	float area() const override;
	float volume() const override;

	std::ostream& print(std::ostream& os) const override;

	HitPoint intersect(Ray const& ray) const;

private:
	glm::vec3 center_;
	float radius_;

};

#endif