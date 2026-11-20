#pragma once

#include <entt/entt.hpp>

class Game {
public:
	Game(int screenWidth, int screenHeight);
	~Game() = default;

	void Initialize();
	void Start();

	entt::registry& getEnttRegistry() { return enttRegistry; }

private:
	int gameScreenWidth;
	int gameScreenHeight;

	entt::registry enttRegistry;
};