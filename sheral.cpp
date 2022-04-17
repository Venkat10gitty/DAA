#include<iostream>
using namespace std;


int** make_2d_array(int r, int c) 
{
    int** arr = new int*[r];
    for(int i = 0; i < r; i++)
        arr[i] = new int[c];
// ,C12,C21,C22
    return arr;
}
    int** matrix_mul(int A[4][4],int B[4][4],int n)
    {
        int** C = make_2d_array(4, 4);;
        int** C11 = make_2d_array(4, 4);
        int** C12 = make_2d_array(4, 4);
        int** C21 = make_2d_array(4, 4);
        int** C22 = make_2d_array(4, 4);
        // int** A11 = make_2d_array(4, 4);
        // int** A12 = make_2d_array(4, 4);
        // int** A21 = make_2d_array(4, 4);
        // int** A22 = make_2d_array(4, 4);
        // int** B11 = make_2d_array(4, 4);
        // int** B12 = make_2d_array(4, 4);
        // int** B21 = make_2d_array(4, 4);
        // int** B22 = make_2d_array(4, 4);


        int A11[4][4],B11[4][4],A12[4][4],B12[4][4],A21[4][4],B21[4][4],A22[4][4],B22[4][4];
        int i=1,j=1;
        while(i<=n/2)
        {
            while(j<=n/2)
            {
            A11[i][j]=A[i][j];
            A21[i][j] = A[i+(n/2)][j];
            A12[i][j] = A[i][j+(n/2)];
            A22[i][j] = A[i+(n/2)][j+(n/2)];

            B11[i][j]=B[i][j];
            B21[i][j] = B[i+(n/2)][j];
            B12[i][j] = B[i][j+(n/2)];
            B22[i][j] = B[i+(n/2)][j+(n/2)];

            j++;
            }
            i++;
            j=1;

        }
    

    if(n<=2)
    {
        for (i=1;i<=n/2;i++)
        {
            for (j=1;j<=n/2;j++)
            {
                C[i][j]=A11[i][j]*B11[i][j]+A12[i][j]*B21[i][j];

                C[i+(n/2)][j] = A11[i][j]*B12[i][j] + A12[i][j]*B22[i][j];
                C[i][j+(n/2)] = A21[i][j]* B11[i][j] + A22[i][j] * B21[i][j];
                C[i+(n/2)][j+(n/2)] = A21[i][j]*B12[i][j]+A22[i][j]*B22[i][j];

            }
        }
    }

    else
    {
        // C11[4][4] = matrix_mul(*A11,*B11,n/2) + matrix_mul(*A12,*B21,n/2);
        // C12[4][4] = matrix_mul((A11,*B12,n/2) + matrix_mul(*A12,*B22,n/2);
        // C21[4][4] = matrix_mul(*A21,*B11,n/2) + matrix_mul(*A22,*B21,n/2);
        // C22[4][4] = matrix_mul(*A21,*B12,n/2) + matrix_mul(*A22,*B22,n/2);

        // C11 = matrix_mul(A11,B11,n/2) + matrix_mul(A12,B21,n/2);
        // C12 = matrix_mul(A11,B12,n/2) + matrix_mul(A12,B22,n/2);
        // C21 = matrix_mul(A21,B11,n/2) + matrix_mul(A22,B21,n/2);
        // C22 = matrix_mul(A21,B12,n/2) + matrix_mul(A22,B22,n/2);

    }
    return C;

    }
int main()
{
    int n , i , j;
    int** res;

    int A[4][4], B[4][4];

    cout<<"Enter the elements for"<<n<< "x "<<n <<"A matrix n";
  
        for(j=1;j<=4;j++)
        {
            cout<<"n";
            for(j=1;j<=4;j++)
            cin>>A[i][j];
        }
        cout<<"Enter the element for"<<n<<"x"<<n <<" B matrix n";
        for (i=1;i<=4;i++)
        {
            for (j=1;j<=4;j++)
            cin>>B[i][j];
        }

res = matrix_mul(A,B,4);
cout<<"The resultant matrix C is :";
for (i=0;i<4;i++)
{
    for(j=0;j<4;j++)
    cout<<res[i][j];
}
return 0;
    }