#pragma once
#include "Graphics.h"

class Board 
{
public:
	static void Initialize(Graphics& gfx);
	static void DeInitialize();
	static Board* GetInstance();
	
	static void set_GridWidth(int newWidth);
	static void set_GridHeight(int newHeight);

	static int get_GridWidth();
	static int get_GridHeight();

	static int GridLengthX();
	static int GridLengthY();

	static void Draw(int gridX, int gridY, Color c);

private:
	Board(Graphics& gfx);

	static Board* _boardInstance;

	Graphics& _gfx;
	int _gridWidth  = 0;
	int _gridHeight = 0;;
};