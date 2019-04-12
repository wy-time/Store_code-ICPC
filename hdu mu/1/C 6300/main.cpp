#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef struct
{
    ll x;
    ll y;
    int idx;
}st;
st point[20005];
struct rule
{
    bool operator () (const st &a, const st &b)
    {
        return a.x<b.x;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        for(i=0;i<3*n;i++)
        {
            cin>>point[i].x>>point[i].y;
            point[i].idx=i+1;
        }
        sort(point,point+(3*n),rule());
        for(i=0;i<3*n;i+=3)
        {
            cout<<point[i].idx<<" "<<point[i+1].idx<<" "<<point[i+2].idx<<endl;
        }
    }
    return 0;
}
