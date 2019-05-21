#include <iostream>
#include <map> 
#include <string> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    string s;
    map<char,char>ma;
    ma.insert(make_pair('A','V'));
    ma.insert(make_pair('B','W'));
    ma.insert(make_pair('C','X'));
    ma.insert(make_pair('D','Y'));
    ma.insert(make_pair('E','Z'));
    ma.insert(make_pair('F','A'));
    ma.insert(make_pair('G','B'));
    ma.insert(make_pair('H','C'));
    ma.insert(make_pair('I','D'));
    ma.insert(make_pair('J','E'));
    ma.insert(make_pair('K','F'));
    ma.insert(make_pair('L','G'));
    ma.insert(make_pair('M','H'));
    ma.insert(make_pair('N','I'));
    ma.insert(make_pair('O','J'));
    ma.insert(make_pair('P','K'));
    ma.insert(make_pair('Q','L'));
    ma.insert(make_pair('R','M'));
    ma.insert(make_pair('S','N'));
    ma.insert(make_pair('T','O'));
    ma.insert(make_pair('U','P'));
    ma.insert(make_pair('V','Q'));
    ma.insert(make_pair('W','R'));
    ma.insert(make_pair('X','S'));
    ma.insert(make_pair('Y','T'));
    ma.insert(make_pair('Z','U'));
    while(cin>>s)
    {
        if(s=="ENDOFINPUT")
            break;
        getline(cin,s);
        getline(cin,s);
        int len=s.size();
        int i;
        wfor(i,0,len)
        {
            if(ma.count(s[i])!=0)
                s[i]=ma[s[i]];
        }
        cout<<s<<endl;
        cin>>s;
    }
    return 0;
}
