#include<stdio.h>
int main()
{
    int n=2,m=3;
    int i,j,k,x;
    int a[100][100];
    int b[100][100];
    int c[100][100];
    printf("Input 2*3 matrix A:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Input 3*2 matrix B:\n");
    for(j=0;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    k=n;
    x=-1;
    int sum;
    for(i=0;i<n;i++)
    {
        x=-1;
        k=n;
        while(k--)
        {
            sum=0;
            x++;
            for(j=0;j<m;j++)
            {
                sum+=a[i][j]*b[x][j];
            }
            c[i][x]=sum;
        }
    }
    printf("matrix C:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            printf("%6d ",c[i][j]);
        }
        printf("%6d\n",c[i][j]);
    }
    return 0;
}
