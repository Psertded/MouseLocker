#pragma once
#include "mlm_var.h"
#include <time.h>

void drawInfoText()
{
	wchar_t* ptr = new wchar_t[200];
	swprintf(ptr, L"FullX:% 5d", screen_x);
	outtextxy(0, MaxRenderSize * 2, ptr);//floor 5
	swprintf(ptr, L"FullY:% 5d", screen_y);
	outtextxy(0, MaxRenderSize * 3, ptr);//floor 5
	swprintf(ptr, L"TotalX:% 5d", Total.x);
	outtextxy(0, MaxRenderSize * 4, ptr);//floor 5
	swprintf(ptr, L"TotalY:% 5d", Total.y);
	outtextxy(0, MaxRenderSize * 5, ptr);//floor 6
	swprintf(ptr, L"Total:% 6d", Total.y + Total.x);
	outtextxy(0, MaxRenderSize * 6, ptr);//floor 7
	swprintf(ptr, L"NowX:% 5d", current_ball.x);
	outtextxy(0, MaxRenderSize * 7, ptr);//floor 8
	swprintf(ptr, L"NowY:% 5d", current_ball.y);
	outtextxy(0, MaxRenderSize * 8, ptr);//floor 9
	swprintf(ptr, L"MouseLeftButton:%d", msg.lbutton);
	outtextxy(0, MaxRenderSize * 9, ptr);//floor 10
	swprintf(ptr, L"MouseMiddleButton:%d", msg.mbutton);
	outtextxy(0, MaxRenderSize * 10, ptr);//floor 11
	swprintf(ptr, L"MouseRightButton:%d", msg.rbutton);
	outtextxy(0, MaxRenderSize * 11, ptr);//floor 12
	swprintf(ptr, L"MouseWheel:%d", msg.wheel);
	outtextxy(0, MaxRenderSize * 12, ptr);//floor 13
	swprintf(ptr, L"EraseDel:%d", erasing);
	outtextxy(0, MaxRenderSize * 13, ptr);//floor 14
	swprintf(ptr, L"Drawing:%d", drawing);
	outtextxy(0, MaxRenderSize * 14, ptr);//floor 15
	swprintf(ptr, L"DelsVectorSize:%lld", dels.size());
	outtextxy(0, MaxRenderSize * 15, ptr);//floor 16
	swprintf(ptr, L"LastDelX:%d", (dels.empty()) ? 0 : dels.back().x);
	outtextxy(0, MaxRenderSize * 16, ptr);//floor 17
	swprintf(ptr, L"LastDelY:%d", (dels.empty()) ? 0 : dels.back().y);
	outtextxy(0, MaxRenderSize * 17, ptr);//floor 18
	swprintf(ptr, L"Fullscreen:%d", (int)fullscreen);
	outtextxy(0, MaxRenderSize * 18, ptr);//floor 19
	swprintf(ptr, L"MaxTextHeight:%d", (int)MaxRenderSize);
	outtextxy(0, MaxRenderSize * 19, ptr);//floor 20
	swprintf(ptr, L"MovedX:%d", move.x);
	outtextxy(0, MaxRenderSize * 20, ptr);//floor 21
	swprintf(ptr, L"MovedY:%d", move.y);
	outtextxy(0, MaxRenderSize * 21, ptr);//floor 22
	swprintf(ptr, L"BallRadius:%d", ballRadius);
	outtextxy(0, MaxRenderSize * 22, ptr);//floor 23

	delete[] ptr;
}

void drawExitBox()
{
	//Rectangle
	COLORREF color = getlinecolor();
	setlinecolor(RGB(0, 0, 0));
	rectangle(screen_x - 20, 0, screen_x, 15);
	//  X  
	line(screen_x - 15, 3, screen_x - 5, 13);
	line(screen_x - 5, 3, screen_x - 15, 13);
	setlinecolor(color);
}

void drawBall(POINT point, int radius)
{
	COLORREF color = getlinecolor();
	if (!(radius - 2))
	{
		printf("Draw Ball : Radius Error.\n");
		return;
	}
	setlinecolor(RGB(128, 128, 128));
	circle(point.x, point.y, radius);
	setlinecolor(RGB(64, 64, 64));
	circle(point.x, point.y, radius - 2);

	putpixel(point.x, point.y, 0);

	setlinecolor(color);
}

void drawFPS(clock_t clock)//floor 1,2
{
	long double fps = 1000.0 / clock;
	wchar_t* ptr = new wchar_t[100];
	swprintf(ptr, L"FPS:%.2f", fps);
	outtextxy(0, 0, ptr);//floor 1
	swprintf(ptr, L"UpdateTime:% 2dms", clock);
	outtextxy(0, MaxRenderSize, ptr);//floor 2
	delete[] ptr;
}

void drawDel()
{
	for (int i = 0; i < dels.size(); i++)
	{
		putpixel(dels[i].x - 1, dels[i].y - 1, 0);
		putpixel(dels[i].x, dels[i].y - 1, 0);
		putpixel(dels[i].x + 1, dels[i].y - 1, 0);
		putpixel(dels[i].x - 1, dels[i].y, 0);
		putpixel(dels[i].x, dels[i].y, 0);
		putpixel(dels[i].x + 1, dels[i].y, 0);
		putpixel(dels[i].x - 1, dels[i].y + 1, 0);
		putpixel(dels[i].x, dels[i].y + 1, 0);
		putpixel(dels[i].x + 1, dels[i].y + 1, 0);
	}
}