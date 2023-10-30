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
        int n;
        cin>>n;
        int i;
        vector<int>v;
        int flag=-1;
        wfor(i,0,n)
        {
            int temp;
            cin>>temp;
            if(v.empty())
            {
                v.push_back(temp);
            }else if(flag==-1)
            {
                if(temp>v.back())
                    flag=1;
                else
                    flag=0;
                v.push_back(temp);
            }else if(flag==1)
            {
                if(temp>v.back())
                {
                    v.pop_back();
                    v.push_back(temp);
                }else
                {
                    v.push_back(temp);
                    flag=0;
                }
            }else
            {
                if(temp<v.back())
                {
                    v.pop_back();
                    v.push_back(temp);
                }else
                {
                    v.push_back(temp);
                    flag=1;
                }
            }
        }
        cout<<v.size()<<endl;;
        for(auto out:v)
            cout<<out<<" ";
        cout<<endl;
    }
    return 0;
}
