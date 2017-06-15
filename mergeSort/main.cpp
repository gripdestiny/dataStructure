/*****************
*********归并排序******
*******************/
#include <iostream>
#include<stdlib.h>
using namespace std;

bool Merge(int arr[],int left, int mid, int right, int *result)
{
    if(arr == NULL || left < 0 )
    {
        return false;
    }
    int i = left;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right)
    {
        if( arr[i] <= arr[j] )
        {
            result[k++] = arr[i++];
        }
        else
        {
            result[k++] = arr[j++];
        }
    }
    while(i <= mid)
    {
        result[k++] = arr[i++];
    }
    while(j <= right)
    {
        result[k++] = arr[j++];
    }
    for(i =0; i < k;i++)
    {
        arr[left+i] = result[i];
    }
    return true;
}

void mergeSort(int * data, int left, int right, int *result)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(data, left, mid, result);
        mergeSort(data, mid+1, right, result);
        Merge(data,left, mid, right, result);
    }
}


int main()
{
    int data[] = {9,8,7,6,10,12,13};
    int *result = new int[20];
    mergeSort(data, 0, 6, result);
    for(int i = 0; i < 7; i++)
    {
        cout<<data[i]<<"\t";
    }

    system("pause");
    return 0;
}
