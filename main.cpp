#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;
const Color screenBackgroundColor = BLACK;
const Color entityColor = WHITE;

struct Ball
{
	float x, y;
	float speedX, speedY;
	float radius;

	void Draw()
	{
		DrawCircle((int) x, (int) y, radius, entityColor);
	}
};

int main(void)
{
	InitWindow(screenWidth, screenHeight, "Pong!");
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);

	Ball ball;
	ball.x = GetScreenWidth() / 2.0f;
	ball.y = GetScreenHeight() / 2.0f;
	ball.radius= 5;
	ball.speedX = 100;
	ball.speedY = 300;

	while (!WindowShouldClose())
	{
		ball.x += ball.speedX * GetFrameTime();
		ball.y += ball.speedY * GetFrameTime();

		if (ball.y < 0)
		{
			ball.y = 0;
			ball.speedY *= -1;
		}

		if (ball.y > GetScreenHeight())
		{
			ball.y = GetScreenHeight();
			ball.speedY *= -1;
		}

		BeginDrawing();
			ClearBackground(screenBackgroundColor);
			ball.Draw();
			DrawRectangle(50, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
			DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
			DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}