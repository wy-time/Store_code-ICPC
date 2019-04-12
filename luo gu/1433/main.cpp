#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
typedef struct
{
    double x;
    double y;
}st;
void dfs(int step,int n,int last,double sum);
bool eat[20];
double r=0x3f3f3f3f;
st info[20];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    info[0].x=0,info[0].y=0;
    for(i=1;i<=n;i++)
    {
        cin>>info[i].x>>info[i].y;
    }
    dfs(1,n,0,0);
    cout<<fixed<<setprecision(2)<<r;
    return 0;
}
void dfs(int step,int n,int last,double sum)
{
    int i;
    if(step==n)
    {
        for(i=1;i<=n;i++)
        {
            if(!eat[i])
            {
                sum+=sqrt((info[i].x-info[last].x)*(info[i].x-info[last].x)+(info[i].y-info[last].y)*(info[i].y-info[last].y));
                r=min(r,sum);
            }
        }
    }else
    {
        for(i=1;i<=n;i++)
        {
            if(!eat[i])
            {
                double t=sqrt((info[i].x-info[last].x)*(info[i].x-info[last].x)+(info[i].y-info[last].y)*(info[i].y-info[last].y));
                sum+=t;
                if(sum>r)
                {
                    sum-=t;
                    continue;
                }else
                {
                    eat[i]=true;
                    dfs(step+1,n,i,sum);
                    sum-=t;
                    eat[i]=false;
                }
            }
        }
    }
}
