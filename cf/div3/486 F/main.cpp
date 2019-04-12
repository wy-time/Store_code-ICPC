#include <iostream>
#include <algorithm>
using namespace std;
struct RAIN
{
    long long beg;
    long long endx;
    bool operator<(const RAIN a) const
    {
        return this->beg<a.beg;
    }
};
struct Umbrella
{
    long long pos;
    long long weight;
    bool operator < (const Umbrella a) const
    {
        return this->pos<a.pos;
    }
};
Umbrella umbrella[2005];
RAIN rain[2005];
int main()
{
    std::ios::sync_with_stdio(false);
    int a,n,m;
    cin>>a>>n>>m;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>rain[i].beg>>rain[i].endx;
    }
    for(i=0;i<m;i++)
    {
        cin>>umbrella[i].pos>>umbrella[i].weight;
    }
    sort(rain,rain+n);
    sort(umbrella,umbrella+m);
    long long sum=0x7f7f7f7f7f;
    long long now=0x7f7f7f7f7f;
    long long nowto=rain[n-1].endx;
    long long res=0;
    for(i=n-1;i>=0;i--)
    {
        sum=0x7f7f7f7f7f;
        if(rain[i].beg<now)
        {
            nowto=min(rain[i].endx,nowto);
            for(int j=0;j<m;j++)
            {
                if(umbrella[j].pos<nowto)
                {
                    long long t=umbrella[j].weight*(nowto-umbrella[j].pos);
                    if(t<sum)
                    {
                        sum=t;
                        now=umbrella[j].pos;
                    }
                }else
                    break;
            }
            nowto=now;
            if(now>rain[i].beg&&sum!=0x7f7f7f7f7f)
                i++;
        }else
            continue;
        if(sum==0x7f7f7f7f7f)
        {
            cout<<-1<<endl;
            return 0;
        }else
        {
            res+=sum;
        }
    }
    cout<<res<<endl;
    return 0;
}
