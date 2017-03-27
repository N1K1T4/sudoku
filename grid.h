#ifndef GRID_H
#define GRID_H

#include "cell.h"

class Grid
{
	private:
		Cell* board;
	public:
		Grid(void);// default constructor
		Grid(const Grid& grid);// copy constructor
		Grid(Grid&& grid);// move constructor
		Grid(char* location);
		Grid& operator=(const Grid& grid);// copy assignment operator
		Grid& operator=(Grid&& grid);// move assignment operator
		const Cell& operator()(int i) const;
		char operator()(int i, int j) const;
		const char* c_str(void) const;
		void reset(void);
		~Grid(void);// destructor
};

#endif
