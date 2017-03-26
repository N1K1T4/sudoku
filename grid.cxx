#include "grid.h"

Grid::Grid(void)
{
	this->reset();
}

Grid::Grid(const Grid& grid)
{
	for (int i=81; i--;)
	{
		this->board[i]=grid(i);
	}
}

Grid::Grid(Grid&& grid)
{
	for (int i=81; i--;)
	{
		this->board[i]=grid(i);
	}
	grid.reset();
}

Grid::Grid(char* location)
{
	(void)location;
	this->reset();
}

Grid& Grid::operator=(const Grid& grid)
{
	if (this!=&grid)
	{
		for (int i=81; i--;)
		{
			this->board[i]=grid(i);
		}
	}
	return *this;
}

Grid& Grid::operator=(Grid&& grid)
{
	if (this!=&grid)
	{
		for (int i=81; i--;)
		{
			this->board[i]=grid(i);
		}
		grid.reset();
	}
	return *this;
}

const Cell& Grid::operator()(int i) const
{
	return this->board[i];
}

char Grid::operator()(int i, int j) const
{
	return this->board[i*9+j](0);
}

void Grid::reset(void)
{
	for (int i=81; i--;)
	{
		board[i].reset();
	}
}

Grid::~Grid(void)
{
}
