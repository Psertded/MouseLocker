#pragma once
#define _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_SECURE_NO_WARNINGS


#include <graphics.h>
#include <stdio.h>
#include <time.h>
#include <vector>

#include "mlm_var.h"

POINT screenSize()
{
	return POINT{ screen_x,screen_y };
}
POINT Divide2(POINT p)
{
	return POINT{ p.x / 2,p.y / 2 };
}
POINT CalcMove(POINT p)
// Calculate the amount of movement
{
	POINT scr_dis = Divide2(screenSize());
	POINT result = { scr_dis.x - p.x,scr_dis.y - p.y };
	Total.x += abs(result.x);
	Total.y += abs(result.y);
	return result;
}
void DoMove(PPOINT pd, const POINT ps)
{
	pd->x -= ps.x;
	pd->y -= ps.y;
}
void BorderCheck(PPOINT pd)
{
	POINT scr_dis = screenSize();
	if (pd->x < 0)
	{
		pd->x = scr_dis.x;
	}
	if (pd->y < 0)
	{
		pd->y = scr_dis.y;
	}
	if (pd->x > scr_dis.x)
	{
		pd->x = 0;
	}
	if (pd->y > scr_dis.y)
	{
		pd->y = 0;
	}
}

void close()
{
	if (batch)
		EndBatchDraw();
	closegraph();
	dels.clear();
}