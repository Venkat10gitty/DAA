#include <stdio.h>

int main(void)
{
    int size;
    scanf("%d",&size);
    int matrix3[size][size];
	for(int i=0; i<size; i++) {
      for(int j=0;j<size;j++) {
         scanf("%d", &matrix3[i][j]);
      }
   }
    int ub = (size > size) ? size : size;
    for (int i = 0; i < ub; i++)
    {
        int sm = matrix3[i][i];
        for (int j = i + 1; j < ub; j++)
        {
            if (sm > matrix3[j][j])
            {
                sm = matrix3[j][j];
                matrix3[j][j] = matrix3[i][i];
                matrix3[i][i] = sm;
            }
        } 
    }
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ",  matrix3[r][c]);
        }
        putchar('\n');
    }
    printf(" ");
    return 0;
}

