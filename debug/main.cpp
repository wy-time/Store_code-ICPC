#include <iostream>
#include <stack> 
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
    string s;
    cin>>s;
    if(s[0]==')'||s[n-1]=='(')
        cout<<":("<<endl;
    else 
    {
        string temp=s.substr(1,n-2);
        stack<pair<char,int>>st;
        int i;
        int len=temp.size();
        int flag=1;
        wfor(i,0,len)
        {
            if(st.empty())
            {
                if(temp[i]==')')
                {
                    flag=0;
                    break;
                }else
                {
                    st.push(make_pair(temp[i],i));
                }
            }else 
            {
                if(temp[i]==')')
                {
                    temp[i]=')';
                    int id=st.top().second;
                    st.pop();
                    temp[id]='(';
                }else
                    st.push(make_pair(temp[i],i));
            }
        }
        if(flag)
        {
            stack<pair<char,int>>st_temp;
            if(!st.empty())
            {
                while(!st.empty())
                {
                    pair <char,int>t_pari;
                    t_pari=st.top();
                    st.pop();
                    if(st_temp.empty())
                    {
                        if(t_pari.first=='(')
                        {
                            flag=0;
                            break;
                        }
                        st_temp.push(t_pari);
                    }
                    else
                    {
                        if(t_pari.first=='(')
                        {
                            int id=st_temp.top().second;
                            st_temp.pop();
                            temp[id]=')';
                        }else
                            st_temp.push(t_pari);
                    }
                }
            }
            if(st_temp.size()%2!=0)
                flag=0;
            else 
            {
                int tag=1;
                while(!st_temp.empty())
                {
                    int id=st_temp.top().second;
                    if(tag==1)
                    {
                        temp[id]='(';
                        tag*=-1;
                    }
                    else
                    {
                        temp[id]=')';
                        tag*=-1;
                    }
                    st_temp.pop();
                }
            }
        }
        if(flag)
            cout<<'('<<temp<<')'<<endl;
        else
            cout<<":("<<endl;
    }
    return 0;
}
