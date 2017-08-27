#include<iostream>
using namespace std;

const int Max = 100;

class Heap{
public:
	Heap()
	{
		length=0;
		size=0;
	}
	int size;
	int length;
	int *array;
};

void max_heapify(Heap,int);
void build_max_heap(Heap);
void heap_sort(Heap);

int main()
{
	int array[]={16,4,10,14,7,9,3,2,8,1};
	Heap a;
	a.array=array;
	a.length=a.size=10;
	heap_sort(a);
	for(int i=0;i<a.length;i++)
		cout<<a.array[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}

void max_heapify(Heap A,int i) 
{
	int l,r,largest;
	l=2*i;
	r=2*i+1;
	if(l<=A.size && A.array[l-1]>A.array[i-1])
		largest=l;
	else
		largest=i;
	if(r<=A.size && A.array[largest-1]<A.array[r-1])
		largest=r;
	if(largest != i)
	{
		A.array[i-1] = A.array[i-1]^A.array[largest-1];
		A.array[largest-1] = A.array[i-1]^A.array[largest-1];
		A.array[i-1] = A.array[i-1]^A.array[largest-1];
		max_heapify(A,largest);
	}
}
void build_max_heap(Heap A)
{
	A.length=A.size;
	for(int i=A.size/2; i>0; i--)
		max_heapify(A,i);
}

void heap_sort(Heap A)
{
	build_max_heap(A);
	while(A.size>1)
	{
		A.array[A.size-1] = A.array[A.size-1]^A.array[0];
		A.array[0] = A.array[A.size-1] ^ A.array[0];
		A.array[A.size-1] = A.array[A.size-1] ^ A.array[0];
		A.size--;
		max_heapify(A,1);
	}
}