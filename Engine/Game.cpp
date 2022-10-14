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

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, 255);

	//Create random colors for grid
	for (int i = 0; i < Board::GridLengthX(); i++)
	{
		_colors.push_back(std::vector<Color>());
		for (int j = 0; j < Board::GridLengthY(); j++)
		{
			_colors[i].push_back(Color(distr(gen), distr(gen), distr(gen)));
		}
	}
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
}

void Game::ComposeFrame()
{
	//Create random colors for grid
	for (int i = 0; i < Board::GridLengthX(); i++)
	{
		for (int j = 0; j < Board::GridLengthY(); j++)
		{
			Board::Draw(i, j, _colors[i][j]);
		}
	}
}