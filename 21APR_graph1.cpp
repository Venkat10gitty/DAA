#include <iostream>
using namespace std;

int main()
{
    int size; 
    cin>>size;
    int arr[size][size];
    for (int i = 0; i < size; i++)                 
    {
        for (int j = 0; j < size; j++)
        {
            cin>>arr[i][j];
        }   
    }
    for (int i = 0; i < size; i++)                 
    {
        for (int j = 0; j < size; j++)
        {
            cout<<arr[i][j]<<" ";
        }   
        cout<<endl;
    }
    check(arr,size);
}
void check(int arr[][], int n) {
    int x, y;
    for(x = 0; x < n; x++) {
        for(y = 0; y < n; y++) {
            if(arr[x][y] == 1) {
                cout<<"no";
                break;
            }
        }
    }
    else
        cout<<"yes";
}