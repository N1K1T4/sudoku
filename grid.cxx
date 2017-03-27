#include "grid.h"
#include <fstream>
#include <iostream>

Grid::Grid(void)
{
	this->board=new Cell[81];
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
	this->board=new Cell[81];
	std::fstream input(location, std::fstream::in);
	if (input.is_open())
	{
		char val;
		for (int i=0; i<9; i++)
		{
			for (int j=0; j<9; j++)
			{
				input.get(val);
				this->board[i*9+j].set(val);
				std::cout << val << ' ' << this->board[i*9+j](0) << std::endl;
			}
			input.get(val);
		}
		input.close();
	}
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

const char* Grid::c_str(void) const
{
	static char cstr[91];
	char c;
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			c=this->board[i*9+j](0);
			if (!c)
			{
				c='v';
			}
			cstr[i*10+j]=c;
		}
		cstr[i*10+9]='\n';
	}
	cstr[90]='\0';
	return cstr;
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
	delete[] board;
	board=nullptr;
}
