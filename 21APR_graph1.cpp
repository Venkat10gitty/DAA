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
    int x=0, y=0;
    int flag = 0;
    for(int i = 0; i<size; i++) {
            
            if(arr[x][y] == 1) {
                flag++;
                break;
            }
            x++;
            y++;
        }
    if(flag == 0) {
        cout<<"yes\n";
    }
    else
        cout<<"no\n";

    
    for(int i = 0; i < size; i++) {
        int count = 0;
        for(int j = 0; j < size; j++) {
            if(arr[i][j] == 1) {
                count++;
            }
        }
        cout<<count<<" ";
    }
}