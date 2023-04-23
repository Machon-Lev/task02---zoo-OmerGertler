#include "Location.h"

int Location::getRow() { return row; }

int Location::getCol() { return col; }

void Location::setRow(int newRow) { row = newRow; }

void Location::setCol(int newCol) { col = newCol; }

bool Location::operator == (const Location& loc) const { return (row == loc.row && col == loc.col); }

bool Location::operator != (const Location& loc) const { return (row != loc.row || col != loc.col); }

Location Location::operator+(const Location& loc) const
{
	Location newLoc;
	newLoc.setRow(row + loc.row);
	newLoc.setCol(col + loc.col);
	return newLoc;
}

Location& Location::operator+=(const Location& loc)
{
	(*this) = (*this) + loc;
	return *this;
}

ostream& operator<<(ostream& os, const Location& loc)
{
	os << '(' << loc.row << ", " << loc.col << ')';
	return os;
}