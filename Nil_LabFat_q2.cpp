#include <iostream>
#include <climits>
using namespace std;
 
int IncreasingSequence(int arr[], int i, int n, int prev)
{
    if (i == n) {
        return 0;
    }
    int excl = IncreasingSequence(arr, i + 1, n, prev);
    int incl = 0;
    if (arr[i] > prev) {
        incl = 1 + IncreasingSequence(arr, i + 1, n, arr[i]);
    }
    return max(incl, excl);
}
 
int main()
{
    int size;
    int arr[size];
    cin>>size;
    int k;
    for(int i=0;i<size;i++) {
        cin>>k;
        k=arr[i];
    }
    cout<<IncreasingSequence(arr, 0, size, INT_MIN);
    return 0;
}



