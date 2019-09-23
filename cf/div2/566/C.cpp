#include <iostream>
#include <stack> 
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
const int maxn=1e5+5;
vector<string>ans[maxn][6];
int ma[300];
vector<string>res;
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
    ma['a']=1;
    ma['e']=2;
    ma['i']=3;
    ma['o']=4;
    ma['u']=5;
    int n;
    cin>>n;
    int i;
    wfor(i,0,n)
    {
        string s;
        cin>>s;
        int j;
        int cnt=0;
        int last=0;
        wfor(j,0,s.length())
        {
            if(ma[s[j]]!=0)
            {
                cnt++;
                last=ma[s[j]];
            }
        }
        ans[cnt][last].push_back(s);
    }
    stack<string>low;
    stack<string>high;
    wfor(i,0,maxn)
    {
        int j;
        stack<string>temp;
        if(low.size()%2!=0)
            low.pop();
        wfor(j,0,6)
        {
            int k=0;
            int len=ans[i][j].size();
            wfor(k,0,len)
            {
                if(j==0)
                    low.push(ans[i][j][k]);
                else
                {
                    if(k+1<len)
                    {
                        high.push(ans[i][j][k++]);
                        high.push(ans[i][j][k]);
                    }else
                        low.push(ans[i][j][k]);
                }
            }
            while(!temp.empty())
            {
                low.push(temp.top());
                temp.pop();
            }
            if(low.size()%2!=0)
                temp.push(low.top()),low.pop();
            if(high.size()%2!=0)
            {
                low.push(high.top());
                high.pop();
            }
            int len1=low.size();
            int len2=high.size();
            while(len1>=2&&len2>=2)
            {
                res.push_back(low.top()+" "+high.top());
                low.pop();
                high.pop();
                res.push_back(low.top()+" "+high.top());
                low.pop(),high.pop();
                len1-=2;
                len2-=2;
            }
        }
    }
    int len=high.size();
    while(len>=4)
    {
        string t1,t2,t3,t4;
        t1=high.top(),high.pop();
        t2=high.top(),high.pop();
        t3=high.top(),high.pop();
        t4=high.top(),high.pop();
        res.push_back(t1+" "+t3);
        res.push_back(t2+" "+t4);
        len-=4;
    }
    cout<<res.size()/2<<endl;
    for(auto k:res)
        cout<<k<<endl;
    return 0;
}
