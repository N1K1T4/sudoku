#include "grid.h"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc>1)
	{
		char* location(argv[1]);
		Grid sudoku(location);
		std::cout << sudoku.c_str() << std::flush;
	}
	return 0;
}
