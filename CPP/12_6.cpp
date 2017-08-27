#include<iostream>
#include<vector>
using namespace std;

vector<int> *fun1()
{
	return new vector<int>;
}

void fun2(vector<int> *savekey,int key)
{
	savekey->push_back(key);
}

void fun3(vector<int> *savekey)
{
	vector<int>::iterator point;
	for(point=savekey->begin();point!=savekey->end();point++)
		cout<<*point<<" ";
	delete savekey;
}

int main()
{
	int key;
	vector<int> *test = fun1();
	while (cin>>key)
	{
		fun2(test,key);
	}
	fun3(test);
	system("pause");
	return 0;
}