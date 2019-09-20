#include <iostream>
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
const int maxn=1e5+5;
string add(string a,string b)
{
    int lena=a.length();
    int lenb=b.length();
    int add=0;
    string ans="";
    int i=lena-1,j=lenb-1;
    while(i>=0&&j>=0)
    {
        int temp=a[i]+b[j]-'0'-'0';
        temp+=add;
        add=temp/10;
        temp%=10;
        ans=(char)(temp+'0')+ans;
        i--,j--;
    }
    if(i>=0)
    {
        while(i>=0)
        {
            int temp=a[i]-'0'+add;
            add=temp/10;
            temp%=10;
            ans=(char)(temp+'0')+ans;
            i--;
        }
        if(add>0)
            ans=(char)(add+'0')+ans;
    }else
    {
        while(j>=0)
        {
            int temp=b[j]-'0'+add;
            add=temp/10;
            temp%=10;
            ans=(char)(temp+'0')+ans;
            j--;
        }
        if(add>0)
            ans=(char)(add+'0')+ans;
    }
    return ans;
}
bool comp(string s1,string s2)
{
    if(s1.size()>s2.size())
        return true;
    else if(s1.size()<s2.size())
        return false;
    else
        return s1>s2;
}
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    string temp1=s.substr(0,n/2);
    string temp2=s.substr(n/2);
    string ans="";
    if(temp2[0]!='0')
    {
        if(n%2==0)
        {
            ans=add(temp1,temp2);
        }else
        {
            string tans1=add(temp1,temp2);
            if(temp2[1]!='0')
            {
                temp1=temp1+temp2[0];
                temp2=temp2.substr(1);
                string tans2=add(temp1,temp2);
                if(comp(tans1,tans2))
                    ans=tans2;
                else
                    ans=tans1;
            }else
                ans=tans1;
        }
    }else
    {
        int i;
        wfor(i,0,temp2.length())
        {
            if(temp2[i]=='0')
                temp1=temp1+temp2[i];
            else
                break;
        }
        temp2=temp2.substr(i);
        string tans1="",tans2="";
        if(temp2.size()!=0)
        {
            tans1=add(temp1,temp2);
        }
        temp1=s.substr(0,n/2);
        temp2=s.substr(n/2);
        mfor(i,temp1.length()-1,0)
        {
            if(temp1[i]=='0')
            {
                temp2=temp1[i]+temp2;
            }else
            {
                temp2=(char)temp1[i]+temp2;
                if(i!=0)
                    temp1=temp1.substr(0,i);
                else
                    temp1="";
                break;
            }
        }
        if(temp1.size()!=0)
        {
            tans2=add(temp1,temp2);
        }
        if(tans1.size()==0)
            ans=tans2;
        else if(tans2.size()==0)
            ans=tans1;
        else
        {
            if(comp(tans1,tans2))
                ans=tans2;
            else
                ans=tans1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
