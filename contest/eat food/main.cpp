#include <iostream>
#include<cstdio>
using namespace std;
typedef struct
{
    int cost;
    int vaule;
}st;
st food[30005];
struct rule
{
    bool operator()(const st&a,const st&b)
    {
        if(a.vaule!=b.vaule)
            return a.vaule>b.vaule
    }
};
int main()
{
    //std::ios::sync_with_stdio(false);
    register int t;
    scanf("%d",&t);
    register int n,m;
    while(t--)
    {
        scanf("%d %d",&n,&m);
        int cnt=0;
        while(n--)
        {
            cin>>food[cnt].cost>>food[cnt].vaule;
            cnt++;
        }
        sort(food,food+n,rule());
    }
    return 0;
}
