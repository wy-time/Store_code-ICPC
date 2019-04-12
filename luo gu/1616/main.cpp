#include <iostream>
using namespace std;
typedef struct
{
    int times;
    int value;
}s;
int main()
{
    int t,m;
    cin>>t>>m;
    s info [10005]={0};
    int i=0;
    for(i=0;i<m;i++)
    {
        cin>>info[i].times>>info[i].value;
    }
    int j;
    long long result[100005]={0};
    for(i=0;i<m;i++)
    {
        for(j=0;j<=t-info[i].times;j++)
        {
            result[j+info[i].times]=max(result[j]+info[i].value,result[j+info[i].times]);
        }
    }
    cout<<result[t];
}
