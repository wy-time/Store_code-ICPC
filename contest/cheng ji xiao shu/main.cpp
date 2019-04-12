#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef struct
{
    string name;
    int intt;
    string xiao;
    string xiao1;
} st;
struct rule
{
    bool operator()(const st&a,const st&b)
    {
        if(a.intt!=b.intt)
            return a.intt>b.intt;
        else
        {
            if(a.xiao1.compare(b.xiao1)!=0)
                return a.xiao1>b.xiao1;
            else
            {
                return a.name<b.name;
            }
        }
    }
};
st info[300005];
int main()
{
    std::ios::sync_with_stdio(false);
    register int n;
    cin>>n;
    register int i;
    string temp;
    for(i=0; i<n; i++)
    {
        cin>>info[i].name>>temp;
        info[i].intt=temp[0]-'0';
        temp.size()>2?info[i].xiao=temp.substr(2):info[i].xiao="";
        string a=info[i].xiao;
        int lena=a.size();
        lena--;
        while(lena>=0&&a[lena]=='0')
        {
            a.erase(lena,1);
            lena--;
        }
        info[i].xiao1=a;
    }
    sort(info,info+n,rule());
    for(i=0; i<n; i++)
    {
        cout<<info[i].name<<" "<<info[i].intt<<"."<<info[i].xiao<<endl;
    }
    return 0;
}
/*inline bool cmp1(st a,st b)
{
    if(a.intt!=b.intt)
        return a.intt>b.intt;
    else
    {
        int lena=a.xiao.size();
        int lenb=b.xiao.size();
        lena--;
        lenb--;
        while(lena>=0&&a.xiao[lena]=='0')
        {
            a.xiao.erase(lena,1);
            lena--;
        }
        while(lenb>=0&&b.xiao[lenb]=='0')
        {
            b.xiao.erase(lenb,1);
            lenb--;
        }
        if(a.xiao.compare(b.xiao)!=0)
            return a.xiao>b.xiao;
        else
        {
            return a.name<b.name;
        }
    }
}*/
