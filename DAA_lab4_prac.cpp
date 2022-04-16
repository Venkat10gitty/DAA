// Brute Force
#include <stdio.h>
#include <limits.h>

int max(int x, int y) {
    return (x > y) ? x : y;
}

int MaxDistusingBruteForce(int arr[], int n)
{
    int diff = INT_MIN;
 
    if (n == 0) {
        return diff;
    }
 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                diff = max(diff, arr[j] - arr[i]);
            }
        }
    }
    return diff;
}
 
int main()
{
    int size;
    scanf("%d",&size);
    int arr [size];

    for(int i=0;i<size;i++){
    scanf("%d",&arr[i]); 
    }
 
    int result = MaxDistusingBruteForce(arr, size);
    if (result != INT_MIN) {
        printf("%d", result);
    }
    return 0;
}