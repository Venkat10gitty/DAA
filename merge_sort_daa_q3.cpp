#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include<vector>
using namespace std;

void merge(vector<int> &v, int start, int middle, int end) {
    vector<int> L(middle - start + 1);
    vector<int> R(end - middle);

    for (int i = 0; i < L.size(); ++i)
        L[i] = v[start + i];

    for (int i = 0; i < R.size(); ++i)
        R[i] = v[middle + 1 + i];

    int l = 0, r = 0;

    int c = start;

    while (l < L.size() && r < R.size()){
        if (L[l] <= R[r]){
            v[c] = L[l];
            l++;
        } else {
            v[c] = R[r];
            r++;
        }
        c++;
    }

    while (l < L.size()) 
    v[c++] = L[l++];

    while ( r < R.size()) 
    v[c++] = R[r++];
}

void merge_sort(vector<int> &v, int i, int j){   
	if(i>=j)
	return;
	int m=(i+j)/2;
	merge_sort(v,i,m);
	merge_sort(v,m+1,j);
	merge(v,i,m,j);
	   
}

int main()
{ 
	int n,i,x;
	vector<int> v;
	cin >> n;
	std::srand(static_cast<unsigned int>(std::time(nullptr))); 
				
	for(int i=0; i<n; i++){
		// x=std::rand();
		// x=x%100;
        //cin>>x;
        int num;
        cin >> num;
		v.push_back(num);
	}
				
	clock_t tStart = clock();
	merge_sort(v,0,n-1);
	for(int i=0; i<n; i++)
	printf("%d ",v[i]);
	printf("\nTime taken: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
		
	return 0;
	  
}
