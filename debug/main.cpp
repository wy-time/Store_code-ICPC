#include <iostream>
#include <map> 
#include <cmath> 
#include <set> 
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
const int maxn=1005;
const double eps=1e-8;
bool equa(double a,double b)
{
    if(fabs(a-b)<eps)
        return true;
    else
        return false;
}
struct st
{
    int x;
    int y;
};
struct Line
{
    double k;
    double b;
    Line (){}
    Line (double a,double a2)
    {
        k=a;
        b=a2;
    }
    bool operator <(const Line & other)const
    {
        if(!equa(k,other.k))
            return k<other.k;
        else
            return b<other.b;
    }
};
st point[maxn];
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
    wfor(i,0,n)
    {
        cin>>point[i].x>>point[i].y;
    }
    set<Line>st;
    map<double,ll>ma;
    ll cnt=0;
    wfor(i,0,n)
    {
        int j;
        wfor(j,i+1,n)
        {
            double k;
            double b;
            if(point[i].x-point[j].x==0)
            {
                k=0.000001;
                b=point[i].x;
            }else
            {
                k=((point[i].y-point[j].y)/(point[i].x-point[j].x));
                b=1.0*point[i].y-k*point[i].x;
            }
            auto it=st.insert(Line(k,b));
            if(it.second)
            {
                cnt++;
                if(ma.count(k)==0)
                    ma.insert(make_pair(k,1));
                else
                    ma[k]++;
            }
        }
    }
    ll ans=0;
    for(auto it:st)
    {
        ans+=cnt-ma[it.k];
    }
    cout<<ans/2<<endl;
    return 0;
}
