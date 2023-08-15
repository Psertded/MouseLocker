#include "mlm_core.h"
#include "mlm_draw.h"
#include "mlm_key.h"
#include <iostream>
#include <String>
std::string tolower(std::string str)
{
	std::string result = str;
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		result[i] = tolower(result[i]);
	}
	return result;
}
int main()
{
	atexit(close);
	std::string input;
	std::cout << "Enter simulation screen width(X)(auto,fullscreen,int)(empty is auto):";
	std::getline(std::cin, input);
	
	input = tolower(input);
	if (input == "auto")
	{
		screen_x = (int)((double)GetSystemMetrics(SM_CXSCREEN) * double(2.0 / 3.0) + 0.5);
		//example:1920/double(2/3) = 1280
	}
	else if (input == "fullscreen")
	{
		screen_x = GetSystemMetrics(SM_CXSCREEN);
		screen_y = GetSystemMetrics(SM_CYSCREEN);
		fullscreen = true;
	}
	else if (input.empty())
	{
		screen_x = (int)((double)GetSystemMetrics(SM_CXSCREEN) * double(2.0 / 3.0) + 0.5);
	}
	else
	{
		screen_x = abs(stoi(input));
	}
	std::cout << "screen_x:" << screen_x << std::endl;
	if (!fullscreen)
	{
		std::cout << "Enter simulation screen height(Y)(auto,fullscreen,int)(empty is auto):";
		std::getline(std::cin, input);

		input = tolower(input);
		if (input == "auto")
		{
			screen_y = (int)((double)GetSystemMetrics(SM_CYSCREEN) * double(2.0 / 3.0) + 0.5);
		}
		else if (input.empty())
		{
			screen_y = (int)((double)GetSystemMetrics(SM_CYSCREEN) * double(2.0 / 3.0) + 0.5);
		}
		else
		{
			screen_y = abs(stoi(input));
		}
	}
	std::cout << "screen_y:" << screen_y << std::endl;

	std::cout << "Enable batch draw(Y/N)(empty is y):";
	std::getline(std::cin, input);

	input = tolower(input);
	if (input == "y" || input == "yes")
	{
		batch = true;
	}
	else if (input.empty())
	{
		batch = true;
	}
	else
		batch = false;

	std::cout << "batch:" << batch << std::endl;

	//init


	HWND hWnd = initgraph(screen_x, screen_y);

	if (fullscreen)
	{
		SetWindowLong(hWnd, GWL_STYLE, (GetWindowLong(hWnd, GWL_STYLE) | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	}
	if(batch)
		BeginBatchDraw();
	setbkmode(TRANSPARENT);
	setbkcolor(0xffffff);	
	
	current_ball = Divide2(screenSize());
	settextcolor(RGB(0, 0, 0));	
	MaxRenderSize = textheight(L"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM|\\/") + 2;	
	const POINT div2 = Divide2(screenSize());
	while (true)
	{
		start = clock();
		drawing = false;
		erasing = false;
		cleardevice();

		getmessage(&msg, EX_MOUSE);

		scanKey();

		drawDel();
		GetCursorPos(&mouse);
		BorderCheck(&current_ball);
		move = CalcMove(mouse);
		DoMove(&current_ball, move);
		drawBall(current_ball, ballRadius);
		SetCursorPos(div2.x, div2.y);

		
		//draw info
		drawInfoText();		
		drawExitBox();
		end = clock();
		drawFPS(end - start);
		if(batch)
			FlushBatchDraw();
	}
}