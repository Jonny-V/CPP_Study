#ifndef WINDOWS_MGR_H
#define WINDOWS_MGR_H
 
#include<vector>
#include"Screen.h"

class Windows_mgr
{
public:
	Windows_mgr() = default;
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);

private:
	std::vector<Screen> screens{ Screen(24,80,' ') };
};


#endif  // WINDOWS_MGR_H