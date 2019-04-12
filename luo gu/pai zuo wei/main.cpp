#include<algorithm>
#include <iostream>
using namespace std;
typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
} s;
typedef struct
{
    int l;
    int cnt;
} s1;
s1 h[1005];
s1 lie[1005];
bool cmp (s1 a,s1 b);
int main()
{
    int m,n,k,l,d;
    s info;
    cin>>m>>n>>k>>l>>d;
    int i,j=0,t=0,s;
    for(i=0;i<d;i++)
    {
        cin>>info.x1>>info.y1>>info.x2>>info.y2;
        if(info.x1==info.x2)
        {
            int safe=0;
            for(s=0;s<=j;s++)
            {
                if(lie[s].l==min(info.y1,info.y2))
                {
                    lie[s].cnt++;
                    safe=1;
                }
            }
            if(!safe)
            {
                lie[j].l=min(info.y1,info.y2);
                lie[j].cnt++;
                j++;
            }
        }else
        {
            int safe=0;
            for(s=0;s<=t;s++)
            {
                if(h[s].l==min(info.x1,info.x2))
                {
                    h[s].cnt++;
                    safe=1;
                }
            }
            if(!safe)
            {
                h[t].l=min(info.x1,info.x2);
                h[t].cnt++;
                t++;
            }
        }
    }
    sort(lie,lie+j,cmp);
    sort(h,h+t,cmp);
    int r1[1005];
    int r2[1005];
    for(i=0;i<k;i++)
    {
        r1[i]=h[i].l;
    }
    for(i=0;i<l;i++)
    {
        r2[i]=lie[i].l;
    }
    sort(r1,r1+k);
    sort(r2,r2+l);
    for(i=0;i<k-1;i++)
    {
        cout<<r1[i]<<" ";
    }cout<<r1[i]<<endl;
    for(i=0;i<l-1;i++)
    {
        cout<<r2[i]<<" ";
    }
    cout<<r2[i]<<endl;
    return 0;
}
bool cmp (s1 a,s1 b)
{
    if(a.cnt==b.cnt)
        return a.l<b.l;
    else
        return a.cnt>b.cnt;
}
