#include <iostream>
#include <algorithm> 
#include <vector> 
#include <string> 
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
vector<int>v[3];
int ma[200];
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
    string s1,s2,s3;
    ma['s']=0;
    ma['m']=1;
    ma['p']=2;
    cin>>s1>>s2>>s3;
    v[ma[s1[1]]].push_back(s1[0]-'0');
    v[ma[s2[1]]].push_back(s2[0]-'0');
    v[ma[s3[1]]].push_back(s3[0]-'0');
    int i;
    int ans=4;
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    sort(v[2].begin(),v[2].end());
    wfor(i,0,3)
    {
        if(v[i].size()==1)
        {
            ans=min(ans,2);
        }else if(v[i].size()==2)
        {
            if(v[i][0]==v[i][1]||v[i][0]+1==v[i][1]||v[i][0]+2==v[i][1])
                ans=min(ans,1);
            else
                ans=min(ans,2);
        }else if(v[i].size()==3)
        {
            if((v[i][0]==v[i][1]&&v[i][1]==v[i][2])||(v[i][0]+1==v[i][1]&&v[i][1]+1==v[i][2]))
                ans=0;
            else if(v[i][0]==v[i][1]||v[i][1]==v[i][2]||v[i][0]+1==v[i][1]||v[i][1]+1==v[i][2]||v[i][0]+2==v[i][1]||v[i][1]+2==v[i][2])
                ans=min(ans,1);
            else
                ans=min(ans,2);
        }
    }
    cout<<ans<<endl;
    return 0;
}
