#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct
{
    string name;
    int cost;
}st;
st item[2005];
struct rule
{
    bool operator()(const st&a,const st&b)
    {
        if(a.cost!=b.cost)
            return a.cost>b.cost;
        else
            return a.name>b.name;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cnt=1;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        for(i=0;i<n;i++)
            cin>>item[i].name>>item[i].cost;
        sort(item,item+n,rule());
        int k;
        cin>>k;
        cout<<"#"<<cnt<<":"<<" "<<item[k-1].name<<" "<<item[k-1].cost<<endl;
        cnt++;
    }
    return 0;
}
