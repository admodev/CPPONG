#include "raylib.h"

int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Pong!");
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
			DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 5, WHITE);
			DrawRectangle(50, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
			DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
			DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}