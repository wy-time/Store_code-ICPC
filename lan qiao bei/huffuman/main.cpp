#include <iostream>
#include<queue>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    priority_queue<int,vector<int>,greater<int> >qu;
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        qu.push(temp);
    }
    int r=0;
    while(qu.size()>1)
    {
        int t1=qu.top();
        qu.pop();
        int t2=qu.top();
        qu.pop();
        r+=t1+t2;
        qu.push(t1+t2);
    }
    cout<<r;
    return 0;
}
