#include "Windows_mgr.h"
#include<string>
void Windows_mgr::clear(Windows_mgr::ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = std::string(s.height*s.width, ' ');
}
