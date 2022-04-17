#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

void MergeDiagonal(int start, int mid, int end)
{

    int n1 = mid - start + 1;
    int n2 = end - mid;

    int MAT1[n1], MAT2[n2];

    for (int i = 0; i < n1; i++)
        MAT1[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        MAT2[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2)
    {
        if (MAT1[i] <= MAT2[j])
        {
            arr[k] = MAT1[i];
            i++;
        }
        else
        {
            arr[k] = MAT2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = MAT1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = MAT2[j];
        j++;
        k++;
    }
}
void sortDiagonal(int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - 1) / 2;

        sortDiagonal(start, mid);
        sortDiagonal(mid + 1, end);
        MergeDiagonal(start, mid, end);
    }
}

int main()
{
    int mat[10][10];

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> vect;

    for (int i = 0; i < n; i++) {
        arr.push_back(mat[i][i]);
    }

    sortDiagonal(0, n-1);

    for (int i = 0; i < n; i++)
    {
        mat[i][i] = vect[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}