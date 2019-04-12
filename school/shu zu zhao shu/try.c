#include<stdio.h>
int Search(int a[], int n, int x);
int main ()
{
    int a[10];
    int i;
    int x;
    printf("Input 10 numbers:\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Input x:\n");
    scanf("%d",&x);
    int r=Search(a,10,x);
    if(r==-1)
    {
        printf("Not Found!\n");
    }else
    {
        printf("Subscript of x is %d\n",r);
    }
    return 0;
}
int Search(int a[], int n, int x)
{
    int i;
    int t=-1;
    for(i=0;i<n;i++)
    {
        if(x==a[i])
        {
           t=i;
        }
    }
    return t;
}
