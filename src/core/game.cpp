#include "game.h"

#include <raylib.h>
#include <entt/entt.hpp>

#include "movementSystem.h"

Game::Game(int screenWidth, int screenHeight)
    : gameScreenWidth(screenWidth), gameScreenHeight(screenHeight) {}

void Game::Initialize() {
	InitWindow(gameScreenWidth, gameScreenHeight, "Arena Survival");
	SetTargetFPS(60);
}

void Game::Start() {
	MovementSystem movementSystem;

	auto player = enttRegistry.create();

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		movementSystem.update(enttRegistry);

		EndDrawing();
	}

	CloseWindow();
}