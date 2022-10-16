/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Board.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	Board::Initialize(gfx);
	Board::set_GridWidth(20);
	Board::set_GridHeight(20);
}

Game::~Game()
{
	Board::DeInitialize();
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//direction handling
	static bool directionSet = false;
	if (wnd.kbd.KeyIsPressed(VK_LEFT) && 
		_snekDirection != std::make_pair<int,int>(1,0) && 
		_snekDirection != std::make_pair<int,int>(0,0) && 
		directionSet == false)
	{
		_snekDirection = std::make_pair<int, int>(-1, 0);
		directionSet = true;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT) && _snekDirection != std::make_pair<int,int>(-1,0) && directionSet == false)
	{
		_snekDirection = std::make_pair<int, int>(1, 0);
		directionSet = true;
	}
	else if (wnd.kbd.KeyIsPressed(VK_UP) && _snekDirection != std::make_pair<int,int>(0,1) && directionSet == false)
	{
		_snekDirection = std::make_pair<int, int>(0, -1);
		directionSet = true;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN) && _snekDirection != std::make_pair<int,int>(0,-1) && directionSet == false)
	{
		_snekDirection = std::make_pair<int, int>(0, 1);
		directionSet = true;
	}

	//debug test snek growth for now
	static bool growthDone = false;
	if (wnd.kbd.KeyIsPressed(VK_SPACE) && growthDone == false)
	{
		_snek.Grow();
		growthDone = true;
	}
	if (!wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		growthDone = false;
	}

	//greater value here means the snek moves slowly
	static int speedCounter = 0;
	speedCounter++;
	if (speedCounter >= 30)
	{
		_snek.Update(_snekDirection);
		speedCounter = 0;
		directionSet = false;
	}
}

void Game::ComposeFrame()
{
	_snek.Draw();
}