//
// Created by Jonny Wu on 2017/9/1.
//

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screen {
	//friend void Windows_mgr::clear(Windows_mgr::ScreenIndex i);
public:

	friend class Windows_mgr;
	using pos = std::string::size_type;

	Screen() = default;
	Screen(const pos &ht, const pos &wt, const char c) :
		height(ht), width(wt), contents(ht * wt, c) {
	}
	Screen(const pos &ht, const pos &wt) :
		height(ht), width(wt), contents(ht*wt, ' ') {};

	char get() const {
		return contents[cursor];
	}
	inline char get(pos ht, pos wt) const;

	Screen &move(const pos &r, const pos &n);
	Screen &set(char c);
	Screen &set(const pos &r, const pos &n, char c);
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}

private:

	pos cursor = 0; //π‚±ÍŒª÷√
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const
	{
		os << contents;
	}
};



#endif