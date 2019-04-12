#include<stdio.h>
int main ()
{
    int i,j,k=0;
    int c1[4]={0};
    int a[2][3];
    int b[3][2];
    int c[2][2];
    a[0][0]=1,a[0][1]=2,a[0][2]=3;
    a[1][0]=4,a[1][1]=5,a[1][2]=6;
    b[0][0]=1,b[0][1]=1;
    b[1][0]=0,b[1][1]=2;
    b[2][0]=2,b[2][1]=0;
    for(j=0;j<3;j++)
    {
        c1[k]+=a[0][j]*b[j][0];
    }
    k++;
    for(j=0;j<3;j++)
    {
        c1[k]+=a[0][j]*b[j][1];
    }
    k++;
    for(j=0;j<3;j++)
    {
        c1[k]+=a[1][j]*b[j][0];
    }
    k++;
    for(j=0;j<3;j++)
    {
        c1[k]+=a[1][j]*b[j][1];
    }
    c[0][0]=c1[0],c[0][1]=c1[1];
    c[1][0]=c1[2],c[1][1]=c1[3];
    printf("array A=\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("\t%d",a[i][j]);
        }
        printf("\t%d\n",a[i][j]);
    }
    printf("array B=\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            printf("\t%d",b[i][j]);
        }
        printf("\t%d\n",b[i][j]);
    }
    printf("array C=\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<1;j++)
        {
            printf("\t%d",c[i][j]);
        }
        printf("\t%d\n",c[i][j]);
    }
    return 0;
}
