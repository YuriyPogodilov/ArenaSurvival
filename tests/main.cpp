#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <entt/entt.hpp>

#include "core/core.h"

TEST_CASE("Entities retain position and velocity components") {
	entt::registry registry;
	const auto entity = registry.create();
	registry.emplace<Position>(entity, 10.0f, 20.0f);
	registry.emplace<Velocity>(entity, 1.0f, -2.0f);

	CHECK(registry.get<Position>(entity).x == doctest::Approx(10.0f));
	CHECK(registry.get<Position>(entity).y == doctest::Approx(20.0f));
	CHECK(registry.get<Velocity>(entity).dx == doctest::Approx(1.0f));
	CHECK(registry.get<Velocity>(entity).dy == doctest::Approx(-2.0f));
}
