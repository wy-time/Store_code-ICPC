#include <iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int n=1;
    while(cin>>n&&n)
    {
        int**a;
        int i,j;
        a=(int**)malloc(n*sizeof(int*));
        for(i=0;i<n;i++)
        {
            a[i]=(int*)malloc((i+1)*sizeof(int));
        }
        a[0][0]=1;
        for(i=1;i<n;i++)
        {
            a[i][0]=1;
            a[i][i]=1;
            for(j=1;j<i;j++)
            {
                a[i][j]=a[i-1][j]+a[i-1][j-1];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                cout<<a[i][j];
                if(i!=j)
                    cout<<" ";
                else
                {
                    cout<<endl;
                }
            }
        }
        cout<<endl;
        for(i=0;i<n;i++)
        {
            free(a[i]);
        }
        free(a);
    }
    return 0;
}
