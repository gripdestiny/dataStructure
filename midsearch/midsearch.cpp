#include <iostream>
#include <stdio.h>
using namespace std;

int midsearch(int arr[], int val, int low, int hight)
{
	if(low > hight)
	{
		return -1;
	}
	else{
		if(val > arr[(low + hight )/2])		
		{
			return midsearch(arr , val, (low+hight)/2+1, hight );
		}
		else if( val < arr[(low+hight)/2])
		{
			return midsearch(arr, val, low, (low+hight)/2-1);
		}
		else 
		{
			return (low+hight)/2;
		}
	}
}

int main()
{
	int a[] = {1, 2, 5, 56 ,78};
	int n;
	n = midsearch(a, 79, 0, 4);
	cout<<n+1<<endl;

	return 0;
}
