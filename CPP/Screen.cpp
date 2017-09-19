//
// Created by Jonny Wu on 2017/9/1.
//

#include "Screen.h"

inline Screen &Screen::move(const pos &r, const pos &n) {
	pos row = r * width;
	cursor = row + n;
	return *this;
}

inline char Screen::get(pos ht, pos wt) const {
	return contents[ht * wt];
}

Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

Screen &Screen::set(const pos &r, const pos &n, char c)
{
	contents[r*width + n] = c;
	return *this;
}