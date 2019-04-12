#include <iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,i;
    int *a;
    cin>>n>>m;
    while(n!=0&&m!=0)
    {
        a=(int*)malloc(sizeof(int)*(n+1));
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        a[i]=m;
        sort(a,a+n+1);
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<a[i]<<endl;
        cin>>n>>m;
        free(a);
    }
    return 0;
}
