#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef struct
{
    int power;
    int tt;
    int p[1005];
}st;
typedef struct
{
    double pp[1005];
}st1;
st gun[2005];
st1 pei[2005];
int main()
{
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    int n,m;
    while(cin>>n>>m)
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            int t;
            cin>>gun[i].power>>t;
            gun[i].tt=t;
            memset(gun[i].p,0,sizeof(gun[i].p));
            for(j=0;j<t;j++)
            {
                cin>>gun[i].p[j];
            }
        }
        for(i=0;i<=1000;i++)
        {
            memset(pei[i].pp,0,sizeof(pei[i].pp));
        }
        int cnt[1005]={0};
        for(i=0;i<m;i++)
        {
            int temp=0;
            double x=0;
            cin>>temp>>x;
            pei[temp].pp[cnt[temp]]=x;
            cnt[temp]++;
            sort(pei[temp].pp,pei[temp].pp+cnt[temp]);
        }
        double max1=0;
        for(i=0;i<n;i++)
        {
            double temp2=1;
            for(j=0;j<gun[i].tt;j++)
            {
                temp2+=(pei[gun[i].p[j]].pp[cnt[gun[i].p[j]]-1]);
            }
            double temp=gun[i].power*temp2;
            if(temp>max1)
            {
                max1=temp;
            }
        }
        printf("%.4f\n",max1);
    }
    return 0;
}
