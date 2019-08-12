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
int check1(string a,string b,string c,int &ans1,int &ans2,int &ans3)
{
    int lena=a.size();
    int lenc=c.size();
    int lenb=b.size();
    if(c.substr(0,lena).compare(a)==0)
    {
        int i;
        int flag=0;
        int cnt=0;
        wfor(i,lena,lenc)
        {
            if(c[i]!='0')
            {
                if(flag!=0)
                {
                    flag=0;
                    break;
                }
                if(c.substr(lena,lenb).compare(b)==0)
                {
                    flag=1;
                    i=lena+lenb-1;
                }
            }else if(flag==1)
                cnt++;
        }
        if(flag)
        {
            ans1=(lenc-lena);
            ans2=cnt;
            ans3=0;
            return 1;
        }
    }
    return 0;
}
string sum(string s1,string s2)
{
    if(s1.length()<s2.length())
    {
        string temp=s1;
        s1=s2;
        s2=temp;
    }
    int i,j;
    for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--)
    {
        s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //注意细节
        if(s1[i]-'0'>=10)
        {
            s1[i]=char((s1[i]-'0')%10+'0');
            if(i) s1[i-1]++;
            else s1='1'+s1;
        }
    }
    return s1;
}
int check2(string a,string b,string c,int &ans1,int &ans2,int &ans3)
{
    int lena=a.size();
    int lenc=c.size();
    int t_lenc=lenc;
    int lenb=b.size();
    ans1=lenb-1;
    ans3=0;
    ans2=0;
    int i;
    wfor(i,0,ans1)
        a+='0';
    lena=a.size();
    string temp=sum(a,b);
    int lent=temp.size();
    wfor(i,0,lent-lenc)
    {
        c+='0';
    }
    lenc=c.size();
    int flag=0;
    while(1)
    {
        if(c.substr(0,lent).compare(temp)==0)
        {
            flag=1;
            wfor(i,lent,t_lenc)
            {
                if(c[i]!='0')
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1)
            break;
        if(ans2>=lena-1)
            break;
        b+='0';
        ans2++;
        temp=sum(a,b);
        lent=temp.size();
        wfor(i,0,lent-lenc)
        {
            c+='0';
        }
        lenc=c.size();
    }
    if(flag==1)
    {
        ans3=temp.size()-t_lenc;
        return 1;
    }
    else
        return 0;
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
    int t;
    cin>>t;
    while(t--)
    {
        string a,b,c;
        cin>>a>>b>>c;
        int ans1,ans2,ans3;
        if(check1(a,b,c,ans1,ans2,ans3)==1)
            cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
        else if(check1(b,a,c,ans2,ans1,ans3)==1)
            cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
        else if(check2(a,b,c,ans1,ans2,ans3)==1)
            cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
        else if(check2(b,a,c,ans2,ans1,ans3)==1)
            cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
