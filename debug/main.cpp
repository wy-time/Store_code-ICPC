#include <iostream>
#include <iomanip> 
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
const int maxn=2005;
struct node
{
    ll len;
    int s;
    int l;
    int r;
};
node tree[maxn<<2];
struct Line
{
    int l;
    int r;
    int high;
    int flag;
    bool operator <(const Line other)const
    {
        return high<other.high;
    }
};
struct Point
{
    double x1;
    double y1;
    double x2;
    double y2;
};
Point point[maxn];
vector <double>num;
Line line[maxn<<2];
void push_up(int id)
{
    if(tree[id].s)
        tree[id].len=num[tree[id].r-1]-num[tree[id].l-1];
    else
        tree[id].len=tree[id<<1].len+tree[id<<1|1].len;
}
void build (int l,int r,int id)
{
    tree[id].len=0;
    tree[id].s=0;
    tree[id].l=l;
    tree[id].r=r;
    if(l+1==r)
    {
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,id<<1);
    build(mid,r,id<<1|1);
}
void update(int id,int L,int R,int number)
{
    if(tree[id].l>=L&&tree[id].r<=R)
    {
        tree[id].s+=number;
        push_up(id);
        return ;
    }
    int mid=(tree[id].l+tree[id].r)>>1;
    if(mid>L)
        update(id<<1,L,R,number);
    if(mid<R)
        update(id<<1|1,L,R,number);
    push_up(id);
}
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
    int casecnt=0;
    while(cin>>n&&n)
    {
        num.clear();
        casecnt++;
        int i;
        wfor(i,0,n)
        {
            cin>>point[i].x1>>point[i].y1>>point[i].x2>>point[i].y2;
            num.push_back(point[i].x1);
            num.push_back(point[i].x2);
            num.push_back(point[i].y1);
            num.push_back(point[i].y2);
        }
        sort(num.begin(),num.end());
        auto it=unique(num.begin(),num.end());
        int len=it-num.begin();
        int cnt=0;
        wfor(i,0,n)
        {
            int x1,y1,x2,y2;
            x1=lower_bound(num.begin(),it,point[i].x1)-num.begin()+1;
            x2=lower_bound(num.begin(),it,point[i].x2)-num.begin()+1;
            y1=lower_bound(num.begin(),it,point[i].y1)-num.begin()+1;
            y2=lower_bound(num.begin(),it,point[i].y2)-num.begin()+1;
            line[cnt].l=x1;
            line[cnt].r=x2;
            line[cnt].flag=1;
            line[cnt++].high=y1;
            line[cnt].l=x1;
            line[cnt].r=x2;
            line[cnt].flag=-1;
            line[cnt++].high=y2;
        }
        sort(line,line+cnt);
        build(1,len,1);
        update(1,line[0].l,line[0].r,line[0].flag);
        int last=line[0].high;
        double ans=0;
        wfor(i,1,cnt)
        {
            ans+=1.0*tree[1].len*(num[line[i].high-1]-num[last-1]);
            update(1,line[i].l,line[i].r,line[i].flag);
            last=line[i].high;
        }
        cout<<"Test case #"<<casecnt<<endl;
        cout<<"Total explored area: ";
        cout<<fixed<<setprecision(2)<<ans<<endl;
        cout<<endl;
    }
    return 0;
}
