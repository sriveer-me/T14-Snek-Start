//#define SIGSLOT_PURE_ISO
//#include "sigslot.h"

#include "Snek.h"
#include "Board.h"

#include <assert.h>

Snek::Snek()
{
	_segments[0] = std::make_pair<int, int>(10,10);
	_segments[1] = std::make_pair<int, int>(9, 10);
	_segments[2] = std::make_pair<int, int>(8, 10);
}

void Snek::Update(const std::pair<int, int>& direction)
{
	if (_growSnek == true && _currentLength < MAX_SEGMENTS)
	{
		_currentLength += 1;
		_growSnek = false;
	}

	//if there is no need to update the snek.. return early
	if (abs(direction.first) + abs(direction.second) == 0)
		return;

	//see that the direction passed in is reasonable.. no diagnol or crazy values
	assert(abs(direction.first) + abs(direction.second) == 1);

	for (int i = _currentLength - 1; i > 0; i--)
	{
		if (_segments[i] == _segments[0])
		{
			//Handle Game Over
		}
		else 
			_segments[i] = _segments[i - 1];
	}
	_segments[0].first  += direction.first;
	_segments[0].second += direction.second;
}

void Snek::Grow()
{
	_growSnek = true;
}

void Snek::Draw()
{
	for (int i = _currentLength - 1; i > 0; i--)
		Board::Draw(_segments[i].first, _segments[i].second, Colors::Gray);
}