#include<iostream>
#include"linked_list.h"

using namespace std;

int main()
{
	Linked_List<int> *L = new Linked_List<int>();
	cout << L->isEmpty() << endl;
	for (int i = 0; i < 10; i++)
		L->add(i);
	L->printList();

	delete L;
	system("pause");
	return 0;
}