#include <iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    char name [25];
    char sex [25];
    int age;
    int score;

}st;
bool cmp(st a,st b);
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    st info[1005];
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>info[i].name>>info[i].sex>>info[i].age>>info[i].score;
    }
    stable_sort(info,info+n,cmp);
    for(i=0;i<n;i++)
    {
        cout<<info[i].name<<" "<<info[i].sex<<" "<<info[i].age<<" "<<info[i].score<<endl;
    }
    return 0;
}
bool cmp(st a,st b)
{
    return a.score<b.score;
}
