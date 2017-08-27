#include<iostream>
//#include<string>
using namespace std;
double add(double,double);
double sub(double,double);
double mul(double,double);
double div(double,double);

double (*function[])(double,double)={
	add,sub,mul,div
};

int main()
{
	double a=5.0;
	double b=2.0;
	for(int i=0;i<4;i++)
		cout<<function[i](a,b)<<endl;
	system("pause");
	return 0;
}

double add(double a,double b)
{
	return a+b;
}


double sub(double a,double b)
{
	return a-b;
}

double mul(double a,double b)
{
	return a*b;
}

double div(double a,double b)
{
	return a/b;
}

