/********************************
************插入排序**************
********************************/

#include<iostream>
#include<stdlib.h>
using namespace std;

bool insertSort(int A[],int n)
{
    if(A == NULL || n <= 0)
    {
        return false;
    }
	for(int j = 1;j < n; j++)
	{
		int key = A[j];
		int i = j-1;
		while( i >=0 && A[i] > key)
		{
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
	return true;
}

int main()
{
	int A[] = {1,3,5,65,4,15,46};
	insertSort(A,7);
	cout<<"After sorted:";
	for(int i = 0; i < 7; i++)
	{
		cout<<A[i]<<"\t";
	}
	cout<<endl;
	system("pause");
	return 0;
}
