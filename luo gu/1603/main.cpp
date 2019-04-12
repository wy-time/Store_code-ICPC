#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct
{
    int a;
    string temp;
}st;
bool cmp(st a, st b);
int main()
{
    string s;
    getline(cin,s);
    st a[10];
    string c[26]={"one","two","three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen","nineteen" ,"twenty","a", "both", "another" ,"first" ,"second" ,"third"};
    int t=0;
    int j=0;
    int cnt=0;
    int i;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(i=0;i<26&&cnt!=6;i++)
    {
        t=0;
        while((s.find(c[i],t))!=-1)
        {
            t=s.find(c[i],t);
            int tt;
            if(i>19)
            {
                if(s.substr(t,7)=="another"&&i==20)
                {
                    t++;
                    continue;
                }
                else if(s.substr(t-1,3)!=" a "&&i==20)
                {
                    t++;
                    continue;
                }else
                    tt=(i-20)%3+1;
            }else
            {
                tt=i+1;
            }
            tt*=tt;
            tt%=100;
            a[j].a=tt;
            cnt++;
            if(tt<10)
            {
                a[j].temp='0';
                a[j].temp+=(tt+'0');
            }else
            {
                int ttt=tt%10;
                tt/=10;
                a[j].temp=tt+'0';
                a[j].temp+=ttt+'0';
            }
            t++;
            j++;
        }
    }
    sort(a,a+cnt,cmp);
    string result;
    for(i=0;i<cnt;i++)
    {
        result+=a[i].temp;
    }
    int len =result.size();
    for(i=0;i<len;i++)
    {
        if(result[i]=='0')
        {
            result.erase(i,1);
            i--;
        }
        else
            break;
    }
    if(result.size()==0)
    {
        result='0';
    }
    cout<<result;
    return 0;
}
bool cmp(st a, st b)
{
    return a.a<b.a;
}
