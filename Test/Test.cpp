#include<iostream>
#include<vector>
using namespace std;
int main()
{
	/*int arr[][2] = { 1,2,3,4,5,6 };
	int(*p)[2] = arr;

	cout << (*p+1)<< endl;
	p++;
	cout << **p<< endl;*/
	int **p = new int *[3];

	p[0][0] = 3;
	cout << p[0][0] << endl;


	system("pause");
	return 0;
    
}

