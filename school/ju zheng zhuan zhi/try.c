#include<stdio.h>
#include<stdlib.h>
void Transpose(int a[][10], int n);
void  Swap(int *x, int *y);
void PrintMatrix(int a[][10], int n);
int main ()
{
    int a[10][10];
    printf("Input n:");
    int n;
    scanf("%d",&n);
    printf("Input 3*3 matrix:\n");
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    Transpose(a,n);
    printf("The transposed matrix is:\n");
    PrintMatrix(a,n);
    return 0;
}
void PrintMatrix(int a[][10], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
}
void Transpose(int a[][10], int n)
{
    int i;
    int j;
    int* x;
    int* y;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            x=&a[i][j];
            y=&a[j][i];
            Swap(x,y);
        }
    }
}
void Swap(int *x, int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
