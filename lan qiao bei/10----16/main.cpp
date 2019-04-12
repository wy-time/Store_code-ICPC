#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char s[20];
    itoa(n,s,16);
    strupr(s);
    cout<<s;
    return 0;
}
