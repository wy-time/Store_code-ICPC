#include <iostream>
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
const int maxn=1e5+5;
int num[maxn];
int vis[maxn];
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
    int n;
    cin>>n;
    int i;
    wfor(i,0,n)
    {
        cin>>num[i];
    }
    fill(vis,vis+num[n-1],1);
    int rest=0;
    vector<int>ans;
    int now_pos=num[n-1]-1;
    mfor(i,n-1,0)
    {
        while(now_pos>=0&&vis[now_pos]==0)
            now_pos--;
        rest=max(num[i],rest);
        if(i-1>=0&&num[i]==num[i-1])
        {
            if(rest>0&&now_pos>num[i])
            {
                ans.push_back(now_pos);
                vis[now_pos]=0;
                now_pos--;
                rest--;
            }else
            {
                ans.push_back(1000000);
            }
        }
        else if(i-1>=0)
        {
            ans.push_back(num[i-1]);
            rest--;
            vis[num[i-1]]=0;
        }else
        {
            if(rest>0&&now_pos!=num[i])
            {
                ans.push_back(now_pos);
                vis[now_pos]=0;
                now_pos--;
                rest--;
            }else
            {
                ans.push_back(1000000);
            }
        }
    }
    if(rest>0)
        cout<<-1<<endl;
    else
    {
        for(auto it=ans.rbegin();it!=ans.rend();it++)
            cout<<*it<<" ";
    }
    return 0;
}
