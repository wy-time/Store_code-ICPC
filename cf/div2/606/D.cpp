#include <iostream>
#include <vector> 
#include <algorithm> 
#include <set> 
#include <unordered_map> 
#include <cmath> 
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
vector <int>_01;
vector <int>_11;
vector <int>_10;
vector <int>_00;
unordered_map<string,int> mp;
set<int>st;
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
        st.clear();
        mp.clear();
        _00.clear();
        _01.clear();
        _10.clear();
        _11.clear();
        int n;
        cin>>n;
        int i;
        wfor(i,0,n)
        {
            string s;
            cin>>s;
            if (s[0]=='0'&&s[s.length()-1]=='0')
                _00.push_back(i+1);
            else if(s[0]=='1'&&s[s.length()-1]=='0')
            {
                _10.push_back(i+1);
                string temp=s;
                reverse(s.begin(),s.end());
                if(mp.count(s)==0)
                    mp.insert(make_pair(temp,i+1));
                else
                {
                    st.insert(i+1);
                    st.insert(mp[s]);
                }
            }
            else if(s[0]=='0'&&s[s.length()-1]=='1')
            {
                _01.push_back(i+1);
                string temp=s;
                reverse(s.begin(),s.end());
                if(mp.count(s)==0)
                    mp.insert(make_pair(temp,i+1));
                else
                {
                    st.insert(i+1);
                    st.insert(mp[s]);
                }

            }
            else
                _11.push_back(i+1);
        }
        int flag=1;
        int res=0;
        if((_01.size()==0&&_10.size()==0)&&(_00.size()>=1&&_11.size()>=1))
            flag=0;
        else
        {
            int cha=abs((int)(_01.size()-_10.size()));
            res=cha/2;
        }
        if(flag==1)
        {
            vector<int>ans;
            int len=0;
            if(_01.size()>_10.size())
            {
                len=_01.size();
                wfor(i,0,len)
                {
                    if(ans.size()==res)
                        break;
                    if(st.count(_01[i])==0)
                        ans.push_back(_01[i]);
                }
            }else
            {
                len=_10.size();
                wfor(i,0,len)
                {
                    if(ans.size()==res)
                        break;
                    if(st.count(_10[i])==0)
                        ans.push_back(_10[i]);
                }
            }
            if(ans.size()==res)
            {
                cout<<res<<endl;
                for(int k:ans)
                    cout<<k<<" ";
            }else
                cout<<-1;
            cout<<endl;
        }else
            cout<<-1<<endl;
    }
    return 0;
}
