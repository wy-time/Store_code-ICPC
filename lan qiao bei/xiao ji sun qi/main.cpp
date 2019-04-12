#include <iostream>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
void cmd_clear(char *base);
void cmd_num(char *t);
void cmd_change(int true_radix,char*sbase,long long base);//进制转换
void cmd_equal(char*base);
long long cmd_math(long long base,string cmd, long long temp);//运算
long long chang10(char* sbase,int true_radix);
long long ksm(long long a,long long b);
int main()
{
    std::ios::sync_with_stdio(false);
    bool flag=false;//判断是否有base的值
    bool isstemp=false;//判断是否已经有temp
    bool ismathcmd=false;
    char sbase[70]={'\0'};
    char stemp[70]={'\0'};
    long long base=0,temp=0;
    int radix=10;
    string mathcmd;
    int n;
    cin>>n;
    while(n--)
    {
        if(isstemp&&ismathcmd)
        {
            base=cmd_math(base,mathcmd,temp);
            ismathcmd=false;
            isstemp=false;
        }
        string cmd;
        cin>>cmd;
        if(cmd=="NUM")
        {
            if(!flag)
            {
                cmd_num(sbase);
                flag=true;
                base=chang10(sbase,radix);
            }else
            {
                cmd_num(stemp);
                isstemp=true;
                temp=chang10(stemp,radix);
            }
        }else if(cmd=="CLEAR")
        {
            cmd_clear(sbase);
            cmd_clear(stemp);
            flag=false;
            isstemp=false;
        }else if(cmd=="EQUAL")
        {
            cmd_change(radix,sbase,base);
            cmd_equal(sbase);
        }else if(cmd=="CHANGE")
        {
            int t;
            cin>>t;
            radix=t;
        }
        else
        {
            mathcmd=cmd;
            ismathcmd=true;
        }
    }
    return 0;
}
long long chang10(char* sbase,int radix)//转换成十进制便于计算
{
    int len=strlen(sbase);
    int k=0;
    bool isd0=false;
    if(sbase[0]=='-')
    {
        isd0=true;
        k=1;
    }
    long long ret=0;
    int i;
    int j=0;
    for(i=len-1;i>=k;i--)
    {
        if(sbase[i]<='9')
        {
            long long st=sbase[i]-'0';
            long long po=ksm(radix,j);
            ret+=(st)*po;
        }else
        {
            long long st=sbase[i]-'A'+10;
            long long po=ksm(radix,j);
            ret+=(st)*po;
        }
        j++;
    }
    if(isd0)
        ret*=-1;
    return ret;
}
void cmd_clear(char*base)
{
    memset(base,0,70);
}
void cmd_num(char *t)// 输入数据
{
    char temp[70];
    cin>>temp;
    strcpy(t,temp);
}
void cmd_change(int true_radix,char*sbase,long long base)// 转换进制
{
    memset(sbase,0,70);
    bool isd0=false;
    if(base<0)
    {
        base*=-1;
        isd0=true;
    }
    int i=0;
    if(base==0)
        sbase[0]='0';
    while(base)
    {
        int temp=base%true_radix;
        if(temp>=10)
        {
            sbase[i]=temp-10+'A';
        }else
            sbase[i]=temp+'0';
        i++;
        base/=true_radix;
    }
    if(isd0)
        sbase[i]='-';
}
void cmd_equal(char*sbase)// 输出
{
    int len=strlen(sbase);
    int i;
    for(i=len-1;i>=0;i--)
    {
        cout<<sbase[i];
    }
    cout<<endl;
}
long long cmd_math(long long base,string cmd, long long temp)//运算
{
    if(cmd=="ADD")
    {
        base+=temp;
    }else if(cmd=="SUB")
    {
        base-=temp;
    }else if(cmd=="MUL")
    {
        base*=temp;
    }else if(cmd=="DIV")
    {
        base/=temp;
    }else
        base%=temp;
    return base;
}
long long ksm(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
}
