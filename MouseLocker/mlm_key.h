#pragma once

#include "mlm_var.h"

#define PRESS(key) (GetAsyncKeyState(key)&0x8000)

void scanKey()
{
	if (PRESS(VK_ESCAPE))
	{
		exit(0);
	}		
	if (PRESS(VK_LEFT))
	{
		current_ball.x--;
		Total.x++;
	}
	if (PRESS(VK_RIGHT))
	{
		current_ball.x++;
		Total.x++;
	}
	if (PRESS(VK_DOWN))
	{
		current_ball.y++;
		Total.y++;
	}
	if (PRESS(VK_UP))
	{
		current_ball.y--;
		Total.y++;
	}
	if (PRESS(VK_RETURN))
	{
		msg.lbutton = true;
	}
	if (PRESS(VK_RSHIFT))
	{
		msg.rbutton = true;
	}
	if (PRESS(VK_LSHIFT))
	{
		msg.mbutton = true;
	}
	if (PRESS(VK_SPACE))
	{
		if (dels.size())
			dels.erase(dels.begin(), dels.begin() + 1);
		msg.vkcode = 1;
	}
	if (msg.lbutton)
	{
		if (current_ball.x >= screen_x - 20 && current_ball.y <= 15)
		{
			exit(0);
		}
		drawing = true;
		if (!dels.empty())
		{
			if (!(dels.back().x == current_ball.x && dels.back().y == current_ball.y))
			{
				dels.push_back(current_ball);
			}
		}
		else
		{
			dels.push_back(current_ball);
		}
	}
	if (msg.wheel)
	{
		ballRadius += (msg.wheel) / 120;
		if (ballRadius < 0)
			ballRadius = 0;
	}
	if (msg.rbutton)
	{
		dels.clear();
	}
	if (msg.mbutton)
	{
		if (dels.size())
			dels.pop_back();
	}
}