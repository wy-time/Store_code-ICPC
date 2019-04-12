#include <iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int id;
    string s;
}stt;
bool cmp(stt a,stt b);
int main()
{
    int n;
    cin>>n;
    stt s[25];
    int i;
    for(i=0;i<n;i++)
    {
        s[i].id=i;
        cin>>s[i].s;
    }
    sort(s,s+n,cmp);
    cout<<s[0].id+1<<endl<<s[0].s<<endl;
    return 0;
}
bool cmp(stt a,stt b)
{
    if(a.s.size()==b.s.size())
        return a.s>b.s;
    else
        return a.s.size()>b.s.size();
}
