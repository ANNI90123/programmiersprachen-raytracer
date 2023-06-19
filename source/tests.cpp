#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include <numbers>




TEST_CASE("returns the surface area of a sphere", "[area()]") {

	Sphere s1{ "s1", glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, 4.0f };
	Sphere s2{ "s2", glm::vec3{0.0f, 0.0f, 0.0f},glm::vec3{-20.0f, 20.0f, 20.0f}, 5.3f };
	Sphere s3{ "s3", glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{-5.0f, -5.0f, -5.0f}, 0.0f };
	
	REQUIRE(s1.area() == Approx(201.0619f));
	REQUIRE(s2.area() == Approx(352.9893f));
	REQUIRE(s3.area() == Approx(0.0f));

}

TEST_CASE("returns the volume of a sphere", "[volume()]") {

	Sphere s1{ "s1", glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, 4.0f };
	Sphere s2{ "s2", glm::vec3{0.0f, 0.0f, 0.0f},glm::vec3{-20.0f, 20.0f, 20.0f}, 5.3f };
	Sphere s3{ "s3", glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{-5.0f, -5.0f, -5.0f}, 0.0f };

	REQUIRE(s1.volume() == Approx(268.083f));
	REQUIRE(s2.volume() == Approx(623.615f));
	REQUIRE(s3.volume() == Approx(0.0f));

}

TEST_CASE("returns the surface area of a box", "[area()]") {

	Box b1{ "b1", glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, glm::vec3{7.0f, 8.0f, 6.0f} };
	Box b2{ "b2", glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{-5.0f, -5.0f, -5.0f}, glm::vec3{-3.0f, -2.0f, -1.0f} };
	Box b3{ "b3", glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, glm::vec3{5.0f, 5.0f, 5.0f} };

	REQUIRE(b1.area() == Approx(22.0f));
	REQUIRE(b2.area() == Approx(52.0f));
	REQUIRE(b3.area() == Approx(0.0f));

}

TEST_CASE("returns the volume of a box", "[volume()]") {

	Box b1{ "b1", glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, glm::vec3{7.0f, 8.0f, 6.0f} };
	Box b2{ "b2", glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{-5.0f, -5.0f, -5.0f}, glm::vec3{-3.0f, -2.0f, -1.0f} };
	Box b3{ "b3", glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, glm::vec3{5.0f, 5.0f, 5.0f} };

	REQUIRE(b1.volume() == Approx(6.0f));
	REQUIRE(b2.volume() == Approx(24.0f));
	REQUIRE(b3.volume() == Approx(0.0f));

}

TEST_CASE("prints out a shape, sphere or box", "[print(std::ostream&)]") {

	Sphere s{ "sphere", glm::vec3{1.0f, 1.0f, 0.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, 4.0f };
	Box b{ "box", glm::vec3{0.0f, 1.0f, 1.0f}, glm::vec3{5.0f, 5.0f, 5.0f}, glm::vec3{7.0f, 8.0f, 6.0f} };

	std::cout << s << b;

}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
