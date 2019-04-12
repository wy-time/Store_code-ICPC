#include <iostream>
using namespace std;
typedef struct
{
    int x;
    int y;
    int dx;
    int dy;
} w;
int main()
{
    w info[10005];
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>info[i].x>>info[i].y>>info[i].dx>>info[i].dy;
        info[i].dx=info[i].x+info[i].dx;
        info[i].dy=info[i].y+info[i].dy;
    }
    int x,y;
    cin>>x>>y;
    int safe=0;
    for(i=n-1;i>=0;i--)
    {
        if(x>=info[i].x&&x<=info[i].dx&&y>=info[i].y&&y<=info[i].dy)
        {
            safe=1;
            break;
        }
    }
    if(safe)
        cout<<i+1<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
