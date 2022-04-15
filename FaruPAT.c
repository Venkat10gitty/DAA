#include <stdio.h>
#include <string.h>

#define MAXL 500
#define MAXN 100

int isPossible[MAXL][MAXL][MAXN];
int matrix[MAXN][MAXN];
char str[MAXN + 1];
int L;

int go(int start, int end, int need)
{
    if (start > end)
        return 0;
    if (isPossible[start][end][need] != -1)
        return isPossible[start][end][need];

    int i, x, y;
    for (i = start; i < end; i++)
    {
        for (x = 0; x < MAXN; x++)
        {
            for (y = 0; y < MAXN; y++) if (matrix[x][y] == need)
            {
                if (go(start, i, x) == 1 && go(i + 1, end, y) == 1)
                {
                    isPossible[start][end][need] = 1;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    while (scanf(" %s", str) == 1)
    {
        L = strlen(str);
        memset(isPossible, -1, sizeof(isPossible));
        go(0, L - 1, 'a');
    }
    return 0;
}