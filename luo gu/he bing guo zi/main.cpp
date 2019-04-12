#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long sum=0;
    priority_queue<long long,vector<long long>,greater<long long> >pq;
    while(n--)
    {
        long long t;
        cin>>t;
        pq.push(t);
    }
    int temp=0;
    while(pq.size()>1)
    {
        temp=0;
        temp+=pq.top();
        pq.pop();
        temp+=pq.top();
        pq.pop();
        pq.push(temp);
        sum+=temp;
    }
    cout<<sum<<endl;
    return 0;
}
