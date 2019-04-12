#include <iostream>
using namespace std;
typedef struct
{
    int money;
    int value;
}s;
int r[100000005]={0};
int main()
{
    int n,m;
    cin>>n>>m;
    s info[30];

    int i=0;
    for(i=0;i<m;i++)
    {
        int t;
        cin>>info[i].money>>t;
        info[i].value=info[i].money*t;
    }
    int j=0;
    for(i=0;i<m;i++)
    {
        for(j=n-info[i].money;j>=0;j--)
        {
            r[j+info[i].money]=max(r[j]+info[i].value,r[j+info[i].money]);
        }
    }
    cout<<r[n];
    return 0;
}
