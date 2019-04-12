#include <iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef struct
{
    char name[15];
    double score;
}st;
st ans[200005];
int noip[200005];
struct rule
{
    bool operator()(const st &a,const st &b)
    {
        if(a.score-b.score>1)
            return true;
        else if(a.score-b.score<-1)
            return false;
        else
        {
            if(strcmp(a.name,b.name)<0)
                return true;
            else
                return false;
        }
    }
};
int d1[200005];int d2[200005];int d3[200005];int d4[200005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        int i;
        int maxn=-1,max1=-1,max2=-1,max3=-1,max4=-1;
        for(i=0;i<n;i++)
        {
            cin>>ans[i].name>>noip[i]>>d1[i]>>d2[i]>>d3[i]>>d4[i];
            maxn=max(noip[i],maxn);
            max1=max(max1,d1[i]);
            max2=max(max2,d2[i]);
            max3=max(max3,d3[i]);
            max4=max(max4,d4[i]);
        }
        //cout<<maxn<<" "<<max1<<" "<<" "<<max2<<" "<<max3<<" "<<max4<<" "<<endl;
        for(i=0;i<n;i++)
        {
            ans[i].score=(1.0*noip[i]*1.0*600/maxn)*0.25+(1.0*d1[i]*300/max1+1.0*d2[i]*300/max2)*0.25+(1.0*d3[i]*300/max3+1.0*d4[i]*300/max4)*0.5;
            ans[i].score*=1.0*100000;
        }
        sort(ans,ans+n,rule());
        for(i=0;i<n;i++)
        {
            cout<<ans[i].name<<" "<<fixed<<setprecision(5)<<ans[i].score/100000<<endl;;
        }
    }
    return 0;
}
