#include <iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int id;
    int f;
}s;
bool cmp(s a,s b);
int main()
{
    int n,m;
    s info[5005];
    cin>>n>>m;
    m*=1.5;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>info[i].id>>info[i].f;
    }
    sort(info,info+n,cmp);
    int cnt=0;
    int max1=info[m-1].f;
    for(i=m;i<n;i++)
    {
        if(max1==info[i].f)
            cnt++;
        else
            break;
    }
    cout<<info[m-1].f<<" "<<m+cnt<<endl;
    for(i=0;i<m+cnt;i++)
    {
        cout<<info[i].id<<" "<<info[i].f<<endl;
    }
    return 0;
}
bool cmp(s a,s b)
{
    if(a.f==b.f)
        return a.id<b.id;
    else
        return a.f>b.f;
}
