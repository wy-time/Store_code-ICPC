#include <iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set <int> s;
    while(n--)
    {
        int t;
        cin>>t;
        s.insert(t);
    }
    cout<<s.size()<<endl;
    set <int>::iterator p,en;
    en=s.end();
    en--;
    for(p=s.begin();p!=en;p++)
    {
        cout<<*p<<" ";
    }
    cout<<*p<<endl;
    return 0;
}
