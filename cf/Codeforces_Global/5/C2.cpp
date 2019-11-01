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
const int maxn=5e5+5;
struct st
{
    int x,y,z;
    int id;
};
struct rule
{
    bool operator ()(const st &a,const st&b)
    {
        if(a.x!=b.x)
            return a.x<b.x;
        else if(a.y!=b.y)
            return a.y<b.y;
        else
            return a.z<b.z;
    }
};
struct rule2
{
    bool operator ()(const st &a,const st&b)
    {
        if(a.y!=b.y)
            return a.y<b.y;
        else if(a.z!=b.z)
            return a.z<b.z;
        else
            return a.x<b.x;
    }
};
struct rule3
{
    bool operator ()(const st &a,const st&b)
    {
        if(a.x!=b.x)
            return a.x<b.x;
        else if(a.z!=b.z)
            return a.z<b.z;
        else
            return a.y<b.y;
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
        cin>>point[i].x>>point[i].y>>point[i].z;
        point[i].id=i+1;
    }
    sort(point,point+n,rule());
    vector<st>rest;
    wfor(i,1,n)
    {
        if(point[i].x==point[i-1].x&&point[i].y==point[i-1].y)
        {
            cout<<point[i-1].id<<" "<<point[i].id<<endl;
            i++;
            if(i==n-1)
                rest.push_back(point[i]);
        }else
        {
            rest.push_back(point[i-1]);
            if(i==n-1)
                rest.push_back(point[i]);
        }
    }
    sort(rest.begin(),rest.end(),rule2());
    int len=rest.size();
    vector<st>rest2;
    wfor(i,1,len)
    {
        if(rest[i].y==rest[i-1].y&&rest[i].z==rest[i-1].z)
        {
            cout<<rest[i-1].id<<" "<<rest[i].id<<endl;
            i++;
            if(i==len-1)
                rest2.push_back(rest[i]);
        }else
        {
            rest2.push_back(rest[i-1]);
            if(i==len-1)
                rest2.push_back(rest[i]);
        }
    }
    rest.clear();
    sort(rest2.begin(),rest2.end(),rule3());
    len=rest2.size();
    wfor(i,1,len)
    {
        if(rest2[i].x==rest2[i-1].x&&rest2[i].z==rest2[i-1].z)
        {
            cout<<rest2[i-1].id<<" "<<rest2[i].id<<endl;
            i++;
            if(i==len-1)
                rest.push_back(rest2[i]);
        }else
        {
            rest.push_back(rest2[i-1]);
            if(i==len-1)
                rest.push_back(rest2[i]);
        }
    }
    sort(rest.begin(),rest.end(),rule());
    rest2.clear();
    len=rest.size();
    wfor(i,1,len)
    {
        if(rest[i].x==rest[i-1].x||rest[i].y==rest[i-1].y||rest[i].z==rest[i-1].z)
        {
            cout<<rest[i-1].id<<" "<<rest[i].id<<endl;
            i++;
            if(i==len-1)
                rest2.push_back(rest[i]);
        }else
        {
            rest2.push_back(rest[i-1]);
            if(i==len-1)
                rest2.push_back(rest[i]);
        }
    }
    sort(rest2.begin(),rest2.end(),rule());
    len=rest2.size();
    wfor(i,0,len)
    {
        cout<<rest2[i].id<<" "<<rest2[i+1].id<<endl;
        i++;
    }
    return 0;
}
