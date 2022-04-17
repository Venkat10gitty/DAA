#include<stdio.h>

void read(int a[10][10],int row,int col)
{
   int i,j;
    for(i=1;i<=row;i++){
        for(j=1;j<=col;j++){
            printf("Enter Element %d %d : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}
void transpose(int a[10][10], int row)
{
    int i,j;
    int tmp;
    for(i=0;i< row-1;i++){
        for(j=i+1;j< row;j++){
            tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
}
void addition(int m1[10][10],int m2[10][10],int m3[10][10],int row,int col)
{
    int i,j;
    for(i=1;i<=row;i++){
        for(j=1;j<=col;j++){
             m3[i][j] =  (m1[i][j] + m2[i][j]);
        }
    }
}
void multiplication(int m1[10][10],int m2[10][10],int m3[10][10],int row,int col)
{
    int i,j,k;
    for(i=1;i<=row;i++){
        for(j=1;j<=col;j++){
            for (k=1;k<=row;k++){
                m3[i][j] = m3[i][j] + (m1[i][k] * m2[k][j]);
            }
        }
    }
}
void display(int m[10][10],int row,int col)
{
    int i,j;
    for(i=1;i<=row;i++){
        for(j=1;j<=col;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
   }
}
int main()
{
    int m1[10][10],m2[10][10],m3[10][10],row,col;
    printf("Enter number of rows :");
    scanf("%d",&row);
    printf("Enter number of colomns :");
    scanf("%d",&col);
    printf("Entries of 1st matrix :\n");
    read(m1,row,col);
    printf("Entries of 2nd matrix :\n");
    read(m2,row,col);
    transpose(m1,row);
    printf("Transpose of matrix 1 :\n");
    display(m2,row,col);
    transpose(m2,row);
    printf("Transpose of matrix 2 :\n");
    display(m2,row,col);
    addition(m1,m2,m3,row,col);
    printf("Addition of 2 matrices :\n");
    display(m3,row,col);
    multiplication(m1,m2,m3,row,col);
    printf("Multiplication of 2 matrices :\n");
    display(m3,row,col);
}