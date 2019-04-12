#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef struct
{
    int l;
    int r;
    int sum;
}st;
bool cmp(st a,st b);
int slove(int *tempttt,int *tempr,st c,int* cnttt,st cc);
bool comper(int *max1,int * tempr,int cnt);
int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("testdata (2).in","r",stdin);
    int n;
    cin >>n;
    int a,b;
    cin>>a>>b;
    st man[1015];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>man[i].l>>man[i].r;
        man[i].sum=man[i].l*man[i].r;
    }
    sort(man,man+n,cmp);
    int tempr [5005]={0};
    int temptt [5005]={0};
    int t1=a/man[0].r;
    int t2=a;
    int cnt=0;
    int cntm=0;
    int cnttt=0;
    int max1[5005]={0};
    while(t2!=0)
    {
        temptt[cnttt]=t2%10;
        t2/=10;
        cnttt++;
    }
    while(t1!=0)
    {
        max1[cntm]=t1%10;
        t1/=10;
        cntm++;
    }
    for(i=0;i<cntm/2;i++)
    {
        int ttttt=max1[i];
        max1[i]=max1[cntm-1-i];
        max1[cntm-1-i]=ttttt;
    }
    for(i=1;i<n;i++)
    {
        cnt=slove(temptt,tempr,man[i-1],&cnttt,man[i]);
        /*int j=0;
        for(j=0;j<cnt;j++)
        {
            cout<<tempr[j];
        }
        cout<<endl;*/
        if(cntm<cnt)
        {
            int j;
            for(j=0;j<cnt;j++)
            {
                max1[j]=tempr[j];
            }
            cntm=cnt;
        }else if(cntm==cnt)
        {
            if(comper(max1,tempr,cnt))
            {
                int j;
                for(j=0;j<cnt;j++)
                {
                    max1[j]=tempr[j];
                }
            }
        }
    }
    for(i=0;i<cntm;i++)
    {
        cout<<max1[i];
    }
    return 0;
}
bool cmp(st a,st b)
{
    return a.sum<b.sum;
}
int slove(int *tempttt,int *tempr,st c,int* cnttt,st cc)
{
    int temp=c.l;
    int i;
    for(i=0;i<*cnttt;i++)
    {
        tempttt[i]*=temp;
    }
    for(i=0;i<*cnttt||tempttt[i]!=0;i++)
    {
        if(tempttt[i]>=10)
        {
            tempttt[i+1]+=tempttt[i]/10;
            tempttt[i]%=10;
        }
    }
    *cnttt=i;
    temp=cc.r;
    int cnt=0;
    i--;
    int temp1=0;
    int tempt=0;
    while(temp1==0)
    {
        tempt*=10;
        tempt+=tempttt[i];
        temp1=tempt/temp;
        if(temp1!=0)
        {
            tempr[cnt]=temp1;
            tempt%=temp;
            cnt++;
        }
        i--;
        if(i<0)
            break;
    }
    for(;i>=0;i--)
    {
        tempt*=10;
        tempt+=tempttt[i];
        tempr[cnt]=tempt/temp;
        tempt%=temp;
        cnt++;
    }
    return cnt;
}
bool comper(int *max1,int * tempr,int cnt)
{
    int i;
    for(i=0;i<cnt;i++)
    {
        if(max1[i]<tempr[i])
            return true;
    }
    return false;
}
