#include <iostream>
#include<cstdio>
using namespace std;
int list_right[100005];
int list_left[100005];
void link(int a,int b,int mode);
void list_erase(int a);
const int MAXN=100004;
int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int n;
    cin>>n;
    list_right[0]=1;
    list_left[1]=0;
    list_right[1]=MAXN;
    list_left[MAXN]=1;
    int cnt=2;
    while(--n)
    {
        int k,p;
        cin>>k>>p;
        if(p==1)
        {
            int t=list_right[k];
            link(k,cnt,1);
            link(t,cnt,0);
            cnt++;
        }
        else
        {
            int t=list_left[k];
            link(k,cnt,0);
            link(t,cnt,1);
            cnt++;
        }
    }
    int t=0;
    cin>>t;
    while(t--)
    {
        int e;
        cin>>e;
        if(list_right[e]!=0)
        {
            list_right[list_left[e]]=list_right[e];
            list_left[list_right[e]]=list_left[e];
            list_erase(e);
        }
    }
    int i=list_right[0];
    cout<<i;
    for(i=list_right[i];i!=MAXN;i=list_right[i])
    {
        cout<<" "<<i;
    }
    cout<<endl;
    return 0;
}
void link(int a,int b,int mode)
{
    if(mode==1)
    {
        list_left[b]=a;
        list_right[b]=list_right[a];
        list_right[a]=b;
    }else
    {
        list_right[b]=a;
        list_left[b]=list_left[a];
        list_left[a]=b;
    }
}
void list_erase(int a)
{
    list_right[a]=0;
}
