#include <iostream>
using namespace std;
int main()
{
    //std::ios::sync_with_stdio(false);
    char a[20];
    int i=0;
    while(cin>>a[i])
        i++;
    int j=0;
    int cnt=0;
    bool q[20]={false};
    for(j=i-1;j>=0;j--)
    {
        cnt++;
        if(cnt%3==0)
            q[j-1]=true;
    }
    for(j=0;j<i;j++)
    {
        cout<<a[j];
        if(q[j])
            cout<<",";
    }
    return 0;
}
