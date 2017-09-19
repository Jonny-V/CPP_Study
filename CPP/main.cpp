#include"Sales_data.h"
#include"Person.h"
#include"Screen.h"
#include"Windows_mgr.h"

using namespace std;
int main()
{
	//Sales_data a(std::cin);
	//print(std::cout, a);
	//cout << endl;

	//Person b(cin);
	//print(cout, b);
	//cout << endl;

	Screen myScreen(5, 3);
	const Screen blank(5, 3);
	myScreen.set('#').display(cout);
	cout << endl;
	blank.display(cout);
	cout << endl;
	Windows_mgr s;
	s.clear(0);


	system("pause");
	return 0;
}