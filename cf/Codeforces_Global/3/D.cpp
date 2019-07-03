#include <iostream>
#include <vector> 
#include <algorithm> 
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
const int maxn=3e5+5;
struct st
{
    int a;
    int b;
    int id;
    bool operator <(const st other)const
    {
        if(b!=other.b)
            return b>other.b;
        else
            return a>other.a;
    }
    bool operator >(const st other)const
    {
        if(b!=other.b)
            return b<other.b;
        else
            return a<other.a;
    }
};
st num1[maxn];
st num2[maxn];
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
    int cnt1=0;
    int cnt2=0;
    wfor(i,0,n)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
        {
            num1[cnt1].id=i+1;
            num1[cnt1].a=a;
            num1[cnt1++].b=b;
        }else
        {
            num2[cnt2].id=i+1;
            num2[cnt2].a=a;
            num2[cnt2++].b=b;
        }
    }
    sort(num2,num2+cnt2);
    sort(num1,num1+cnt1,greater<st>());
    vector<int>ans1;
    if(cnt2>0)
        ans1.push_back(num2[0].id);
    wfor(i,1,cnt2)
    {
        if(num2[i].a<num2[i-1].b)
            ans1.push_back(num2[i].id);
    }
    vector<int>ans2;
    if(cnt1>0)
        ans2.push_back(num1[0].id);
    wfor(i,1,cnt1)
    {
        if(num1[i].a>num1[i-1].b)
            ans2.push_back(num1[i].id);
    }
    if(ans1.size()>ans2.size())
    {
        cout<<ans1.size()<<endl;
        for(int k:ans1)
            cout<<k<<" ";
    }else
    {
        cout<<ans2.size()<<endl;
        for(int k:ans2)
            cout<<k<<" ";
    }
    return 0;
}
