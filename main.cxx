#include "grid.h"

int main(int argc, char* argv[])
{
	if (argc>1)
	{
		char* location(argv[1]);
		Grid sudoku(location);
	}
	return 0;
}
