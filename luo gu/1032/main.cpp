#include <iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
typedef struct
{
    char a1[25];
    char b1[25];
}st;
typedef struct
{
    string a1;
    int step;
}st2;
st change[10];
int slove(int n,string a,string b);
int main()
{
    std::ios::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    int i=0;
    while(cin>>change[i].a1>>change[i].b1)
        i++;
    int r=slove(i,a,b);
    if(r==-1)
        cout<<"NO ANSWER!";
    else
        cout<<r;
    return 0;
}
int slove(int n,string a,string b)
{
    queue<st2>qu;
    st2 ans;
    ans.a1=a;
    ans.step=0;
    qu.push(ans);
    while(!qu.empty())
    {
        int i;
        string aa=qu.front().a1;
        int cnt=qu.front().step;
        qu.pop();
        string temp;
        for(i=0;i<n;i++)
        {
            int t=0;
            while((t=aa.find(change[i].a1,t))!=string::npos)
            {
                temp=aa;
                int lena=strlen(change[i].a1);
                int lenb=strlen(change[i].b1);
                temp.erase(t,lena);
                temp.insert(t,change[i].b1);
                t+=lenb;
                ans.a1=temp;
                ans.step=cnt+1;
                if(ans.a1==b)
                    return ans.step;
                if(ans.step<10)
                    qu.push(ans);
            }
        }
    }
    return -1;
}
