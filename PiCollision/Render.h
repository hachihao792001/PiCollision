#pragma once
#include "Physics.h"
#include <Windows.h>

#define WIDTH 960
#define HEIGHT 600
#define WALL_THICCNESS 3
#define CELL_SIZE 40
#define ENTITY_SIZE 30
#define RENDER_OFFSET 70
const COLORREF BLACK = RGB(0, 0, 0);
const COLORREF WHITE = RGB(255, 255, 255);

void DrawRectangle(MyRectangle rec, COLORREF color);

void ClearScreen();

void InitWindow();

void DrawCustomText(string messageStr, int x, int y);
