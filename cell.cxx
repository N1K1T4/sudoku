#include "cell.h"

Cell::Cell(void)
{
	this->reset();
}

Cell::Cell(const Cell& cell)
{
	for (char val=10; val--;)
	{
		this->value[(int)val]=cell(val);
	}
}

Cell::Cell(Cell&& cell)
{
	for (char val=10; val--;)
	{
		this->value[(int)val]=cell(val);
	}
	cell.reset();
}

Cell::Cell(char val)
{
	if (0<val && val<10)
	{
		for (int i=10; i--;)
		{
			this->value[i]=0;
		}
		this->value[0]=val;
		this->value[(int)val]=val;
	}
	else
	{
		this->reset();
	}
}

Cell& Cell::operator=(const Cell& cell)
{
	if (this!=&cell)
	{
		for (char val=10; val--;)
		{
			this->value[(int)val]=cell(val);
		}
	}
	return *this;
}

Cell& Cell::operator=(Cell&& cell)
{
	if (this!=&cell)
	{
		for (char val=10; val--;)
		{
			this->value[(int)val]=cell(val);
		}
		cell.reset();
	}
	return *this;
}

char Cell::operator()(char val) const
{
	if(val<10)
	{
		val=this->value[(int)val];
	}
	else
	{
		val=0;
	}
	return val;
}

char Cell::pop(char val)
{
	if (val>0 && val<10 && !this->value[0])
	{
		this->value[(int)val]=0;
		char zeros=0;
		for (val=10; val--;)
		{
			zeros+=!this->value[(int)val];
		}
		if (zeros==9)
		{
			val=9;
			while(!this->value[(int)val])
			{
				val--;
			}
			this->value[0]=val;
		}
	}
	return this->value[0];
}

void Cell::reset(void)
{
	for (char val=10; val--;)
	{
		this->value[(int)val]=val;
	}
}

Cell::~Cell(void)
{
}
