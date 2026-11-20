#include "movementSystem.h"

#include <entt/entt.hpp>
#include "core.h"

void MovementSystem::update(entt::registry& enttRegistry) {
	auto view = enttRegistry.view<Position, Velocity>();

	for (auto [entity, pos, vel] : view.each()) {
	}
}