#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int max(int a, int b)
{
	return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int> > K(n + 1, vector<int>(W + 1));
	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
								K[i - 1][w - wt[i - 1]],
								K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

int main()
{
    int size;
    cin>>size;
    int wt[size];
    int val[size];
    for(int i = 0; i<size; i++) {
        cin>>wt[i];
    }
    for(int j = 0; j<size; j++) {
        cin>>val[j];
    }
    int W;
    cin>>W;
    cout<<knapSack(W, wt, val, size)<<endl;
    
	return 0;
}


