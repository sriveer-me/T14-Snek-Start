#include <utility>

class Snek
{
public:
	Snek();

	void Update(const std::pair<int,int>& direction);
	void Grow();
	void Draw();

private:
	static constexpr int MAX_SEGMENTS = 100;
	std::pair<int,int> _segments[MAX_SEGMENTS];
	int _currentLength = 3;
	bool _growSnek = false;
};