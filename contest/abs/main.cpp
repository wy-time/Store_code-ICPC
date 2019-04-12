#include <iostream>
#include<algorithm>
#include<math.h>
bool cmp (int a,int b);
using namespace std;
int main()
{
    int n;
    int i;
    int a[105];
    while(cin>>n)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+i,cmp);
        for(i=0;i<n-1;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<a[i]<<endl;
    }
}
bool cmp (int a,int b)
{
    return abs(a)>abs(b);
}
