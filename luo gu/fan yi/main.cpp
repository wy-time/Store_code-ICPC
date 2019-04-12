#include <iostream>
#include<queue>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    queue <int> a;
    bool b[1005]={false};
    int cnt=0;
    int result=0;
    while(m--)
    {
        int t;
        cin>>t;
        if(!b[t])
        {
            b[t]=true;
            if(cnt<n)
            {
                a.push(t);
                cnt++;
                result++;
            }else
            {
                b[a.front()]=false;
                a.pop();
                a.push(t);
                result++;
            }
        }
    }
    cout<<result;
    return 0;
}
