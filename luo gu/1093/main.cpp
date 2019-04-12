#include <iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int a;
    int b;
    int c;
    int id;
    int sum;
}s;
bool cmp (s a,s b);
s info[305];
int main()
{
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>info[i].a>>info[i].b>>info[i].c;
        info[i].id=i+1;
        info[i].sum=info[i].a+info[i].b+info[i].c;
    }
    sort(info,info+n,cmp);
    for(i=0;i<5;i++)
    {
        cout<<info[i].id<<" "<<info[i].sum<<endl;
    }
    return 0;
}
bool cmp (s a,s b)
{
    if(a.sum!=b.sum)
        return a.sum>b.sum;
    else if(a.a!=b.a)
        return a.a>b.a;
    else
        return a.id<b.id;
}
