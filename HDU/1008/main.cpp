#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n=1;
    int req[1005];
    while(cin>>n&&n)
    {
        memset(req,0,sizeof(req));
        int i;
        for(i=0;i<n;i++)
        {
            cin>>req[i];
        }
        int now=0;
        long long res=0;
        for(i=0;i<n;i++)
        {
            if(req[i]>now)
            {
                res+=(req[i]-now)*6;
                now=req[i];
            }else
            {
                res+=(now-req[i])*4;
                now=req[i];
            }
            res+=5;
        }
        cout<<res<<endl;
    }
    return 0;
}
