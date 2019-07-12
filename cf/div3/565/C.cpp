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
const int maxn=5e5+5;
int num[maxn];
vector<int>pos[6];
int ma[50];
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    int n;
    cin>>n;
    int i;
    ma[4]=0;
    ma[8]=1;
    ma[15]=2;
    ma[16]=3;
    ma[42]=5;
    ma[23]=4;
    wfor(i,0,n)
    {
        cin>>num[i];
        pos[ma[num[i]]].push_back(i);
    }
    int cnt=0;
    int sz=pos[0].size();
    int flag=1;
    int nowpos[6]={0};
    wfor(i,0,sz)
    {
        int now=pos[0][i];
        int j;
        wfor(j,1,6)
        {
            int temp=upper_bound(pos[j].begin()+nowpos[j],pos[j].end(),now)-pos[j].begin();
            if(temp==pos[j].size())
            {
                flag=0;
                break;
            }
            now=pos[j][temp];
            nowpos[j]=temp+1;
        }
        if(!flag)
            break;
        if(flag)
            cnt++;
    }
    cout<<n-cnt*6<<endl;
    return 0;
}
