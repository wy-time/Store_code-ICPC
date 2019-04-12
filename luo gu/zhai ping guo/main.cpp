#include <iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int h;
    int y;
}j;
bool cmp(j a,j b);
int main()
{
    int n,s;
    cin>>n>>s;
    int a,b;
    cin>>a>>b;
    j info[5000];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>info[i].h>>info[i].y;
    }
    sort(info,info+i,cmp);
    int cnt=0;
    for(i=0;i<n;i++)
    {
        if(s<info[i].y)
            break;
        else
        {
            if(a+b>=info[i].h)
            {
                cnt++;
                s-=info[i].y;
            }
        }
    }
    cout<<cnt;
    return 0;
}
bool cmp(j a,j b)
{
    return a.y<b.y;
}
