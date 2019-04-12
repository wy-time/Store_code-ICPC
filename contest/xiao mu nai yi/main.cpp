#include <iostream>
using namespace std;
typedef struct
{
    int a;
    int b,
    int len;
}st;
struct rule{
    bool operator()(const st&a,const st&b)
    {
        return a.len<b.len;
    }
};
st info[200005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=0;i<m;i++)
    {
        cin>>info[i].a>>info[i].b>>info[i].len;
    }
    sort(info,info+m,rule());
    return 0;
}
