#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int **a;
    int m,n,i,j;
    int max,r,c;
    printf("Input array size m,n:");
    scanf("%d,%d",&m,&n);
    a=(int**)malloc(sizeof(int*)*m);
    for(i=0;i<m;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*n);
    }
    printf("Input %d*%d array:\n",m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    max=a[0][0];
    r=0;
    j=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(max<a[i][j])
            {
                max=a[i][j];
                r=i;
                c=j;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        free(a[i]);
    }
    free(a);
    printf("maxScore = %d, class = %d, number = %d\n",max,r+1,c+1);
    return 0;
}
