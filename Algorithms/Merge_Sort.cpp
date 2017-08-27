#include<iostream>
using namespace std;
#define MAX 10000;

void merge(int *,int,int,int);
void merge_sort(int *,int,int);
int main()
{
	int a[]={9,8,7,6,5,4,3,2,1,0};
	merge_sort(a,1,10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	getchar();
}
void merge(int *a,int p,int q,int r)
{
	int n1=q-p+1;	//the number of array1's element
	int n2=r-q;		//the number of array2's element
	int *array1=new int[n1+1];
	int *array2=new int[n2+1];
	int i,j;
	for(i=0;i<n1;i++)
		array1[i]=a[p+i-1];
	for(j=0;j<n2;j++)
		array2[j]=a[q+j];
	array1[n1]=MAX;
	array2[n2]=MAX;
	i=j=0;
	for(int m=p-1;m<r;m++)
	{
		if(array1[i]<=array2[j])
		{
			a[m]=array1[i];
			i++;
		}
		else
		{
			a[m]=array2[j];
			j++;
		}
	}
	delete array1;
	delete array2;
}
void merge_sort(int *a,int p,int r)
{
	if(p<r)
	{	
		int q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);	
	}
}