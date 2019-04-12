#include <iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef struct
{
    int a;
    int x;
    int y;
} num;
bool cmp(num a,num b);
int main()
{
    num huasheng[405];
    int m,n;
    int time;
    cin>>m>>n>>time;
    int s[25][25];
    int i,j;
    int cnt=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>s[i][j];
            if(s[i][j]!=0)
            {
                huasheng[cnt].a=s[i][j];
                huasheng[cnt].x=i;
                huasheng[cnt].y=j;
                cnt++;
            }
        }
    }
    sort(huasheng,huasheng+cnt,cmp);
    int sum=0;
    time-=huasheng[0].x+2;
    if(time>huasheng[0].x+1)
    {
        sum+=huasheng[0].a;
        for(i=1;i<cnt;i++)
        {
            time-=abs(huasheng[i].x-huasheng[i-1].x)+abs(huasheng[i].y-huasheng[i-1].y)+1;
            if(time>huasheng[i].x)
                sum+=huasheng[i].a;
            else
                break;
        }

    }
    cout<<sum<<endl;
    return 0;
}
bool cmp(num a,num b)
{
    return a.a>b.a;
}
