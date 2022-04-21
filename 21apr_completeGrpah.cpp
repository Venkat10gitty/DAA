#include <iostream>
using namespace std;

int main()
{
    int checker=0;
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
    
    for(int i = 0; i < size; i++) {
        int count = 0;
        for(int j = 0; j < size; j++) {
            if(arr[i][j] == 0) {
                count++;
            }
        }
        if(count == size) {
            checker++;
            //cout<<"-1\n";
        }
        else 
            //cout<<"1\n ";
        
    }
    if(checker == size) {
        cout<<"-1\n";
    }
    else
        cout<<"1\n";
}