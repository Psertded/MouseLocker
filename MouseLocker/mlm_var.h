#pragma once

#include <graphics.h>
#include <Windows.h>
#include <vector>

std::vector<POINT> dels;

int screen_x, screen_y, MaxRenderSize;
bool fullscreen = false, batch = true, drawing = false, erasing = false;
int ballRadius = 8;
POINT Total;
POINT mouse, current_ball, move;
ExMessage msg;	
clock_t start = 0, end = 0;