#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   void solve(int si, int sj, vector < vector <int> > &mat){
      int n = mat.size();
      int m = mat[0].size();
      vector <int> temp;
      int i = si;
      int j = sj;
      int idx = 0;
      while(i < n && j < m){
         temp.push_back(mat[i][j]);
         i++;
         j++;
      }
      sort(temp.begin(), temp.end());
      idx = 0;
      i = si;
      j = sj;
      while(i < n && j < m){
         mat[i][j] = temp[idx];
         i++;
         j++;
         idx++;
      }
   }
   vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
      int n = mat.size();
      int m = mat[0].size();
      for(int i = 0; i <n; i++){
         solve(i, 0, mat);
      }
      for(int j = 1; j < m; j++){
         solve(0, j, mat);
      }
      return mat;
   }
};
int main(){
   int in,temp;
   cin>>in;
   vector<vector<int>> v;
   for(int i=0; i<in; i++){ 
    vector<int> row;
    for(int j=0; j<in; j++){
      cin>>temp;
      row.push_back(temp);
    }
    v.push_back(row);
   }
   Solution ob;
   ob.diagonalSort(v);
   for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }   
        cout << endl;
    }
}