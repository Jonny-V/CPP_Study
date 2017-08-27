#include<iostream>
#include<vector>
#include<memory>
using namespace std;

shared_ptr<vector<int>> fun1()
{
	return shared_ptr<vector<int>>(new vector<int>);
}

void fun2(shared_ptr<vector<int>> savekey,int key)
{
	savekey->push_back(key);
}

void fun3(shared_ptr<vector<int>> savekey)
{
	vector<int>::iterator point;
	for(point=savekey->begin();point!=savekey->end();point++)
		cout<<*point<<" ";
}

int main()
{
	int key;
	shared_ptr<vector<int>> test = fun1();
	while (cin>>key)
	{
		fun2(test,key);
	}
	fun3(test);
	system("pause");
	return 0;
}