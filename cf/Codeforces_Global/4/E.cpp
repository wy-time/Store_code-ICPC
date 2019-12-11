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
const int maxn=1e6+5;
int _next[maxn][3];
int __next[maxn][3];
char ans[maxn];
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
    string s;
    cin>>s;
    int i;
    int len=s.size();
    string res=s;
    reverse(res.begin(),res.end());
    _next[len][0]=_next[len][1]=_next[len][2]=-1;
    __next[len][0]=__next[len][1]=__next[len][2]=-1;
    mfor(i,len-1,0)
    {
        int j;
        wfor(j,0,3)
        {
           _next[i][j]=_next[i+1][j];
           _next[i][res[i]-'a']=i;
        }
    }
    mfor(i,len-1,0)
    {
        int j;
        wfor(j,0,3)
        {
            __next[i][j]=__next[i+1][j];
            __next[i][s[i]-'a']=i;
        }
    }
    int nowa=0;
    int nowb=0;
    int flag=0;
    int cnt=0;
    while(nowa<=len/2&&nowb<=len/2)
    {
        int choosea=len-__next[nowa][0]+len-_next[nowb][0];
        if(__next[nowa][0]==-1||_next[nowb][0]==-1)
            choosea=-1;
        int chooseb=len-__next[nowa][1]+len-_next[nowb][1];
        int choosec=len-__next[nowa][2]+len-_next[nowb][2];
        if(__next[nowa][1]==-1||_next[nowb][1]==-1)
            chooseb=-1;
        if(__next[nowa][2]==-1||_next[nowb][2]==-1)
            choosec=-1;
        int maxnum=max(choosea,max(chooseb,choosec));
        if(maxnum==choosea)
        {
            ans[cnt++]='a';
            nowa=__next[nowa][0]+1;
            nowb=_next[nowb][0]+1;
        }else if(maxnum==chooseb)
        {
            ans[cnt++]='b';
            nowa=__next[nowa][1]+1;
            nowb=_next[nowb][1]+1;
        }else
        {
            ans[cnt++]='c';
            nowa=__next[nowa][2]+1;
            nowb=_next[nowb][2]+1;
        }
        if(nowa+nowb-1==len)
            flag=1;
    }
    if(!flag)
    {
        int t=cnt;
        mfor(i,t-1,0)
        {
            ans[cnt++]=ans[i];
        }
    }else
    {
        int t=cnt;
        mfor(i,t-2,0)
        {
            ans[cnt++]=ans[i];
        }
    }
    if(cnt>=len/2)
        cout<<ans<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
