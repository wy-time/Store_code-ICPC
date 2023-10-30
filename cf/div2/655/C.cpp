#include <iostream>
#include <algorithm> 
#include <vector> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn=2e5+5;
int num[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int>>sor;
        vector<pair<int,int>>usor;
        int n;
        cin>>n;
        int i;
        wfor(i,1,n+1)
        {
            cin>>num[i];
        }
        int cnt=0;
        int flag=0;
        int prel=0;
        int minnum=1e9;
        int maxnum=0;
        wfor(i,1,n+1)
        {
            if(num[i]!=i)
            {
                minnum=min(minnum,num[i]);
                maxnum=max(maxnum,num[i]);
                if(flag==1)
                {
                    sor.push_back(make_pair(prel,i-1));
                    flag=0;
                    prel=i;
                }else if(i==1)
                    prel=1;
            }else
            {
                if(flag==0)
                {
                    if(prel!=0)
                        usor.push_back(make_pair(min(prel,minnum),max(i-1,maxnum)));
                    flag=1;
                    prel=i;
                    minnum=1e9;
                    maxnum=0;
                }
            }
        }
        if(flag==1)
            sor.push_back(make_pair(prel,i-1));
        else
            usor.push_back(make_pair(min(prel,minnum),max(i-1,maxnum)));
        sort(usor.begin(),usor.end());
        int len=usor.size();
        if(len==0)
        {
            cout<<0<<endl;
            continue;
        }
        int l,r;
        l=usor[0].first,r=usor[0].second;
        vector<pair<int,int>>meg;
        wfor(i,1,len)
        {
            r=max(r,usor[i].second);
        }
        meg.push_back(make_pair(l,r));
        len=meg.size();
        int len2=sor.size();
        wfor(i,0,len)
        {
            int j;
            wfor(j,0,len2)
            {
                if(sor[j].first>=meg[i].first&&sor[j].first<=meg[i].second)
                    cnt++;
                else if(sor[j].second>=meg[i].first&&sor[j].second<=meg[i].second)
                    cnt++;
                else if(sor[j].first<=meg[i].first&&sor[j].second>=meg[i].second)
                    cnt++;
                if(cnt>0)
                    break;
            }
        }
        cout<<len+cnt<<endl;
    }
    return 0;
}
