#include <iostream>
#include<map>
#include<string>
using namespace std;
typedef map<string,int>map1;
map1 ma;
int main()
{
    std::ios::sync_with_stdio(false);
    int n=1;
    while(cin>>n&&n)
    {
        int i;
        ma.clear();
        for(i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            if(ma.count(temp)==0)
            {
                ma.insert(make_pair(temp,1));
            }else
            {
                ma[temp]++;
            }
        }
        map1::iterator it;
        string res;
        int maxx=0;
        for(it=ma.begin();it!=ma.end();it++)
        {
            if((it->second)>maxx)
            {
                maxx=it->second;
                res=it->first;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
