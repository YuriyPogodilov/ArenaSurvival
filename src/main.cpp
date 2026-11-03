#include "raylib.h"

int main() {
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Arena Survival");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawTriangle(
			{ screenWidth * 0.33f, screenHeight * 0.66f },
			{ screenWidth * 0.66f, screenHeight * 0.66f },
			{ screenWidth * 0.5f, screenHeight * 0.33f },
			GREEN
		);

		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}
