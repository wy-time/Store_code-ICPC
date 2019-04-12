#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    double deg=10;
    int maxn=60*60*12;
    double h=1.0/120.0;
    double m=0.1;
    double s=6;
    double hm=m-h;
    double hs=s-h;
    double ms=s-m;
    double thm=360.0/hm;
    double ths=360.0/hs;
    double tms=360.0/ms;
    while(cin>>deg&&deg!=-1)
    {
        double res=0;
        double a[3]={deg/hm,deg/hs,deg/ms};
        double b[3]={(360-deg)/hm,(360-deg)/hs,(360-deg)/ms};
        double i,j,k;
        for(i=0;i<=1.0*maxn;i+=thm)
        {
            for(j=0;j<=1.0*maxn;j+=ths)
            {
                if(a[1]+j>b[0]+i)
                    break;
                if(a[0]+i>b[1]+j)
                    continue;
                for(k=0;k<=1.0*maxn;k+=tms)
                {
                    double p=max(max(a[0]+i,a[1]+j),a[2]+k);
                    double q=min(min(b[0]+i,b[1]+j),b[2]+k);
                    if(p>maxn||q>maxn)
                        break;
                    if(q>p)
                        res+=q-p;
                }
            }
        }
        cout<<fixed<<setprecision(3)<<100*res/maxn<<endl;
    }
    return 0;
}
