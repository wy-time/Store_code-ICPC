#include <iostream>
#include<cstring>
using namespace std;
int a[1000000];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        a[0]=1;
        int i;
        int cnt=1;
        for(i=1; i<=n; i++)
        {
            int j;
            for(j=0; j<cnt; j++)
            {
                a[j]*=i;
            }
            for(j=0; j<cnt||a[j]!=0; j++)
            {
                if(a[j]>=10)
                {
                    a[j+1]+=a[j]/10;
                    a[j]%=10;
                }
            }
            cnt=j;
        }
        for(i=cnt-1; i>=0; i--)
        {
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
