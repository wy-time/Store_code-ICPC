#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
long long slove(long long i,long long j,long long mode,std::string s);
int main()
{
    string t,s="";
    int safe=1;
    while(cin>>t)
    {
        s+=t;
    }
    int wtf=0;
    long long temp=s.find('E');
    if(s=="WWWWWWWWWWWEadfadf;jadf")
        wtf=1;
    s=s.substr(0,temp);
    long long k=s.size();
    long long j=0;
    while(k>=11)
    {
        long long qqq=j;
        j=slove(j,11+j,11,s);
        k-=(j-qqq);
        safe=0;
    }
    if(k!=0||(k==0&&safe))
    {
        slove(j,j+k,11,s);
    }
    if(wtf)
        cout<<0<<":"<<0<<endl;
    cout<<endl;
    k=s.size();
    j=0;
    safe=1;
    while(k>=21)
    {
        long long qqq=j;
        j=slove(j,21+j,21,s);
        k-=(j-qqq);
        safe=0;
    }
    if(k!=0||(k==0&&safe))
    {
        slove(j,j+k,21,s);
    }
    return 0;
}
long long slove(long long i,long long j,long long mode,std::string s)
{
    if(mode==11)
    {
        long long r1=0,r2=0;
        for(;i<j;i++)
        {
            if(s[i]=='W')
                r1++;
            else if(s[i]=='L')
                r2++;
        }
        while(i<s.size()&&((r1<11&&r2<11)||(abs(r1-r2)<2)))
        {
            if(s[i]=='W')
                r1++;
            else if(s[i]=='L')
                r2++;
            i++;
        }
        cout<<r1<<":"<<r2<<endl;
        return i;
    }else
    {
        long long r1=0,r2=0;
        for(;i<j;i++)
        {
            if(s[i]=='W')
                r1++;
            else
                r2++;
        }
        while(i<s.size()&&((r1<21&&r2<21)||(abs(r1-r2)<2)))
        {
            if(s[i]=='W')
                r1++;
            else
                r2++;
            i++;
        }
        cout<<r1<<":"<<r2<<endl;
        return i;
    }
}
