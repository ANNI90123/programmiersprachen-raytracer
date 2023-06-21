#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include <numbers>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>




TEST_CASE("returns the surface area of a sphere", "[area()]") {

	Sphere s1{ "s1", Color{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, 4.0f };
	Sphere s2{ "s2", Color{0.0f, 0.0f, 0.0f},glm::vec3{-20.0f, 20.0f, 20.0f}, 5.3f };
	Sphere s3{ "s3", Color{0.0f, 0.0f, 0.0f}, glm::vec3{-5.0f, -5.0f, -5.0f}, 0.0f };
	
	REQUIRE(s1.area() == Approx(201.0619f));
	REQUIRE(s2.area() == Approx(352.9893f));
	REQUIRE(s3.area() == Approx(0.0f));

}

TEST_CASE("returns the volume of a sphere", "[volume()]") {

	Sphere s1{ "s1", Color{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, 4.0f };
	Sphere s2{ "s2", Color{0.0f, 0.0f, 0.0f},glm::vec3{-20.0f, 20.0f, 20.0f}, 5.3f };
	Sphere s3{ "s3", Color{0.0f, 0.0f, 0.0f}, glm::vec3{-5.0f, -5.0f, -5.0f}, 0.0f };

	REQUIRE(s1.volume() == Approx(268.083f));
	REQUIRE(s2.volume() == Approx(623.615f));
	REQUIRE(s3.volume() == Approx(0.0f));

}

TEST_CASE("returns the surface area of a box", "[area()]") {

	Box b1{ "b1", Color{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, glm::vec3{7.0f, 8.0f, 6.0f} };
	Box b2{ "b2", Color{0.0f, 0.0f, 0.0f}, glm::vec3{-5.0f, -5.0f, -5.0f}, glm::vec3{-3.0f, -2.0f, -1.0f} };
	Box b3{ "b3", Color{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, glm::vec3{5.0f, 5.0f, 5.0f} };

	REQUIRE(b1.area() == Approx(22.0f));
	REQUIRE(b2.area() == Approx(52.0f));
	REQUIRE(b3.area() == Approx(0.0f));

}

TEST_CASE("returns the volume of a box", "[volume()]") {

	Box b1{ "b1", Color{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, glm::vec3{7.0f, 8.0f, 6.0f} };
	Box b2{ "b2", Color{0.0f, 0.0f, 0.0f}, glm::vec3{-5.0f, -5.0f, -5.0f}, glm::vec3{-3.0f, -2.0f, -1.0f} };
	Box b3{ "b3", Color{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, glm::vec3{5.0f, 5.0f, 5.0f} };

	REQUIRE(b1.volume() == Approx(6.0f));
	REQUIRE(b2.volume() == Approx(24.0f));
	REQUIRE(b3.volume() == Approx(0.0f));

}

TEST_CASE("prints out a shape, sphere or box", "[print(std::ostream&)]") {

	Sphere s{ "sphere", Color{1.0f, 1.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, 4.0f };
	Box b{ "box", Color{0.0f, 1.0f, 1.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, glm::vec3{7.0f, 8.0f, 6.0f} };

	std::cout << s << b;

}


TEST_CASE("intersect_ray_sphere", "[intersect]") {

	glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};

	glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};

	glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
	float sphere_radius{1.0f};

	float distance = 0.0f;
	auto result = glm::intersectRaySphere(ray_origin, ray_direction, sphere_center, sphere_radius * sphere_radius, distance);
	REQUIRE(distance == Approx(4.0f));

}

TEST_CASE("calculates the hitpoint of an intersection between a ray and a sphere", "[intersect]") {

	Sphere s1{ "s1", Color{1.0f, 1.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, 4.0f };
	HitPoint hp1 =  s1.intersect(Ray{ glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{1.0f, 1.0f, 1.0f} });

	Sphere s2{ "s2", Color{1.0f, 1.0f, 0.0f}, glm::vec3{2.0f, 5.0f, 3.0f}, 0.0f };
	HitPoint hp2 = s2.intersect(Ray{ glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{1.0f, 1.0f, 1.0f} });

	Sphere s3{ "s3", Color{1.0f, 1.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, 2.0f };
	HitPoint hp3 = s3.intersect(Ray{ glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{1.0f, 1.0f, .0f} });

	Sphere s4{ "s4", Color{1.0f, 1.0f, 0.0f}, glm::vec3{-5.0f, 0.0f, 0.0f}, 3.0f };
	HitPoint hp4 = s4.intersect(Ray{ glm::vec3{-3.0f, 0.0f, 0.0f}, glm::vec3{-1.0f, 0.0f, 0.0f} });

	REQUIRE(hp1.intersection == true);
	REQUIRE(hp1.distance == Approx(std::sqrt(75) - 4.0f));
	REQUIRE(hp1.name == "s1");

	REQUIRE(hp2.intersection == false);
	REQUIRE(hp2.distance == INFINITY);
	REQUIRE(hp2.intersection_point.x == INFINITY);
	REQUIRE(hp2.intersection_point.y == INFINITY);
	REQUIRE(hp2.intersection_point.z == INFINITY);

	REQUIRE(hp3.intersection == false);
	REQUIRE(hp3.distance == INFINITY);

	REQUIRE(hp4.intersection == true);
	REQUIRE(hp4.distance == Approx(5.0f));
	REQUIRE(hp4.name == "s4");
	REQUIRE(hp4.intersection_point.x == Approx(- 8.0f));
	REQUIRE(hp4.intersection_point.y == Approx(0.0f));
	REQUIRE(hp4.intersection_point.z == Approx(0.0f));
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
