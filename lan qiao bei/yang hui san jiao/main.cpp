#include <iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int **a;
    int i,j;
    a=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*(i+1));
    }
    a[0][0]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0||j==i)
            {
                a[i][j]=1;
            }else
            {
                a[i][j]=a[i-1][j]+a[i-1][j-1];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<a[i][j]<<endl;
    }
    for(i=0;i<n;i++)
        free(a[i]);
    free(a);
    return 0;
}
