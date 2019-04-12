#include <iostream>
#include<map>
using namespace std;
int main()
{
    int n,m;
    pair<int,int> p;
    typedef multimap<int,int> ma;
    cin>>n>>m;
    ma map1;
    while(m--)
    {
        cin>>p.first>>p.second;
        map1.insert(p);
    }
    int sum=0;
    int money=0;
    ma::iterator it;
    for(it=map1.begin();sum<n;it++)
    {
        sum+=it->second;
        money+=it->first*(it->second);
    }
    if(sum>n)
    {
        it--;
        money-=it->first*(it->second);
        sum-=it->second;
        money+=(n-sum)*(it->first);
    }
    cout<<money<<endl;
    return 0;
}
