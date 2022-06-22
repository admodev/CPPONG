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
			DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}