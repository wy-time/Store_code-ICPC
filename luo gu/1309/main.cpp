#include<iostream>
#include<algorithm>
typedef struct
{
    int id;
    int score;
    int power;
}s;
s man[210005];
s win[110005];
s lose[110005];
bool cmp(s a,s b);
using namespace std;
int  main()
{
    int n,q,r;
    cin>>n>>r>>q;
    int i;
    for(i=0;i<n*2;i++)
    {
        man[i].id=i+1;
        cin>>man[i].score;
    }
    for(i=0;i<n*2;i++)
    {
        cin>>man[i].power;
    }
    sort(man,man+2*n,cmp);
    int j=0;
    while(r--)
    {
        j=0;
        for(i=0;i<2*n;i+=2)
        {
            if(man[i].power>man[i+1].power)
            {
                man[i].score++;
                win[j]=man[i];
                lose[j]=man[i+1];
                j++;
            }else
            {
                man[i+1].score++;
                win[j]=man[i+1];
                lose[j]=man[i];
                j++;
            }
        }
        int k=0;
        i=j=0;
        while(i<n&&j<n)
        {
            if(cmp(win[i],lose[j]))
            {
                man[k]=win[i];
                i++;
                k++;

            }else
            {
                man[k]=lose[j];
                j++;
                k++;
            }
        }
        if(j<n)
        {
            for(;j<n;j++)
            {
                man[k]=lose[j];
                k++;
            }
        }else if(i<n)
        {
            for(;i<n;i++)
            {
                man[k]=win[i];
                k++;
            }
        }
    }
    cout<<man[q-1].id;
    return 0;
}
bool cmp(s a,s b)
{
    if(a.score==b.score)
        return a.id<b.id;
    else
        return a.score>b.score;
}
