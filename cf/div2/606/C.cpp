#include <iostream>
#include <set> 
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
set<int>ans;
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
        ans.clear();
        string s;
        cin>>s;
        string one="one";
        string two="two";
        int pos=0;
        while(pos!=-1)
        {
            pos=s.find(one,pos);
            if(pos!=-1)
            {
                if(pos-1>=0&&pos-2>=0)
                {
                    if(s[pos-1]=='w'&&s[pos-2]=='t')
                    {
                        s[pos]='g';
                        ans.insert(pos+1);
                    }else
                        ans.insert(pos+2);
                }else 
                {
                    ans.insert(pos+2);
                }
                pos+=1;
            }
        }
        pos=0;
        while(pos!=-1)
        {
            pos=s.find(two,pos);
            if(pos!=-1)
            {
                ans.insert(pos+2);
                pos+=1;
            }
        }
        cout<<ans.size()<<endl;
        for(auto k:ans)
            cout<<k<<" ";
        cout<<endl;
    }
    return 0;
}
