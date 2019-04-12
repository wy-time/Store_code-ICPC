#include <iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int n,i,m,t;
    cin>>n;
    int *a;
    while(n!=0)
    {
        a=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        m=a[0];
        t=0;
        for(i=0;i<n;i++)
        {
            if(m>a[i])
            {
                m=a[i];
                t=i;
            }
        }
        a[t]=a[0];
        a[0]=m;
        for(i=0;i<n-1;i++)
            cout<<a[i]<<" ";
        cout<<a[i]<<endl;
        cin>>n;
        free(a);
    }
    return 0;
}
