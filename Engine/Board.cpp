#include "Board.h"
#include <assert.h>

Board* Board::_boardInstance = nullptr;

Board::Board(Graphics& gfx)
    :
    _gfx(gfx)
{}

void Board::Initialize(Graphics& gfx)
{
    if (_boardInstance == nullptr)
    {
        _boardInstance = new Board(gfx);
    }
}

void Board::DeInitialize()
{
    if (_boardInstance != nullptr)
    {
        delete _boardInstance;
    }
}

Board* Board::GetInstance()
{
    assert(_boardInstance != nullptr);
    return _boardInstance;
}

void Board::set_GridWidth(int newWidth)
{
    //no unexpected and strange behaviour down the line..
    assert(newWidth > 0);
    
    auto board = Board::GetInstance();

    //remainder here means the entire window is not being used by the board.. it might look strange
    assert(board->_gfx.ScreenWidth % newWidth == 0);
    
    board->_gridWidth = newWidth;
}

void Board::set_GridHeight(int newHeight)
{
    assert(newHeight > 0);

    auto board = Board::GetInstance();

    //remainder here means the entire window is not being used by the board.. it might look strange
    assert(board->_gfx.ScreenHeight % newHeight == 0);

    board->_gridHeight = newHeight;
}

int Board::get_GridWidth()
{
    return Board::GetInstance()->_gridWidth;
}

int Board::get_GridHeight()
{
    return Board::GetInstance()->_gridHeight;
}

int Board::GridLengthX()
{
    auto board = Board::GetInstance();
    assert(board->_gridWidth > 0);
    const int screenWidth = board->_gfx.ScreenWidth;

    return screenWidth / board->_gridWidth;
    
}

int Board::GridLengthY()
{
    auto board = Board::GetInstance();
    assert(board->_gridHeight > 0);
    const int screenHeight = board->_gfx.ScreenHeight;

    return screenHeight / board->_gridHeight;
}

void Board::Draw(int gridX, int gridY, Color c)
{
    auto board = Board::GetInstance();
    assert(board->_gridWidth  > 0);
    assert(board->_gridHeight > 0);

    const int screenWidth  = board->_gfx.ScreenWidth;
    const int screenHeight = board->_gfx.ScreenHeight;

    const int numberOfGridsX = screenWidth  / board->_gridWidth;
    const int numberOfGridsY = screenHeight / board->_gridHeight;

    assert(gridX < numberOfGridsX);
    assert(gridY < numberOfGridsY);

    std::pair<int, int> topLeft     = std::make_pair(gridX * board->_gridWidth, gridY * board->_gridHeight);
    board->_gfx.DrawRectDim(topLeft.first, topLeft.second, board->_gridWidth, board->_gridHeight, c);
}