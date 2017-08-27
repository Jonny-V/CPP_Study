#include<iostream>
using namespace std;
int length(int *);
void insert_sort(int *);
int main()
{
	int a[]={5,2,7,9,1,6,3,4,8,0};
	insert_sort(a);
	system("pause");
	return 0;

}
inline int length(int *p)
{
	return sizeof(p)/sizeof(int);
}
void insert_sort(int *p)
{
	int array_length=length(p);
	//cout<<array_length<<endl;
	array_length=10;
	int n;
	int key;
	for(int i=0;i<array_length;i++)
	{
		n=i-1;
		key=p[i];
		while(n>=0&&p[n]>key)
		{
			p[n+1]=p[n];
			n--;
		}
		p[n+1]=key;
	}
	for(int j=0;j<array_length;j++)
	{
		cout<<p[j]<<" ";
	}
	cout<<endl;
}