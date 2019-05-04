#include <iostream>
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
struct st
{
    int num;
    int tim;
    int last;
    bool operator <(const st&x)const
    {
        if(x.num!=num)
        {
            return num>x.num;
        }else if(tim!=x.tim)
            return tim<x.tim;
        else 
            return last<x.last;
    }
    bool operator ==(const st&x)const
    {
        if(x.num==num&&x.tim==tim&&x.last==last)
        {
            return true;
        }else
            return false;
    }
};
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
    st a,b;
    cin>>a.num>>a.tim>>a.last;
    cin>>b.num>>b.tim>>b.last;
    if(a==b)
    {
        cout<<"God"<<endl;
    }else if(a<b)
    {
        cout<<1<<endl;
    }else 
        cout<<2<<endl;
    return 0;
}
