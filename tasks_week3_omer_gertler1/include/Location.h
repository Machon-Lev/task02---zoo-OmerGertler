#pragma once
#include <iostream>
using std::ostream;

struct Location
{
	int row;
	int col;
	int getRow();
	int getCol();
	void setRow(int newRow);
	void setCol(int newCol);
	bool operator == (const Location& loc) const;
	bool operator != (const Location& loc) const;
	Location operator+(const Location& loc) const;
	Location& operator+=(const Location& loc);

	friend ostream& operator<<(ostream& os, const Location& loc);
};


//friend ostream& operator<<(ostream& os, const Location& loc)
//ostream& operator<<(ostream& os, const Location& loc)
//{
//	os << '(' << loc.row << ", " << loc.col << ')';
//	return os;
//};
