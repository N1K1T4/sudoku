#ifndef CELL_H
#define CELL_H

class Cell
{
	private:
		char value[10];
	public:
		Cell(void);// default constructor
		Cell(const Cell& cell);// copy constructor
		Cell(Cell&& cell);// move constructor
		Cell(char val);
		Cell& operator=(const Cell& cell);// copy assignment operator
		Cell& operator=(Cell&& cell);// move assignment operator
		char operator()(char val) const;
		char pop(char val);
		void reset(void);
		~Cell(void);// destructor
};

#endif
