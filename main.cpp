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

struct Paddle
{
	float x, y;
	float speed;
	float width, height;

	void Draw()
	{
		DrawRectangle((int) x -  width / 2, (int) y - height / 2, width, height, entityColor);
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

	Paddle leftPaddle;
	leftPaddle.x = 50;
	leftPaddle.y = GetScreenHeight() / 2;
	leftPaddle.width = 10;
	leftPaddle.height = 100;
	leftPaddle.speed = 500;

	Paddle rightPaddle;
	rightPaddle.x = GetScreenWidth() - 50;
	rightPaddle.y = GetScreenHeight() / 2;
	rightPaddle.width = 10;
	rightPaddle.height = 100;
	rightPaddle.speed = 500;

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
			leftPaddle.Draw();
			rightPaddle.Draw();
			DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}