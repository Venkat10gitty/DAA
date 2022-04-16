#include<iostream>
#include<cstring>

using namespace std;
int main()
{
    int z =0;
    int count=0;
    char *txt;
    char *pat;
    
    cout<<"Enter the text: ";
    cin>>txt;
    cout<<"Enter the pattern: ";
    cin>>pat;
    int M = strlen(pat);
    int N = strlen(txt);
 
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
        {
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == M) 
        {
            count++;
            printf("Pattern found at index %d \n", i);
        }
    }
    if(count == 0) {
        printf("-1\n");
    }
    int arr[256];
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
        {
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == M) 
        {
            arr[z] = i;
            z++;
        }
    }
    int diff1 = arr[1] - arr[0];
    int diff2 = arr[2] - arr[1];
    
    if(diff1 == diff2) 
        printf("Arithmetic Text");
    else 
        printf("Not an Arithmetic text");
    
    return 0;
}