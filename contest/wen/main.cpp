#include <iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef struct
{
    string name;
    int score;
}st1;
struct rule
{
    bool operator()(const st1&a,const st1&b)
    {
        if(a.score!=b.score)
            return a.score>b.score;
        else
        {
            return a.name<b.name;
        }
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    string s;
    st1 st [105];
    cin>>n>>m;
    cin>>s;
    int i;
    for(i=0;i<m;i++)
    {
        string ans;
        int tempscore=0;
        cin>>st[i].name>>ans;
        for(int j=0;j<n;j++)
        {
            if(ans[j]==s[j])
                tempscore++;
        }
        st[i].score=tempscore;
    }
    sort(st,st+m,rule());
    double score=1.0*st[0].score/n*100;
    cout<<st[0].name<<endl<<fixed<<setprecision(2)<<score;
    return 0;
}
