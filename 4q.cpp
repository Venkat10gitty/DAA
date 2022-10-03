#include<iostream>
using namespace std;
int main()
{
  int m,n;
  cout<<"Enter the dimension of the array mXn by enetering value of m and n:"; cin>>m>>n;
  int arr[m][n];
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++) 
    {
      cin>>arr[i][j]; 
    }
  }
  int transpose[n][m]; for(int i=0;i<m;i++) {
  for(int j=0;j<n;j++) {
    transpose[j][i]=arr[i][j]; }
  }
  for(int i=0;i<m;i++) {
    for(int j=0;j<n;j++) {
      cout<<arr[i][j]<<" ";
  }
    cout<<endl; 
  }
  cout<<endl;
  cout<<"The transpose of above matrix is:"<<endl;
  for(int i=0;i<m;i++) {
    for(int j=0;j<n;j++) {
      cout<<transpose[i][j]<<" ";
  }
  cout<<endl; 
  }
}
