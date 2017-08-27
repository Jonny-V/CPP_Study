#include<iostream>
using namespace std;
#define Min_Value -10000

//define the struct of the point and maxsum
class point{
public:
	point()
	{
		left=right=0;
		max_sum=-1000;
	}
	void display()
	{
		cout<<"left point:"<<left<<"  right point:"<<right<<"  max sum:"<<max_sum<<endl;
	}

	int left;
	int right;
	int max_sum;
};

point find_max_crossing_subarray(const int *,int,int);	/*find max subarray of crossing mid*/
point find_maximum_subarray(const int *,int,int);		/*find max subarray of array*/

int main()
{
	point getpoint;
	int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	getpoint=find_maximum_subarray(a,1,16);
	getpoint.display();
	system("pause");
	return 0;
}

point find_max_crossing_subarray(const int *a,int low,int high)
{
	point return_point;
	int mid=(low+high)/2;
	int left_maxsum,right_maxsum,sum;
	left_maxsum=right_maxsum=Min_Value;
	sum=0;
	for(int i=mid-1;i>=low-1;i--) //find the maxsum in the left array 
	{
		sum+=a[i];
		if(sum>=left_maxsum)
		{
			return_point.left=i;
			left_maxsum=sum;
		}
	}
	sum=0;
	for(int j=mid;j<high;j++)	//find the maxsum in the right array
	{
		sum+=a[j];
		if(sum>=right_maxsum)
		{
			return_point.right=j;
			right_maxsum=sum;
		}
	}
	return_point.max_sum=left_maxsum+right_maxsum;
	return return_point;
}

point find_maximum_subarray(const int *a,int low,int high)
{
	point left_point,mid_point,right_point;
	int mid=(low+high)/2;
	if(low==high)	//low equal high ,then return itself
	{
		left_point.left=left_point.right=low;
		left_point.max_sum=a[low];
		return left_point;
	}
	else
	{
		left_point=find_maximum_subarray(a,low,mid);
		right_point=find_maximum_subarray(a,mid+1,high);
		mid_point=find_max_crossing_subarray(a,low,high);
		if(left_point.max_sum > right_point.max_sum && left_point.max_sum > mid_point.max_sum)
			return left_point;
		else if(right_point.max_sum > mid_point.max_sum)
			return right_point;
		else 
			return mid_point;
	}
}