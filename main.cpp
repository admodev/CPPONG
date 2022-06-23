#include "raylib.h"

int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	const Color screenBackgroundColor = BLACK;
	const Color entityColor = WHITE;

	InitWindow(screenWidth, screenHeight, "Pong!");
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);

	float ballX = GetScreenWidth() / 2.0f;
	float ballY = GetScreenHeight() / 2.0f;
	float ballRadius = 5;

	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(screenBackgroundColor);
			DrawCircle((int) ballX, (int) ballY, ballRadius, entityColor);
			DrawRectangle(50, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
			DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
			DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}