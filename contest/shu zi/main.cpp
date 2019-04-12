#include <iostream>
#include<cstring>
using namespace std;
void feng1(int a);
bool feng2(int a);
bool ttt[15];
int main()
{
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    int t;
    cin>>t;
    bool ans[1005];
    while(t--)
    {
        memset(ans,true,sizeof(ans));
        int a,b;
        int cnt=0;
        cin>>a>>b;
        memset(ttt,false,sizeof(ans));
        feng1(a),feng1(b);
        int i=1;
        for(i=1;i*a<=1000;i++)
        {
            ans[i*a]=false;
        }
        for(i=1;i*b<=1000;i++)
        {
            ans[i*b]=false;
        }
        for(i=1;i<=1000;i++)
        {
            if(ans[i])
            {
                if(feng2(i))
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
void feng1(int a)
{
    while(a!=0)
    {
        int t=a%10;
        ttt[t]=true;
        a/=10;
    }
}
bool feng2(int a)
{
    while(a!=0)
    {
        int t=a%10;
        if(ttt[t])
            return false;
        a/=10;
    }
    return true;
}
