#include <iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    char name[25];
    int finaltest;
    int classnum;
    char ganbu;
    char xibu;
    int lunwen;
    int id;
    int money;
} s;
s a[105];
bool cmp(s a,s b);
int main()
{
    int n;
    cin>>n;

    int i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i].name>>a[i].finaltest>>a[i].classnum>>a[i].ganbu>>a[i].xibu>>a[i].lunwen;
        a[i].id=i;
        if(a[i].finaltest>80)
        {
            if(a[i].lunwen>=1)
                a[i].money+=8000;
            if(a[i].finaltest>90)
            {
                a[i].money+=2000;
            }
            if(a[i].xibu=='Y'&&a[i].finaltest>85)
                a[i].money+=1000;
        }
        if(a[i].classnum>80)
        {
            if(a[i].ganbu=='Y')
                a[i].money+=850;
            if(a[i].finaltest>85)
                a[i].money+=4000;
        }
        sum+=a[i].money;
    }
    sort(a,a+n,cmp);
    cout<<a[0].name<<endl<<a[0].money<<endl;
    cout<<sum<<endl;
    return 0;
}
bool cmp(s a,s b)
{
    if(a.money!=b.money)
        return a.money>b.money;
    else
        return a.id<b.id;
}
