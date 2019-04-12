#include <iostream>
#include <map>
using namespace std;
typedef map <long long,long long>map1;
int main()
{
    std::ios::sync_with_stdio(false);
    long long n;
    cin>>n;
    long long i;
    map1 ma;
    long long sum=0;
    for(i=0;i<n;i++)
    {
        long long temp;
        cin>>temp;
        if(ma.count(temp)==0)
        {
            ma.insert(make_pair(temp,1));
        }else
        {
            ma[temp]++;
        }
        sum+=temp;
    }
    int a,b;
    for(i=0;i<n-1;i++)
        cin>>a>>b;
    map1::iterator it;
    it=ma.begin();
    long long res=sum-(it->first)*(it->second)+(n-it->second)*(it->first);
    it++;
    for(;it!=ma.end();it++)
    {
        res=min(res,sum-(it->first)*(it->second)+(n-it->second)*(it->first));
    }
    cout<<res<<endl;
    return 0;
}
