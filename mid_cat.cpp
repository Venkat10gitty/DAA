#include <stdio.h>
#include <stdlib.h>
 
int countPairsWithDiffK(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {      
        for (int j = i+1; j < n; j++)
            if (arr[i] - arr[j] == k || arr[j] - arr[i] == k )
                  count++;
    }
    return count;
}

void printPairs(int *array, int size, int K){
    int i, j;
     
    for(i = 0; i < size; i++) {       
        for(j = i+1; j < size; j++) {
            if(abs(array[i] - array[j]) == K) {
               printf("%d\n%d\n", array[i], array[j]);
            }
        }
    }
}
 
int main(){
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i =0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    //int arr[4] = {2,8,4,5}; 
    int i, small, large;
    small = arr[0];
    large = arr[0];

    for (i = 1; i < size; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
        }
        
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    int flag=0;
    int diff = large - small;
    for(int i = 0; i<diff; i++) {
        int cou = countPairsWithDiffK(arr, size, i);
        if(cou > 1) {
            flag++;
            printf("%d\n", i);
            printf("%d\n", cou);
            printPairs(arr, size, i);
        }
    }
    if(flag == 0) {
        printf("0\n1\n");
        printf("%d\n", arr[0]);
        printf("%d\n", arr[1]);
    }
 
    return 0;
}