#include <iostream>
#include<algorithm>
using namespace std;
long long ans[6];
int main()
{
    std::ios::sync_with_stdio(false);
    long long n;
    cin>>n;
    long long i;
    long long cnt=0;
    for(i=0; i<n; i++)
    {
        int t;
        cin>>t;
        ans[t]++;
    }
    cnt+=ans[5];
    ans[5]=0;
    if(ans[4]<=ans[1])
    {
        cnt+=ans[4];
        ans[1]-=ans[4];
        ans[4]=0;
    }
    else
    {
        cnt+=ans[4];
        ans[1]=0;
        ans[4]=0;
    }
    if(ans[3]<=ans[2])
    {
        cnt+=ans[3];
        ans[2]-=ans[3];
        ans[3]=0;
    }
    else
    {
        cnt+=ans[2];
        ans[3]-=ans[2];
        ans[2]=0;
    }
    //if(ans[1]>0)
    //{
        if(ans[3]>0)
        {
            if(ans[3]*2<=ans[1])
            {
                cnt+=ans[3];
                ans[1]-=ans[3]*2;
                ans[3]=0;
            }
            else
            {
                cnt+=ans[3];
                ans[1]=0;
                ans[3]=0;
            }
        }
        else if(ans[2]>0)
        {
            //int a2=ans[2];
            //int a1=ans[1];
            int f4=ans[2]/2;
            ans[2]%=2;
            if(f4<=ans[1])
            {
                cnt+=f4;
                ans[1]-=f4;
                f4=0;
                ans[1]-=3;
                cnt++;
                ans[2]=0;
            }
            else
            {
                cnt+=f4;
                f4=0;
                ans[1]=0;
                cnt+=ans[2];
                ans[2]=0;
            }
            /*int cnttt=0;
            ans[2]=a2;
            ans[1]=a1;
            if(ans[2]*3<=ans[1])
            {
                cnttt+=ans[2];
                ans[1]-=ans[2]*3;
                ans[2]=0;
            }else
            {
                cnttt+=ans[1]/3;
                ans[2]-=ans[1]/3;
                ans[1]%=3;
                cnttt++;
                ans[1]=0;
                ans[2]--;
                cnttt+=ans[2]/2;
                cnttt+=ans[2]%2;
            }
            cnt+=min(cnttt,cntt);*/
        }
        if(ans[1]>0)
        {
            cnt+=ans[1]/5;
            ans[1]%=5;
            if(ans[1]>0)
                cnt++;
            ans[1]=0;
        }
    //}else
    //{
    //    cnt+=ans[2]+ans[3];
    //}
    cout<<cnt;
    return 0;
}
