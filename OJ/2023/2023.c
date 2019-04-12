#include<stdio.h>
#include<stdlib.h>
void trance(int**p, int b, int c);
int main ()
{
    int **a;
    int i, j;
    a = (int**)malloc(sizeof(int) * 3);
    for(i = 0; i < 3; i++)
    {
        a[i] = (int*)malloc(sizeof(int) * 3);
    }
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    trance(a, 0, 1);
    trance(a, 0, 2);
    trance(a, 1, 2);
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < 3; i++)
    {
        free(a[i]);
    }
    free(a);
    return 0;
}
void trance (int**p, int b, int c)
{
    int t;
    t = p[b][c];
    p[b][c] = p[c][b];
    p[c][b] = t;
}
