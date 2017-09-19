#include<iostream>
#include<string>
using namespace std;
class Employee {
public:
	Employee() = default;
	Employee(string s):name(s),UID(getUID()) { }
	Employee(const Employee &person) = delete;
	//{
	//	name = person.name;
	//	UID = getUID();
	//}
	Employee& operator=(const Employee &person) = delete;
	//{
	//	name = person.name;
	//	UID = getUID();
	//	return *this;
	//}

	int getUID()
	{
		return ++id;
	}
private:
	string name;
	int UID;
	static int id;
};

int Employee::id = 0;

int main()
{
	system("pause");
	return 0;
}