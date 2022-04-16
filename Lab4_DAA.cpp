// // Divide and conquer
#include <iostream>
#include <algorithm>
using namespace std;

int MinOfArray(int a[], int low, int high)
{
    int i,min;
    min = a[low];
    for(i=low;i<=high;i++)
    {
        if(a[i]<min)
        {
            min = a[i];
        }
    }
    return min;
}
int MaxOfArray(int a[], int low, int high)
{
    int i,max;
    max = a[low];
    for(i=low;i<=high;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
        }
    }
    return max;
}
int MaxDistUsingDivide_n_Conquer(int a[], int low, int high)
{
    if(low>=high)
        return 0;

    int mid = (low+high)/2;
    int leftPartition = MaxDistUsingDivide_n_Conquer(a,low,mid);
    int rightPartition = MaxDistUsingDivide_n_Conquer(a,mid+1,high);
    int left = MinOfArray(a,low,mid); 
    int right = MaxOfArray(a,mid+1,high);
    return max(max(leftPartition, rightPartition), (right - left));
}

int main() 
{
    int size;
    cin>>size;
    int arr[size];

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    
    int ans = MaxDistUsingDivide_n_Conquer(arr, 0, size-1);
    cout <<ans<<endl;
    return 0;
}