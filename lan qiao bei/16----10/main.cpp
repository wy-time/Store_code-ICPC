#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char c[10];
    cin>>c;
    char r[15];
    long long i=0;
    sscanf(c,"%x",&i);
    cout<<i;
    return 0;
}
