#include <iostream>
#include <string> 
#include <algorithm> 
#include <vector> 
#include <cstdio>
#include <stack> 
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn=2005;
char num[maxn][maxn];
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        stack<pair<int,int> >ans;
        cin>>n>>m;
        int i,j;
        wfor(i,0,n)
        {
            string s;
            cin>>s;
            wfor(j,0,s.length())
            {
                num[i][j]=s[j];
            }
        }
        int k;
        int tflag=1;
        int last=0;
        mfor(k,26,0)
        {
            if(tflag==0)break;
            vector<pair<int,int> >v;
            int flag=0;
            wfor(i,0,n)
            {
                if(tflag==0)break;
                wfor(j,0,m)
                {
                    if(tflag==0)break;
                    if(num[i][j]==k+'a')
                    {
                        if(v.empty())
                            v.push_back(make_pair(i,j));
                        else
                        {
                            if(flag!=0)
                            {
                                if(flag==1)
                                {
                                    if(i==v[0].first)
                                        v.push_back(make_pair(i,j));
                                    else
                                    {
                                        tflag=0;
                                        break;
                                    }
                                }else
                                {
                                    if(j==v[0].second)
                                        v.push_back(make_pair(i,j));
                                    else
                                    {
                                        tflag=0;
                                        break;
                                    }
                                }
                            }else
                            {
                                if(i==v[0].first||j==v[0].second)
                                {
                                    v.push_back(make_pair(i,j));
                                    if(i==v[0].first)
                                        flag=1;
                                    else
                                        flag=2;
                                }else
                                {
                                    tflag=0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            sort(v.begin(),v.end());
            int len=v.size();
            int p;
            wfor(p,0,len-1)
            {
                wfor(i,v[p].first,v[p+1].first+1)
                {
                    wfor(j,v[p].second,v[p+1].second+1)
                    {
                        if(num[i][j]<k+'a')
                        {
                            tflag=0;
                            break;
                        }
                    }
                    if(tflag==0)break;
                }
                if(tflag==0)break;
            }
            if(tflag!=0)
            {
                if(last==1&&len==0)
                {
                    auto temp=ans.top();
                    ans.pop();
                    auto temp2=ans.top();
                    ans.push(temp);
                    ans.push(temp2);
                    ans.push(temp);
                }
                if(v.size()!=0)
                {
                    ans.push(make_pair(v.rbegin()->first,v.rbegin()->second));
                    ans.push(make_pair(v.begin()->first,v.begin()->second));
                    last=1;
                }
            }
        }
        if(tflag==0)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            cout<<ans.size()/2<<endl;
            while(!ans.empty())
            {
                cout<<ans.top().first+1<<" "<<ans.top().second+1<<" ";
                ans.pop();
                cout<<ans.top().first+1<<" "<<ans.top().second+1<<endl;
                ans.pop();
            }
        }
    }
    return 0;
}
