#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int ans[46]={1,1};
    int i;
    for(i=2;i<46;i++)
    {
        ans[i]=ans[i-1]+ans[i-2];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int res=0;
        int cnt=0;
        bool bre=false;
        for(i=1;i<46;i++)
        {
            if(n-ans[i]>=ans[i+1])
            {
                n-=ans[i];
                res+=pow(2.0,1.0*cnt);
                cnt++;
            }
            else if(n!=0)
            {
                for(i=1;i<46;i++)
                    if(n==ans[i])
                    {
                        res+=pow(2.0,i-1.0);
                        bre=true;
                        break;
                    }
            }else
                break;
            if(bre)
                break;
        }
        cout<<res<<endl;
    }
    return 0;
}
