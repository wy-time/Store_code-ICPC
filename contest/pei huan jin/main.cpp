#include <iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef struct
{
    int v;
    int m;
} st;
st soft[1005];
int isup[1005];
int main()
{
    std::ios::sync_with_stdio(false);
    int m,n;
    cin>>m>>n;
    int i;
    long long sum=0;
    for(i=0; i<n; i++)
    {
        cin>>soft[i].v;
        sum+=soft[i].v;
    }
    for(i=0; i<n; i++)
    {
        cin>>soft[i].m;
    }
    cout<<fixed<<setprecision(2)<<1.0*sum/m;
    return 0;
}
