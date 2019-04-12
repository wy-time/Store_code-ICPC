#include <iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
{
    char s[40];
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        itoa(a,s,b);
        strupr(s);
        cout<<s<<endl;;
    }
    return 0;
}
