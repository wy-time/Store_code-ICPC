#include <iostream>
#include <algorithm>
#include <cmath>
#include<iomanip>
using namespace std;
struct POINT
{
    double x;
    double y;
}ax[100005];
struct rule1
{
    bool operator ()(const POINT &a,const POINT &b)
    {
        return a.x<b.x;
    }
};
struct rule2
{
    bool operator ()(const int &a,const int &b)
    {
        return ax[a].y<ax[b].y;
    }
};
int a[100005];
double cal(POINT a,POINT b);//计算两点距离
double chaifeng(int l,int r);//分治函数
int main()
{
    std::ios::sync_with_stdio(false);
    int n=1;
    while(cin>>n&&n)
    {
        int i=0;
        for(i=0;i<n;i++)
        {
            cin>>ax[i].x>>ax[i].y;
        }
        sort(ax,ax+n,rule1());
        double res=chaifeng(0,n-1);
        cout<<fixed<<setprecision(2)<<res/2.0<<endl;
    }
    return 0;
}
double chaifeng(int l,int r)
{
    double res=0;
    if(l==r-1)
    {
        return cal(ax[l],ax[r]);
    }else if(l==r-2)
    {
        return min(cal(ax[l],ax[l+1]),min(cal(ax[l],ax[r]),cal(ax[l+1],ax[r])));
    }else
    {
        int mid=(l+r)>>1;
        res=min(chaifeng(l,mid),chaifeng(mid+1,r));
        int i;
        double L=ax[mid].x;
        int cnt=0;
        for(i=l;i<mid;i++)
        {
            if(ax[i].x>L-res)
                a[cnt++]=i;
        }
        for(i=mid;i<=r;i++)
        {
            if(ax[i].x<L+res)
                a[cnt++]=i;
        }
        sort(a,a+cnt,rule2());
        for(i=0;i<cnt;i++)
        {
            for(int j=i+1;j<cnt&&j<i+7;j++)
            {
                if(ax[a[j]].y-ax[a[i]].y>=res)
                    break;
                res=min(res,cal(ax[a[i]],ax[a[j]]));
            }
        }
    }
    return res;
}
double cal(POINT a ,POINT b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
/*#include <iostream>
#include <algorithm>
#include <cmath>
#include<vector>
#include<iomanip>
using namespace std;
struct POINT
{
    double x;
    double y;
    POINT(double a,double b)
    {
        x=a;
        y=b;
    }
};
struct rule1
{
    bool operator ()(const POINT &a,const POINT &b)
    {
        return a.x<b.x;
    }
};
struct rule2
{
    bool operator ()(const POINT &a,const POINT &b)
    {
        return a.y<b.y;
    }
};
vector <POINT> x;
vector <POINT> y;
const double INF=0x7f7f7f7f;
double chaifeng(vector <POINT> x,vector <POINT> y);//分治函数
double hebing(vector <POINT> yl,vector <POINT> yr,double dist,double L);//合并两边
double cal(POINT a,POINT b);//计算两点距离
int main()
{
    std::ios::sync_with_stdio(false);
    int n=1;
    while(cin>>n&&n)
    {
        x.clear();
        y.clear();
        int i;
        double t1,t2;
        for(i=0;i<n;i++)
        {
            cin>>t1>>t2;
            x.push_back(POINT(t1,t2));
            y.push_back(x[i]);
        }
        sort(x.begin(),x.end(),rule1());
        sort(y.begin(),y.end(),rule2());
        double res=chaifeng(x,y);
        cout<<fixed<<setprecision(2)<<res/2.0<<endl;
    }
    return 0;
}
double cal(POINT a ,POINT b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double chaifeng(vector <POINT> x,vector <POINT> y)
{
    double dist=INF;
    int len=x.size();
    if(len==1)
        return dist;
    else if(len==2)
        return  cal(x[0],x[1]);
    else
    {
        int mid=len/2;
        int i,j;
        double L=x[mid].x;
        vector<POINT>xr,xl;
        vector<POINT>yr,yl;
        xr.clear();xl.clear();yr.clear();yl.clear();
        for(i=0;i<mid;i++)
            xl.push_back(x[i]);
        for(j=mid;j<len;j++)
            xr.push_back(x[j]);
        int len2=y.size();
        for(i=0;i<len2;i++)
        {
            if(y[i].x<L)
                yl.push_back(y[i]);
            else
                yr.push_back(y[i]);
        }
        double dist1=chaifeng(xl,yl);
        double dist2=chaifeng(xr,yr);
        dist=min(dist1,dist2);
        dist=hebing(yl,yr,dist,L);
    }
    return dist;
}
double hebing(vector <POINT> yl,vector <POINT> yr,double dist,double L)
{
    vector<POINT>yL1;
    vector<POINT>yR1;
    int i=0;
    yL1.clear();
    yR1.clear();
    int lenl=yl.size();
    int lenr=yr.size();
    for(i=0;i<lenl;i++)
    {
        if(yl[i].x>L-dist)
            yL1.push_back(yl[i]);
    }
    for(i=0;i<lenr;i++)
    {
        if(yr[i].x<L+dist)
            yR1.push_back(yr[i]);
    }
    int len1=yL1.size();
    int len2=yR1.size();
    for(i=0;i<len1;i++)
    {
        int j=0;
        while(yL1[i].y>yR1[j].y&&j<len2)
            j++;
        for(int k=max(0,j-3);k<min(j+3,len2);k++)
        {
            if(cal(yR1.at(k),yL1.at(i))<dist)
                dist=cal(yR1.at(k),yL1.at(i));
        }
    }
    return dist;
}*/
