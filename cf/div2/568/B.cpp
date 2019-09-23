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
    while(n--)
    {

        string s1,s2;
        cin>>s1>>s2;
        stack<char>st;
        while(!st.empty())
            st.pop();
        int i;
        wfor(i,0,s2.length())
            st.push(s2[i]);
        char last='0';
        int flag=1;
        mfor(i,s1.length()-1,0)
        {
            if(st.empty())
            {
                flag=0;
                break;
            }
            if(s1[i]==st.top())
            {
                st.pop();
                last=s1[i];
            }
            else if(st.top()==last)
            {
                st.pop();
                i++;
            }else
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            while(!st.empty())
            {
                if(st.top()!=last)
                {
                    flag=0;
                    break;
                }
                st.pop();
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
